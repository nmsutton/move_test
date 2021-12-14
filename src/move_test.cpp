/*
	Author: Nate Sutton 2021

	References:
	https://en.wikipedia.org/wiki/Gompertz_function
*/

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

	//if (t != 0) {
	if (true) {
		cout << "\ntime: " << t << " sec\n";

		for (int i = (layer_y - 1); i >= 0; i--) {
			for (int j = 0; j < layer_x; j++) {
				gc_ind = (i * layer_x) + j;

				printf("|");
				if (gc_firing[gc_ind] >= 0) {
					//printf("+");
					printf(" ");
				}
				//printf("%.2f %c",abs(gc_firing[gc_ind]),get_pd(i,j));
				printf("%.2f",gc_firing[gc_ind]);

				if (g->pos[0] == j && g->pos[1] == i && g->print_move) {
					printf("(%c)",g->last_dir);
				}
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

	double mex_hat = y_inter + scale * (2/(sqrt(3*s_1*pow(PI,1/4))))*(1-pow((m*d)/s_2,2))*(exp(-1*(pow(m*d,2)/(2*pow(s_3,2)))));

	return mex_hat;
}

void init_firing(double *gc_firing, G *g) {
	// initialize firing

	int i;
	double mex_hat, d;
	double init_f = 4.0; // initial firing amount
	double w1 = 2.000001;
	double w2 = 1.748563;
 	double w3 = 1.473271;
 	double scaling_factor = 0.5;
	double weights_bumps[g->layer_size];
	for (int i = 0; i < g->layer_size; i++) {
		weights_bumps[g->layer_size] = 0.0;
	}
	int num_bumps = 4;
	double bump_pos[num_bumps][2] = {{1,1},{1,11},{11,1},{11,11}};
	//double bump_pos[num_bumps][2] = {{1,1}};
	//double bump_pos[num_bumps][2] = {{4,4},{4,14},{14,4},{14,14}};
	g->y_inter = g->y_inter_init; // y intercept
	g->s_1 = g->s_1_init; // sigma_1. Note: specific value used for equalibrium of weights over time.
	g->s_2 = g->s_2_init;
	g->s_3 = g->s_3_init;
	g->m = g->m_init;
	g->scale = g->scale_init;
	g->run_time = g->run_time_init;

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

	if (g->pos[0] >= g->layer_x) {
		g->pos[0] = 0;
	}
	else if (g->pos[0] < 0) {
		g->pos[0] = (g->layer_x - 1);
	}
	if (g->pos[1] >= g->layer_y) {
		g->pos[1] = 0;
	}
	else if (g->pos[1] < 0) {
		g->pos[1] = (g->layer_y - 1);
	}

	if (g->print_move == true && (direction == 'u' || direction == 'd' || direction == 'l' || direction == 'r')) {
		cout << " move: " << direction;
	}

	g->last_dir=direction;
}

void set_weights(G *g) {
	/*
		Set weights

		https://en.wikipedia.org/wiki/Ricker_wavelet (mexican hat)
	*/

	int pd_i, gc_i;
	double d, mex_hat;
	g->y_inter = g->y_inter_syn;
	g->s_1 = g->s_1_syn;
	g->s_2 = g->s_2_syn;
	g->s_3 = g->s_3_syn;
	g->m = g->m_syn;
	g->scale = g->scale_syn;
	g->run_time = g->run_time_syn;
	double w_scale_f = 0.16; // multiple weight scaling factor to avoid weights increasing too much

	// init weights
	for (int i = 0; i < g->layer_size; i++) {
		for (int j = 0; j < g->layer_size; j++) {
			g->weights[i][j] = 0.0;
		}
	}

	for (int pdy = 0; pdy < g->layer_y; pdy++) {
		for (int pdx = 0; pdx < g->layer_x; pdx++) {
			for (int gcy = 0; gcy < g->layer_y; gcy++) {
				for (int gcx = 0; gcx < g->layer_x; gcx++) {			
					pd_i = (pdy * g->layer_x) + pdx;
					gc_i = (gcy * g->layer_x) + gcx;

					d = get_distance(pdx, pdy, gcx, gcy, get_pd(pd_i, g), g);
					if (d < g->dist_thresh) { 
						mex_hat = get_mex_hat(d, g);
					}

					g->weights[pd_i][gc_i] = mex_hat;
				}
			}
		}
	}
}

double get_noise(G *g) {
	int rand_max = g->noise_rand_max;
	double scale = g->noise_scale;

	double rand_val = rand() % rand_max; // rand number up to rand_max
	rand_val = rand_val * scale; // scale to desired size
	rand_val = rand_val - (scale/2); // include negative values

	return rand_val;
}

void ext_input(char direction, double speed, double *gc_firing, G* g) {
	/*
		Apply external input
	*/	

	double new_firing, new_weight, weight_sum, pd_fac, mex_hat;
	double pdx, pdy, gcx, gcy, d; // for distance
	int pd_i, gc_i;
	double new_firing_group[g->layer_size];
	for (int i = 0; i < g->layer_size; i++) {
		new_firing_group[i] = 0.00001;
	}
	g->tau = g->tau_syn;
	g->y_inter = g->y_inter_syn;
	g->scale = g->scale_syn;
	g->s_1 = g->s_1_syn;
	g->s_2 = g->s_2_syn;
	g->s_3 = g->s_3_syn;
	g->m = g->m_syn;

	set_pos(g, direction);

	if (g->print_move) {cout << "\n";}

	/*
		apply ext input first
	*/
	for (int gc_i = 0; gc_i < g->layer_size; gc_i++) {
		if (get_pd(gc_i, g) == direction) {
			pd_fac = 1.0;//2;
			//cout << "test";
		}
		else if(get_pd_opp(gc_i, g) == direction) {
			pd_fac = 0.0;//-1.0;//.5;
			//cout << "test";
		}
		else {
			pd_fac = 0.0;//1.0;
		}

		gc_firing[gc_i] = gc_firing[gc_i] + (pd_fac * g->speed_syn);
	}

	for (int pdy = 0; pdy < g->layer_y; pdy++) {
		for (int pdx = 0; pdx < g->layer_x; pdx++) {
			if (direction == get_pd(pdx, pdy) || direction == 'n') {
				for (int gcy = 0; gcy < g->layer_y; gcy++) {
					for (int gcx = 0; gcx < g->layer_x; gcx++) {			
						pd_i = (pdy * g->layer_x) + pdx;						
						gc_i = (gcy * g->layer_x) + gcx;

						d = get_distance(pdx, pdy, gcx, gcy, direction, g);

						if (d < g->dist_thresh) { 

							mex_hat = get_mex_hat(d, g);

							new_firing = gc_firing[pd_i] * mex_hat;

							new_firing_group[gc_i] = new_firing_group[gc_i] + new_firing;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < g->layer_size; i++) {
		gc_firing[i] = new_firing_group[i] * g->tau;
		// asymmetric sigmoid function for value bounding
		//gc_firing[i] = g->asig_yi + g->asig_scale * ((exp(1)/g->asig_a) * exp(-exp(g->asig_b-g->asig_c*gc_firing[i])));
		if (gc_firing[i] < 1.2) {
			gc_firing[i] = 0;
		}
		else {
			gc_firing[i] = g->asig_yi + g->asig_scale * ((exp(1)/g->asig_a) * exp(-exp(g->asig_b-g->asig_c*gc_firing[i])));
		}
		if (g->noise_active == true) {
			// add random noise for realism
			gc_firing[i] = gc_firing[i] + get_noise(g);
		}
	}
}

int main() {
	struct G g;	
	double gc_firing[g.layer_size];
	
	init_firing(gc_firing, &g);

	set_weights(&g);

	print_firing(gc_firing, 0, &g);

	for (int t = 1; t <= g.run_time; t++) {
		move_path(gc_firing, t, &g);

		print_firing(gc_firing, t, &g);

		//write_firing(gc_firing, t, &g);		
	}

	return 0;
}