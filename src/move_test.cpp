#include <vector>
#include <math.h> // for sqrt() and other functions

// for to_string()
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#define PI 3.14159265

using namespace std;

string to_string(double x);

struct G {
	// general parameters

	double speed; // ext input speed level
	double y_inter; // y intercept
	double scale; //0.1; // multiple synaptic connections scaling factor
	double s_1; // sigma_1
	double s_2;
	double s_3;
	double m; // magnitude variable for mex hat
	int pos[2] = {1,1};
};

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

void print_firing(int layer_x, int layer_y, double *gc_firing, int t, G* g) {
	int layer_size = layer_x * layer_y;
	int gc_ind = 0; // grid cell index
	double temp;

	if (t != 0) {
		cout << "time: " << t << " sec\n";

		for (int i = (layer_x - 1); i >= 0; i--) {
			for (int j = 0; j < layer_y; j++) {
				gc_ind = (i * layer_x) + j;

				printf("[%f]",gc_firing[gc_ind]);

				if (g->pos[0] == j && g->pos[1] == i) {
					printf(" (+)");
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

	int w1 = 12;
	int w2 = 9;
	int w3 = 6;
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
	g->speed = 5; // ext input speed level
	g->y_inter = 1; // y intercept
	g->scale = 0.1; //0.1; // multiple synaptic connections scaling factor
	g->s_1 = 2.0; // sigma_1
	g->s_2 = 2.0;
	g->s_3 = 2.5;
	g->m = 1.5; // magnitude variable for mex hat

	double y_inter = g->y_inter; // y intercept
	double scale = g->scale; // multiple synaptic connections scaling factor
	double s_1 = g->s_1;
	double s_2 = g->s_2;
	double s_3 = g->s_3;
	double m = g->m;

	set_pos(g, direction);

	for (int pdy = 0; pdy < 10; pdy++) {
		for (int pdx = 0; pdx < 10; pdx++) {
			//if (direction == get_pd(pdx, pdy) && pdx == 1 && pdy == 7) {
			if (direction == get_pd(pdx, pdy)) {
				pd_i = (pdy * 10) + pdx;
				for (int gcy = 0; gcy < 10; gcy++) {
					for (int gcx = 0; gcx < 10; gcx++) {			
						gc_i = (gcy * 10) + gcx;

						d = get_distance(pdx, pdy, gcx, gcy, direction);

						if (d < 3.0) {
							// distance threshold for only local connections

							mex_hat = (2/(sqrt(pow((3*s_1*PI),(1/4)))))*(1-pow((m*d)/s_2,2))*(exp(pow(-1*(m*d),2)/pow(2*s_3,2)));

							new_firing = y_inter + gc_firing[pd_i] * speed * scale * mex_hat;
							//new_firing = y_inter + speed * scale * mex_hat;
							//new_firing = y_inter + scale * mex_hat;
							//new_firing = y_inter + mex_hat;
							//new_firing = mex_hat;
							//new_firing = d;

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

void move_path(double *gc_firing, int t, G* g) {
	// movement path

	double speed = g->speed;
	if (t == 1) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 3) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 5) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 7) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 9) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 11) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 13) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 15) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 17) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 19) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 21) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 23) {
		ext_input('u', speed, gc_firing, g);
	}
}

int main() {
	int layer_x = 10;
	int layer_y = 10;
	int layer_size = layer_x * layer_y;
	int run_time = 23;
	double gc_firing[layer_size];
	struct G g;
	
	init_firing(gc_firing, layer_size);

	for (int t = 0; t < run_time; t++) {
		move_path(gc_firing, t, &g);

		print_firing(layer_x, layer_y, gc_firing, t, &g);
	}

	return 0;
}