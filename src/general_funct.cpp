/*
	General functions and parameters
*/

#define PI 3.14159265

struct G {
	// general parameters
	static const int bump_init_x = 1.0; // initial bump x
	static const int bump_init_y = 1.0; // initial bump y
	static const int bump_dist = 20.0; // inter-bump distance
	int bumps_x = 2; // number of bumps on x axis
	int bumps_y = 2; // number of bumps on y axis
	int num_bumps = bumps_x * bumps_y; // number of initial bumps
	int pos[2] = {1,1}; // starting position
	char last_dir; // last direction command
	static const int layer_x = 40;//26;
	static const int layer_y = 40;//26;
	static const int layer_size = layer_x * layer_y;
	double run_time_syn = 1000; // sim run time
	bool print_move = false; // print each move's direction
	bool print_time = true; // print time after processing

	// noise parameters
	bool noise_active = false; // activate noise
	double noise_rand_max = 100; // 0 - rand_max is range of random number gen
	double noise_scale = 0.005; // scale to desired size for firing

	// values for synapse activites
	double speed_syn = 1.5; // ext input speed level
	double tau_syn = .6;
	double y_inter_syn = 0.69; // y intercept
	double scale_syn = 3.0; // multiple synaptic connections scaling factor
	double m_syn = 0.6; // magnitude variable for mex hat
	double m_syn2 = 2.5;
	double m_syn3 = 0.5; 
	double m_syn4 = 1.0; 
	double s_1_syn = 0.95;
	double s_2_syn = 0.26;
	double s_3_syn = 12;
	double s_4_syn = 1.0;
	double s_5_syn = 1.0;
	double a_syn = 4.5; // add
	double dist_thresh = 20; // distance threshold for only local connections

	// initial values
	double y_inter_init = y_inter_syn; // y intercept
	double scale_init=scale_syn;	
	double s_1_init = s_1_syn; // sigma_1. Note: specific value used for equalibrium of weights over time.
	double s_2_init = s_2_syn;
	double s_3_init = s_3_syn;
	double s_4_init = s_4_syn;
	double s_5_init = s_5_syn;
	double m_init=m_syn;
	double m_init2=m_syn2;
	double m_init3=m_syn3;
	double m_init4=m_syn4;
	double a_init=a_syn;
	double run_time_init = 1;
	double speed, tau, y_inter, scale, s_1, s_2, s_3, s_4, s_5, m, m2, m3, m4, a, run_time;

	// tau time constant and asymmetric sigmoid parameters. https://en.wikipedia.org/wiki/Gompertz_function
	double asig_a = -5;//-8.0;//0.6;//0.45;//2.0;//0.45;
	double asig_b = 2.5;//2.2;//9.89493996719;//0.6;//2.15;//0.6;
	double asig_c = 5.0;//4.9898;//3.0;//0.457921;//1.0;//0.5;
	double asig_yi = 0.0;//-0.9;//0.0;//-0.9;
	double asig_scale = 1.0;//2.0;//-0.9;

	// place cell parameters
	double pc_sig = 0.25; // sigma symbol; width of the place feild
	double pc_level = 14.0; // place cell firing level

	// boundary cell parameters
	double r_d = 1.0; // boundary cell active region width
	double bc_firing_scale = 0.1; // amount of boundary cell firing when activated
};

double get_mex_hat(double d, G *g) {
	double y_inter = g->y_inter;
	double s1 = g->s_1;
	double s2 = g->s_2;
	double s3 = g->s_3;
	double s4 = g->s_4;
	double s5 = g->s_5;
	double m1 = g->m;
	double m2 = g->m2;
	double m3 = g->m3;
	double m4 = g->m4;
	double a = g->a;
	double scale = g->scale;

	/*double mex_hat = y_inter + scale * 
	(2/(sqrt(3*s_1*pow(PI,1/4)))) *
	(1-pow((m*d)/s_2,2)) *
	(exp(-1*(pow(m*d,2)/(2*pow(s_3,2))))) -
	(exp(-1*(pow(m2*d,2)/(2*pow(s_4,2))))) -
	.8*(exp(-1*(pow((m4*d)-m3,2)/(2*pow(s_5,2))))) -
	.8*(exp(-1*(pow((m4*d)+m3,2)/(2*pow(s_5,2)))));*/

	/*double mex_hat = 0.85 + ((exp(-1*((.105*pow(d,2))/(2*pow(0.6,2)))))*10.7
	 - (exp(-1*(.07*pow(d,2)/(2*pow(.55,2)))))*8.5)*1.3
	 - (exp(-1*(1.9*pow(d,2)/(2*pow(35,2)))));*/

	/*double mex_hat = 0.94 + 
	(2/(sqrt(3*1*pow(PI,1/4)))) *
	1.5*(1-pow((1*d)/1,2)) *
	(exp(-1*(pow(1*d,2)/(2*pow(1,2))))) -
	(exp(-1*((1.9*pow(d,2))/(2*pow(55,2)))));*/

	double mex_hat = y_inter + scale * 
	(exp(-1*(m1*pow(d,2)/(2*pow(s1,2))))) -
	1.2*(exp(-1*(pow((m2*d)+a,2)/(2*pow(s2,2))))) -
	1.2*(exp(-1*(pow((m2*d)-a,2)/(2*pow(s2,2))))) -
	(exp(-1*(m3*pow(d,2)/(2*pow(s3,2)))));

	/*mex_hat = .87+1.5* 
	(2/(sqrt(3*.25*pow(PI,1/4)))) *
	(1-pow((1.5*d)/10,2)) *
	(exp(-1*(pow(1.5*d,2)/(2*pow(1.5,2))))) -
	(exp(-1*(pow(.5*d,2)/(2*pow(15,2))))) -
	(exp(-1*(pow((4.5*d)-8,2)/(2*pow(.5,2))))) -
	(exp(-1*(pow((4.5*d)+8,2)/(2*pow(.5,2)))));*/

	return mex_hat;
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