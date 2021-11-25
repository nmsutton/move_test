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

string to_string(double x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}

/*string to_string(int x)
{
  ostringstream ss;
  ss << x;
  return ss.str();
}*/

char get_pd(int x, int y) {
	char pd[100] = { 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'd', 'r', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u', 'l', 'u' }; 

	int gc_ind = (y * 10) + x;

	return pd[gc_ind];
}

void print_firing(int layer_x, int layer_y, double *gc_firing) {
	int layer_size = layer_x * layer_y;
	int gc_ind = 0; // grid cell index
	double temp;

	for (int i = (layer_x - 1); i >= 0; i--) {
		for (int j = 0; j < layer_y; j++) {
			gc_ind = (i * layer_x) + j;

			printf("[%f]\t",gc_firing[gc_ind]);
		}
		cout << "\n";
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

	int w1 = 4;
	int w2 = 3;
	int w3 = 2;
	for (int i = 0; i < layer_size; i++) {
		gc_firing[i] = 1.0;
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

void ext_input(char direction, double *gc_firing) {
	/*
		Apply external input

		https://en.wikipedia.org/wiki/Ricker_wavelet
		mexican hat: (2/(sqrt(pow((3*sigma*PI),(1/4))))*(pow(1-pow(x/sigma,2),(exp(pow(-1*x,2)/pow(2*sigma,2))))))
	*/	
	double new_gc_firing[100];
	// init
	for (int i = 0; i < 100; i++) {
		new_gc_firing[i] = 0.000001;
	}
	int pd_i = 0;
	int gc_i = 0;
	double d;
	double y_inter = 0.5; // y intercept
	double new_firing;
	double mex_hat; // mexican hat
	double scale = 0.1; // multiple synaptic connections scaling factor
	double sigma = 3.0;

	for (int pdy = 0; pdy < 10; pdy++) {
		for (int pdx = 0; pdx < 10; pdx++) {
			//if (direction == get_pd(pdx, pdy) && pdx == 1 && pdy == 7) {
			if (direction == get_pd(pdx, pdy)) {
				pd_i = (pdy * 10) + pdx;
				for (int gcy = 0; gcy < 10; gcy++) {
					for (int gcx = 0; gcx < 10; gcx++) {			
						gc_i = (gcy * 10) + gcx;

						d = get_distance(pdx, pdy, gcx, gcy, direction);
						//d = get_distance(pdx, pdy, gcx, gcy, 'n');

						if (d < 3.0) {
							// distance threshold for only local connections

							mex_hat = (2/(sqrt(pow((3*sigma*PI),(1/4)))))*(1-pow(d/sigma,2))*(exp(pow(-1*d,2)/pow(2*sigma,2)));

							new_firing = y_inter + gc_firing[pd_i] * scale * mex_hat;
							//new_firing = y_inter + gc_firing[pd_i] * scale;
							//new_firing = d;

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
	
	init_firing(gc_firing, layer_size);

	ext_input('u', gc_firing);

	for (int i = 0; i < 10; i++) {
		cout << "time " << i << "\n";

		print_firing(layer_x, layer_y, gc_firing);
	}

	return 0;
}