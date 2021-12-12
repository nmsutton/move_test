struct G {
	// general parameters

	// values for synapse activites
	double speed_syn = 0.3;//0.2924981;//1.0;//0.3; // ext input speed level
	double tau_syn = .6;//.7; // time constant; TODO: add diff equ for more realistic one
	double tau2 = 1.0;//.9;	
	double y_inter_syn = 0.1; // y intercept
	double scale_syn = 1.0; //0.1; // multiple synaptic connections scaling factor
	double s_1_syn = 1.5;//1.8*.404318655; // sigma_1
	double s_2_syn = 2.3;//1.8;
	double s_3_syn = 2.2;
	double m_syn = 1.0; // magnitude variable for mex hat
	double run_time_syn = 200; // sim run time

	// initial values
	double y_inter_init = y_inter_syn; // y intercept
	double scale_init=scale_syn;	
	double s_1_init = s_1_syn; // sigma_1. Note: specific value used for equalibrium of weights over time.
	double s_2_init = s_2_syn;
	double s_3_init = s_3_syn;
	double m_init=m_syn;
	double run_time_init = 1;

	double speed, tau, y_inter, scale, s_1, s_2, s_3, m, run_time;

	int pos[2] = {1,1};
	char last_dir; // last direction command
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
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 3) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 4) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 5) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 6) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 7) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 8) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 9) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 10) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 11) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 12) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 13) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 14) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 15) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 16) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 17) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 18) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 19) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 20) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 21) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 22) {
		ext_input('r', speed, gc_firing, g);
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
	else if (t == 66) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 67) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 68) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 69) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 70) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 71) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 72) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 73) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 74) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 75) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 76) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 77) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 78) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 79) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 80) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 81) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 82) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 83) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 84) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 85) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 86) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 87) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 88) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 89) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 90) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 91) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 92) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 93) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 93) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 94) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 95) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 96) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 97) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 98) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 99) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 100) {
		ext_input('l', speed, gc_firing, g);
	}	
	else if (t == 101) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 102) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 103) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 104) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 105) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 106) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 107) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 108) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 109) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 110) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 111) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 112) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 113) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 114) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 115) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 116) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 117) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 118) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 119) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 120) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 121) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 122) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 123) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 124) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 125) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 126) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 127) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 128) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 129) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 130) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 131) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 132) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 133) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 134) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 135) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 136) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 137) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 138) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 139) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 140) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 141) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 142) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 143) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 144) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 145) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 146) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 147) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 148) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 149) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 150) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 151) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 152) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 153) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 154) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 155) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 156) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 157) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 158) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 159) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 160) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 161) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 162) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 163) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 164) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 165) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 166) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 167) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 168) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 169) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 170) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 171) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 172) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 173) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 174) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 175) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 176) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 177) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 178) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 179) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 180) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 181) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 182) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 183) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 184) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 185) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 186) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 187) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 188) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 189) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 190) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 191) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 192) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 193) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 193) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 194) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 195) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 196) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 197) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 198) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 199) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 200) {
		ext_input('l', speed, gc_firing, g);
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