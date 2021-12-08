struct G {
	// general parameters

	// values for synapse activites
	double speed_syn = 1.0;//0.3; // ext input speed level
	double y_inter_syn = 1.0; // y intercept
	double scale_syn = 0.25; //0.1; // multiple synaptic connections scaling factor
	double s_1_syn = 2*.1; // sigma_1
	double s_2_syn = 2;
	double s_3_syn = 2;
	double m_syn = 1; // magnitude variable for mex hat
	double run_time_syn = 2; // sim run time

	// initial values
	double y_inter_init = y_inter_syn; // y intercept
	double scale_init=scale_syn;	
	double s_1_init = s_1_syn; // sigma_1. Note: specific value used for equalibrium of weights over time.
	double s_2_init = s_2_syn;
	double s_3_init = s_3_syn;
	double m_init=m_syn;
	double run_time_init = 1;

	double speed, y_inter, scale, s_1, s_2, s_3, m, run_time;

	int pos[2] = {1,1};
	char last_dir; // last direction command
	double tau = .8; // time constant; TODO: add diff equ for more realistic one
	double dist_thresh = 5.0; // distance threshold for only local connections
	static const int layer_x = 20;//26;
	static const int layer_y = 20;//26;
	static const int layer_size = layer_x * layer_y;
	double weights[layer_size][layer_size];
	double a_sym = 0.5; // alpha sym
	double a_asym = .15;//-1.5; // alpha asym
};

void ext_input(char direction, double speed, double *gc_firing, G* g);

void move_path(double *gc_firing, int t, G* g) {
	// movement path

	double speed = g->speed;
	if (t == 1) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 2) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 3) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 3) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 4) {
		ext_input('u', speed, gc_firing, g);
	}	
	else if (t == 5) {
		ext_input('r', speed, gc_firing, g);
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
	else if (t == 24) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 25) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 26) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 27) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 28) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 29) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 30) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 31) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 32) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 33) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 34) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 35) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 36) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 37) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 38) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 39) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 40) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 41) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 42) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 43) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 44) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 45) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 46) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 47) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 48) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 49) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 50) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 51) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 52) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 53) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 54) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 55) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 56) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 57) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 58) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 59) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 60) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 61) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 62) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 63) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 64) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 65) {
		ext_input('r', speed, gc_firing, g);
	}	
	else {
		ext_input('n', speed, gc_firing, g);
	}
}

void move_path2(double *gc_firing, int t, G* g) {
	// movement path

	double speed = g->speed;
	if (t == 1) {
		ext_input('n', speed, gc_firing, g);
	}	
	else if (t == 3) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 5) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 7) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 9) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 11) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 13) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 15) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 17) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 19) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 21) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 23) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 24) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 25) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 26) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 27) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 28) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 29) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 30) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 31) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 32) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 33) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 34) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 35) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 36) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 37) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 38) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 39) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 40) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 41) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 42) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 43) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 44) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 45) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 46) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 47) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 48) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 49) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 50) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 51) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 52) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 53) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 54) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 55) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 56) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 57) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 58) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 59) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 60) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 61) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 62) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 63) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 64) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 65) {
		ext_input('n', speed, gc_firing, g);
	}
	else {
		ext_input('n', speed, gc_firing, g);
	}
}