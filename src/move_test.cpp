#include <vector>
#include <math.h> // for sqrt() and other functions

// for to_string()
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#include "move_path.cpp"

// for odeint
/*
#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>
*/

#define PI 3.14159265

using namespace std;

string to_string(double x);

string to_string(double x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

string to_string(int x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

char get_pd(int x, int y) {
	char pd[100] = { 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u' }; 

	int gc_ind = (y * 10) + x;

	return pd[gc_ind];
}

char get_pd(int i) {
	char pd[100] = { 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u' }; 

	return pd[i];
}

char get_pd_opp(int i) {
	// opposite prefered direction
	char pd[100] = { 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd' }; 

	return pd[i];
}

int get_pd_angle(int x, int y) {
	double pd[100] = { .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, .5*PI, 0, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI, PI, 1.5*PI }; 

	int gc_ind = (y * 10) + x;

	return pd[gc_ind];
}

void print_firing(int layer_x, int layer_y, double *gc_firing, double (*gc_weights)[100], int t, G* g) {
	int layer_size = layer_x * layer_y;
	int gc_ind = 0; // grid cell index
	double temp;

	//if (t != 0) {
	if (true) {
		cout << "time: " << t << " sec\n";

		for (int i = (layer_x - 1); i >= 0; i--) {
			for (int j = 0; j < layer_y; j++) {
				gc_ind = (i * layer_x) + j;

				printf("[%f]",gc_firing[gc_ind]);

				if (g->pos[0] == j && g->pos[1] == i) {
					printf("(%c)",g->last_dir);
				}

				printf("\t");
			}
			cout << "\n";
		}
	}
}

double get_distance(int x1, int y1, int x2, int y2, char pd) {
	// d = sqrt((e_x - i_x - o_x)^2+(e_y - i_y - o_y)^2)
	int x2_x1 = (x2 - x1);
	int y2_y1 = (y2 - y1);
	int half_point = 10 / 2; // layer length divided by 2

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
		x2_x1 = (10 - abs(x2_x1));
	}
	if (abs(y2_y1) >= half_point) {
		y2_y1 = (10 - abs(y2_y1));
	}

	double d = sqrt(pow(x2_x1,2)+pow(y2_y1,2));

	return d;
}

void init_firing(double *gc_firing, int layer_size) {
	// initialize firing

	double w1 = 2.000001;
	double w2 = 1.748563;
 	double w3 = 1.473271;
 	double scaling_factor = 0.5;
 	w1 = w1 * scaling_factor;
 	w2 = w2 * scaling_factor;
 	w3 = w3 * scaling_factor;
	for (int i = 0; i < layer_size; i++) {
		gc_firing[i] = 0.3;
	}
	gc_firing[11] = w1;
	gc_firing[1] = w2;
	gc_firing[10] = w2;
	gc_firing[12] = w2;
	gc_firing[21] = w2;
	gc_firing[0] = w3;
	gc_firing[20] = w3;
	gc_firing[2] = w3;
	gc_firing[22] = w3;
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
	g->last_dir=direction;
}

double get_mex_hat(G* g, double d) {
	double mex_hat;
	g->s_1 = 2.5; // sigma_1
	g->s_2 = g->s_1;
	g->s_3 = g->s_1;
	g->m = 1.0; // magnitude variable for mex hat
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;
	double m = g->m;
	double scaling_factor = 2.35; // used to retain equalibrium over movements
	double multiple_synapse = 0.1; // reduces each connection due to multiple connections

	mex_hat = scaling_factor * multiple_synapse * ((2/(sqrt(pow((3*s_1*PI),(1/4)))))*(1-pow((m*d)/s_2,2))*(exp(pow(-1*(m*d),2)/pow(2*s_3,2))));

	return mex_hat;
}

void ext_input(char direction, double speed, double *gc_firing, double (*gc_weights)[100], G* g) {
	/*
		Apply external input

		https://en.wikipedia.org/wiki/Ricker_wavelet
		mexican hat: (2/(sqrt(pow((3*sigma*PI),(1/4))))*(pow(1-pow(x/sigma,2),(exp(pow(-1*x,2)/pow(2*sigma,2))))))
	*/	

	double new_gc_firing[100];
	for (int i = 0; i < 100; i++) { // initialize array
		new_gc_firing[i] = 0.000001;
	}
	double new_gc_weights[100][100];
	for (int i = 0; i < 100; i++) { // initialize array
		for (int j = 0; j < 100; j++) {
			new_gc_weights[i][j] = 0.0;
		}
	}
	int pd_i, gc_i;
	double d, new_firing, new_weight, pd_angle, weight_sum, pd_fac;
	double mex_hat; // mexican hat
	double weight_sym; // weight symetrical
	double weight_asym; // weight asymetrical
	double vel_in = 0.0; // velocity input
	g->speed = 2.35;//.405; // ext input speed level
	g->y_inter = -0.3; // y intercept
	g->scale = 0.34; // multiple synaptic connections scaling factor
	/*g->s_1 = 2.5; // sigma_1
	g->s_2 = g->s_1;
	g->s_3 = g->s_1;
	g->m = 1.0; // magnitude variable for mex hat*/
	g->run_time = 13;

	speed = g->speed;
	vel_in = speed;
	double y_inter = g->y_inter; // y intercept
	double scale = g->scale; // multiple synaptic connections scaling factor
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;
	double m = g->m;

	set_pos(g, direction);

	for (int pdy = 0; pdy < 10; pdy++) {
		for (int pdx = 0; pdx < 10; pdx++) {
			pd_angle = get_pd_angle(pdx, pdy);
			pd_i = (pdy * 10) + pdx;
			for (int gcy = 0; gcy < 10; gcy++) {
				//if (pdy == 1) {cout << "\n" << pdy << " " << pdx << " " << gcy << "\n";}
				for (int gcx = 0; gcx < 10; gcx++) {	
					weight_sym = 0;
					weight_asym = 0;		
					gc_i = (gcy * 10) + gcx;

					d = get_distance(pdx, pdy, gcx, gcy, direction);

					if (d < 3.0) { // distance threshold for only local connections
						mex_hat = get_mex_hat(g, d);

						new_weight = g->a_sym * mex_hat * 0.1;

						//if (new_weight < 0) {new_weight = 0;} // avoid negative

						weight_sym = new_weight;

						if (direction == get_pd(pdx, pdy)) {
							//new_weight = gc_firing[pd_i] * mex_hat * 0.1;
							//new_weight = g->a_asym * mex_hat * 0.1;
							//new_weight = gc_firing[pd_i] * mex_hat * 0.1 * speed;
							new_weight = gc_firing[pd_i] * mex_hat;// * 0.1 * speed;

							//if (new_weight < 0) {new_weight = 0;} // avoid negative

							weight_asym = new_weight;
							//cout << weight_asym << " ";
						}

						//new_gc_firing[gc_i] = new_gc_firing[gc_i] + new_firing;
						//if (pd_i == 13) {
							//new_gc_weights[pd_i][gc_i] = weight_sym + weight_asym;
							new_gc_weights[pd_i][gc_i] = weight_asym;
						//}
					}
					//if (pdy == 1) {cout << "[" << pd_i << "," << gc_i << "|" << new_gc_weights[pd_i][gc_i] << "] ";}
				}
			}
			//cout << pdx << " " << pdy << "\n";
		}
	}

	/*
		tau is used for reducing the firing over time
	*/
	for (int gc_i = 0; gc_i < 100; gc_i++) {
		weight_sum = 0;
		if (gc_i == 21) {
			//cout << "\n" << gc_i << "\n";
		}				
		for (int pd_i = 0; pd_i < 100; pd_i++) {
			weight_sum = weight_sum + new_gc_weights[pd_i][gc_i];
			if (gc_i == 21) {
				//if (pd_i % 10 == 0) {cout << "\n";}
				//cout << "[" << pd_i << "|" << weight_sum << "] ";
			}
		}
		//printf("%d: %f ",i,weight_sum);

		if (get_pd(gc_i) == direction) {
			pd_fac = 2;
		}
		else if(get_pd_opp(gc_i) == direction) {
			pd_fac = .5;
		}
		else {
			pd_fac = 1.0;
		}

		//new_firing = g->tau * ((gc_firing[gc_i] * weight_sum) + vel_in);
		//new_firing = g->tau * ((gc_firing[gc_i] * weight_sum));
		new_firing = weight_sum;
		//new_firing = gc_firing[gc_i];
		//new_firing = g->tau * ((gc_firing[gc_i] * weight_sum) + (pd_fac * vel_in));

		//if (new_firing < 0) {new_firing = 0.000001;}

		gc_firing[gc_i] = new_firing;
	}
}

int main() {
	const static int layer_x = 10;
	const static int layer_y = 10;
	const static int layer_size = layer_x * layer_y;
	double gc_firing[layer_size];
	double gc_weights[layer_size][layer_size];
	struct G g;
	
	init_firing(gc_firing, layer_size);

	for (int t = 0; t <= g.run_time; t++) {
		move_path(gc_firing, gc_weights, t, &g);

		print_firing(layer_x, layer_y, gc_firing, gc_weights, t, &g);
	}

	return 0;
}