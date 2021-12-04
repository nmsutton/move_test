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
	int run_time = 23; // sim run time
	char last_dir; // last dir command
	double dist_thresh = 5.0; // distance threshold for only local connections
	int layer_x = 26;
	int layer_y = 26;
	int layer_size = layer_x * layer_y;
};

void ext_input(char direction, double speed, double *gc_firing, G* g);

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
}