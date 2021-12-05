#include <vector>
#include <math.h> // for sqrt() and other functions

// for to_string()
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include "move_path.cpp"

// for file out
#include <iostream>
#include <fstream>
#include <string> // for filename

#define PI 3.14159265

using namespace std;

string to_string(double x);

string to_string(double x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

string int_to_string(int x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

char get_pd(int x, int y) {
	char pd;

	if (y % 2 == 0) {
		if (x % 2 == 0) {
			pd = 'd';
		}
		else {
			pd = 'r';
		}
	}
	else {
		if (x % 2 == 0) {
			pd = 'l';
		}
		else {
			pd = 'u';
		}		
	}

	return pd;
}

char get_pd(int i, G *g) {	
	char pd;
	int x = i % g->layer_x;
	int y = i / g->layer_x;

	if (y % 2 == 0) {
		if (x % 2 == 0) {
			pd = 'd';
		}
		else {
			pd = 'r';
		}
	}
	else {
		if (x % 2 == 0) {
			pd = 'l';
		}
		else {
			pd = 'u';
		}		
	}

	return pd;
}

char get_pd_opp(int i, G *g) {	
	char pd;
	int x = i % g->layer_x;
	int y = i / g->layer_x;

	if (y % 2 == 0) {
		if (x % 2 == 0) {
			pd = 'u';
		}
		else {
			pd = 'l';
		}
	}
	else {
		if (x % 2 == 0) {
			pd = 'r';
		}
		else {
			pd = 'd';
		}		
	}

	return pd;
}

void write_firing(double *gc_firing, int t, G* g) {
	ofstream output_file;
	string filename = "output/firing_t" + int_to_string(t) + ".csv";
	output_file.open(filename);

	int layer_x = g->layer_x;
	int layer_y = g->layer_y;
	int layer_size = g->layer_size;
	int gc_ind = 0; // grid cell index
	double temp;

	if (t != 0) {
		for (int i = (layer_x - 1); i >= 0; i--) {
			for (int j = 0; j < layer_y; j++) {
				gc_ind = (i * layer_x) + j;

				output_file << gc_firing[gc_ind];

				if (j != (layer_y -1)) {
					output_file << ",";
				}
			}
			if (i != 0) {
				output_file << "\n";
			}
		}
	}

  output_file.close();
}

void print_firing(double *gc_firing, int t, G* g) {
	int layer_x = g->layer_x;
	int layer_y = g->layer_y;
	int layer_size = g->layer_size;
	int gc_ind = 0; // grid cell index
	double temp;

	if (t != 0) {
	//if (true) {
		cout << "time: " << t << " sec\n";

		for (int i = (layer_x - 1); i >= 0; i--) {
			for (int j = 0; j < layer_y; j++) {
				gc_ind = (i * layer_x) + j;

				printf("|");
				if (gc_firing[gc_ind] >= 0) {
					//printf("+");
				}
				printf("%.2f %c",abs(gc_firing[gc_ind]),get_pd(i,j));

				/*if (g->pos[0] == j && g->pos[1] == i) {
					printf("(%c)",g->last_dir);
				}*/

				//printf(" ");
			}
			cout << "\n";
		}
	}
}

double get_distance(int x1, int y1, int x2, int y2, char pd, G *g) {
	// d = sqrt((e_x - i_x - o_x)^2+(e_y - i_y - o_y)^2)
	int x2_x1 = (x2 - x1);
	int y2_y1 = (y2 - y1);
	int half_point = g->layer_x / 2; // layer length divided by 2

	// preferred direction bias
	if (pd == 'u') {
		y2_y1 = y2_y1 - 1;
	}
	if (pd == 'd') {
		y2_y1 = y2_y1 + 1;
	}
	if (pd == 'r') {
		x2_x1 = x2_x1 - 1;
	}
	if (pd == 'l') {
		x2_x1 = x2_x1 + 1;
	}	

	// torus wrap around
	if (abs(x2_x1) >= half_point) {
		// distance wraps half way around
		x2_x1 = (g->layer_x - abs(x2_x1));
	}
	if (abs(y2_y1) >= half_point) {
		y2_y1 = (g->layer_y - abs(y2_y1));
	}

	double d = sqrt(pow(x2_x1,2)+pow(y2_y1,2));

	return d;
}

double get_mex_hat(double d, G *g) {
	double y_inter = g->y_inter;
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;
	double m = g->m;
	double scale = g->scale;

	double mex_hat = scale * (y_inter + (2/(sqrt(3*s_1*pow(PI,1/4))))*(1-pow((m*d)/s_2,2))*(exp(-1*(m*pow(d,2)/(2*pow(s_3,2))))));

	return mex_hat;
}

void init_firing(double *gc_firing, G *g) {
	// initialize firing

	int i;
	double mex_hat, d;
	double init_f = 1.0; // initial firing amount
	double w1 = 2.000001;
	double w2 = 1.748563;
 	double w3 = 1.473271;
 	double scaling_factor = 0.5;
	double weights_bumps[g->layer_size];
	for (int i = 0; i < g->layer_size; i++) {
		weights_bumps[g->layer_size] = 0.0;
	}
	int num_bumps = 4;
	double bump_pos[num_bumps][2] = {{5,5},{5,15},{15,5},{15,15}};
	g->y_inter = 1.0; // y intercept
	g->s_1 = 2*.1; // sigma_1. Note: specific value used for equalibrium of weights over time.
	g->s_2 = 2;
	g->s_3 = 2;
	g->m=1;
	g->scale=0.25;
	g->run_time = 1;

	// find weights for the starting bumps
	for (int y = 0; y < g->layer_y; y++) {
		for (int x = 0; x < g->layer_x; x++) {
			for (int b = 0; b < num_bumps; b++) {
				i = (y * g->layer_x) + x;

				d = get_distance(x, y, bump_pos[b][0], bump_pos[b][1], 'n', g);

				if (d < g->dist_thresh) {
					mex_hat = get_mex_hat(d, g);

					weights_bumps[i] = weights_bumps[i] + mex_hat;
				}
			}
		}
	}

	for (int i = 0; i < g->layer_size; i++) {
		gc_firing[i] = init_f * weights_bumps[i];
	}

	/*gc_firing[11] = w1;
	gc_firing[1] = w2;
	gc_firing[10] = w2;
	gc_firing[12] = w2;
	gc_firing[21] = w2;
	gc_firing[0] = w3;
	gc_firing[20] = w3;
	gc_firing[2] = w3;
	gc_firing[22] = w3;*/
}

void set_pos(G* g, char direction) {
	if (direction == 'u') {
		g->pos[1]++; 
	}
	else if (direction == 'd') {
		g->pos[1]--; 
	}
	else if (direction == 'r') {
		g->pos[0]++; 
	}
	else if (direction == 'l') {
		g->pos[0]--; 
	}

	if (direction == 'u' || direction == 'd' || direction == 'l' || direction == 'r') {
		cout << " move: " << direction;
	}

	g->last_dir=direction;
}

void ext_input(char direction, double speed, double *gc_firing, G* g) {
	/*
		Apply external input

		https://en.wikipedia.org/wiki/Ricker_wavelet
		mexican hat: (2/(sqrt(pow((3*sigma*PI),(1/4))))*(pow(1-pow(x/sigma,2),(exp(pow(-1*x,2)/pow(2*sigma,2))))))
	*/	

	double new_gc_firing[g->layer_size];
	for (int i = 0; i < g->layer_size; i++) { // initialize array
		new_gc_firing[i] = 0.000001;
	}
	int pd_i, gc_i;
	double d, new_firing, new_weight, weight_sum, pd_fac;
	double mex_hat; // mexican hat
	double weight_sym; // weight symetrical
	double weight_asym; // weight asymetrical
	double vel_in = 0.0; // velocity input
	g->speed = 0.3;
	g->y_inter = 1.0; // y intercept
	g->s_1 = 2*.1; // sigma_1. Note: specific value used for equalibrium of weights over time.
	g->s_2 = 2;
	g->s_3 = 2;
	g->m=1;
	g->scale=0.25;
	g->run_time = 5;

	// clear weights
	for (int i = 0; i < g->layer_size; i++) {
		for (int j = 0; j < g->layer_size; j++) {
			g->weights[i][j] = 0.0;
		}
	}

	vel_in = g->speed;
	double y_inter = g->y_inter;
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;
	double m = g->m;
	double scale = g->scale;

	double w_scale_f = 0.16; // multiple weight scaling factor to avoid weights increasing too much

	set_pos(g, direction);

	cout << "\n";
	for (int pdy = 0; pdy < g->layer_y; pdy++) {
		for (int pdx = 0; pdx < g->layer_x; pdx++) {
			//if (direction == get_pd(pdx, pdy) && pdx == 1 && pdy == 1) {
			//if (direction == get_pd(pdx, pdy)) {
			if (true) {
			//get_pd(pdx, pdy);
			//if (pdx == 4 && pdy == 5) {
				pd_i = (pdy * g->layer_x) + pdx;
				for (int gcy = 0; gcy < g->layer_y; gcy++) {
					for (int gcx = 0; gcx < g->layer_x; gcx++) {			
						gc_i = (gcy * g->layer_x) + gcx;

						// find weight_sym
						d = get_distance(pdx, pdy, gcx, gcy, 'n', g); // no pd bias
						if (d < g->dist_thresh) { 
							mex_hat = get_mex_hat(d, g);							
							mex_hat = mex_hat * g->a_sym; // symmetric amplitude factor
							//printf("%f + (2/(sqrt(3*%f*pow(PI,1/4))))*(1-pow((%f*%f)/%f,2))*(exp(-1*(%f*pow(%f,2)/(2*pow(%f,2)))))\n",y_inter,s_1,m,d,s_2,m,d,s_3);
							weight_sym = mex_hat;
						}

						// find weight_asym
						d = get_distance(pdx, pdy, gcx, gcy, get_pd_opp(pd_i, g), g); // with pd bias
						if (d < g->dist_thresh) { 
							mex_hat = get_mex_hat(d, g);
							if (mex_hat < 0) {
								mex_hat = 0.00001; // avoid negative
							}
							mex_hat = mex_hat * g->a_asym; // asymmetric amplitude factor; for adjustment to inhibitory					
							weight_asym = gc_firing[gc_i] * mex_hat;
						}

						g->weights[pd_i][gc_i] = (weight_sym + weight_asym) * w_scale_f;
						//g->weights[pd_i][gc_i] = weight_asym * w_scale_f;
						//g->weights[pd_i][gc_i] = weight_sym * w_scale_f;
					}
				}
			}
		}
	}

	/*
		tau is used for reducing the firing over time
	*/
	for (int gc_i = 0; gc_i < g->layer_size; gc_i++) {
		weight_sum = 0;
		for (int pd_i = 0; pd_i < g->layer_size; pd_i++) {
			weight_sum = weight_sum + (gc_firing[gc_i] * g->weights[pd_i][gc_i]);
			//weight_sum = weight_sum + g->weights[pd_i][gc_i];

			if (false && pd_i == 104) {
				cout << "[";
				if (g->weights[pd_i][gc_i] >= 0) {
					cout << "+";
				}
				printf("%.2f]",g->weights[pd_i][gc_i]);
				//printf("%d]",pd_i);
				if ((gc_i+1) % g->layer_x == 0 && gc_i != 0) {
					cout << "\n";
				}
			}
		}
		//printf("%d: %f ",gc_i,weight_sum);

		if (get_pd(gc_i, g) == direction) {
			pd_fac = 1.0;//2;
			//cout << "test";
		}
		else if(get_pd_opp(gc_i, g) == direction) {
			pd_fac = -1.0;//.5;
			//cout << "test";
		}
		else {
			pd_fac = 0.0;//1.0;
		}

		//new_firing = g->tau * weight_sum + vel_in;
		new_firing = weight_sum;
		//new_firing = gc_firing[gc_i];
		//new_firing = g->tau * weight_sum + (pd_fac * vel_in);
		//new_firing = (pd_fac * vel_in);

		//if (new_firing < 0) {new_firing = 0.000001;}

		gc_firing[gc_i] = new_firing;
	}
}

int main() {
	struct G g;	
	double gc_firing[g.layer_size];
	
	init_firing(gc_firing, &g);

	for (int t = 0; t <= g.run_time; t++) {
		move_path(gc_firing, t, &g);

		print_firing(gc_firing, t, &g);

		//write_firing(gc_firing, t, &g);		
	}

	return 0;
}