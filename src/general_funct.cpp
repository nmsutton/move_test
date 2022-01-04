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
	double pos[2] = {1,1}; // starting position
	char last_dir; // last direction command
	static const int layer_x = 40;//26;
	static const int layer_y = 40;//26;
	static const int layer_size = layer_x * layer_y;
	double run_time = 1000; // sim run time
	bool print_move = false; // print each move's direction
	bool print_time = true; // print time after processing
	bool init_bumps = true; // inital bumps present
	bool base_input = true; // baseline external signal input
	bool gc_to_gc = true; // grid cell to grid cell signaling
	bool bc_to_gc = false; // boundary cells to grid cells signaling
	bool pc_to_gc = true; // place cells to grid cells signaling
	bool bc_to_pc = true; // boundary cells to place cells signaling
	bool pc_active = true; // pc signaling active. bc->pc->gc can still work even if this is disabled.

	// noise parameters
	bool noise_active = true; // activate noise
	double noise_rand_max = 100; // 0 - rand_max is range of random number gen
	double noise_scale = 0.01; // scale to desired size for firing

	// values for synapse activites
	double speed_syn = 1.0; // starting grid cell input speed level
	//double speed_ext = 1.5; // baseline ext input speed level
	double min_ext = 1.0; // minimum external input for random speed generator. note: signal applied even when stopped.
	double max_ext = 3.0; // maximum external input for random speed generator
	double tau_syn = .6;
	double y_inter_syn = 1.032;//1.055; // y intercept
	double scale_syn = 3.0; // multiple synaptic connections scaling factor
	double m_syn = 0.4; // magnitude variable for mex hat f1
	double m_syn2 = 2.5; // f2 f3
	double m_syn3 = 0.5; // f4
	double m_syn4 = 0.99; // f2 f3
	double s_1_syn = 0.65; // f1
	double s_2_syn = 0.45; // f2 f3
	double s_3_syn = 20; // f4
	double s_4_syn = 1.5; 
	double s_5_syn = 1.0;
	double a_syn = 4.6; // add f2 f3
	double dist_thresh = 22; // distance threshold for only local connections

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
	double speed, tau, y_inter, scale, s_1, s_2, s_3, s_4, s_5, m, m2, m3, m4, a;

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
	double bc_pd = 5.0; // boundary cell prefered distance
	static const int b_num = 4.0; // number of borders
	double bc_distances[b_num];
	// response curve factors
	//double bc_level = 14.0 * 0.25; // level of bc firing
	double bc_a0 = 2.0; // boundary cell A_0 factor for response curve
	double bc_b = 0.25;
	double bc_sig0 = 0.0;
	double bc_y = 0.05;//0.25;
	double bc_a = 0.25;
	double bc_sig = 1.0;
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

	double mex_hat = y_inter + scale * 
	(exp(-1*((m1*pow(d,2))/(2*pow(s1,2))))) -
	m4*(exp(-1*(pow((m2*d)+a,2)/(2*pow(s2,2))))) -
	m4*(exp(-1*(pow((m2*d)-a,2)/(2*pow(s2,2))))) -
	(exp(-1*((m3*pow(d,2)-150)/(2*pow(s3,2)))));

	return mex_hat;
}

double get_distance(int x1, int y1, int x2, int y2, char pd, G *g) {
	// d = sqrt((e_x - i_x - o_x)^2+(e_y - i_y - o_y)^2)
	int x2_x1 = (x2 - x1);
	int y2_y1 = (y2 - y1);
	int half_point = g->layer_x / 2; // layer length divided by 2

	// preferred direction bias
	if (pd == 'u') {
		y2_y1 = y2_y1 - g->speed_syn;
	}
	if (pd == 'd') {
		y2_y1 = y2_y1 + g->speed_syn;
	}
	if (pd == 'r') {
		x2_x1 = x2_x1 - g->speed_syn;
	}
	if (pd == 'l') {
		x2_x1 = x2_x1 + g->speed_syn;
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