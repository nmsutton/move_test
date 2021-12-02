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
	char pd[100] = { 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u' }; 

	int gc_ind = (y * 10) + x;

	return pd[gc_ind];
}

void write_firing(int layer_x, int layer_y, double *gc_firing, int t, G* g) {
	ofstream output_file;
	string filename = "output/firing_t" + int_to_string(t) + ".csv";
	output_file.open(filename);

	int layer_size = layer_x * layer_y;
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

void print_firing(int layer_x, int layer_y, double *gc_firing, int t, G* g) {
	int layer_size = layer_x * layer_y;
	int gc_ind = 0; // grid cell index
	double temp;

	if (t != 0) {
	//if (true) {
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

void ext_input(char direction, double speed, double *gc_firing, G* g) {
	/*
		Apply external input

		https://en.wikipedia.org/wiki/Ricker_wavelet
		mexican hat: (2/(sqrt(pow((3*sigma*PI),(1/4))))*(pow(1-pow(x/sigma,2),(exp(pow(-1*x,2)/pow(2*sigma,2))))))
	*/	

	double new_gc_firing[100];
	for (int i = 0; i < 100; i++) { // initialize array
		new_gc_firing[i] = 0.000001;
	}
	int pd_i, gc_i;
	double d, new_firing;
	double mex_hat; // mexican hat
	g->y_inter = -0.5; // y intercept
	g->s_1 = 1.8*.404318655; // sigma_1. Note: specific value used for equalibrium of weights over time.
	g->s_2 = 1.8; //g->s_1;
	g->s_3 = 1.8; //g->s_1;
	g->run_time = 52;

	double y_inter = g->y_inter;
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;

	set_pos(g, direction);

	for (int pdy = 0; pdy < 10; pdy++) {
		for (int pdx = 0; pdx < 10; pdx++) {
			//if (direction == get_pd(pdx, pdy) && pdx == 1 && pdy == 1) {
			if (direction == get_pd(pdx, pdy)) {
				pd_i = (pdy * 10) + pdx;
				for (int gcy = 0; gcy < 10; gcy++) {
					for (int gcx = 0; gcx < 10; gcx++) {			
						gc_i = (gcy * 10) + gcx;

						d = get_distance(pdx, pdy, gcx, gcy, direction);

						if (d < g->dist_thresh) { 

							mex_hat = (2/(sqrt(3*s_1*pow(PI,1/4))))*(1-pow(d/s_2,2))*(exp(pow(-1*d,2)/pow(2*s_3,2)));

							new_firing = y_inter + gc_firing[pd_i] * mex_hat;

							if (new_firing < 0) {
								new_firing = 0.00001; // avoid negative
							}

							new_gc_firing[gc_i] = new_gc_firing[gc_i] + new_firing;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		gc_firing[i] = new_gc_firing[i];
	}
}

int main() {
	int layer_x = 10;
	int layer_y = 10;
	int layer_size = layer_x * layer_y;
	double gc_firing[layer_size];
	struct G g;
	
	init_firing(gc_firing, layer_size);

	for (int t = 0; t <= g.run_time; t++) {
		move_path(gc_firing, t, &g);

		print_firing(layer_x, layer_y, gc_firing, t, &g);

		write_firing(layer_x, layer_y, gc_firing, t, &g);		
	}

	return 0;
}