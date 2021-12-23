char rand_move() {
	int num_directions = 5;
	int rand_val = rand() % num_directions + 1;
	char direction;

	if (rand_val == 1) {
		direction = 'u';
	}
	else if (rand_val == 2) {
		direction = 'r';
	}
	else if (rand_val == 3) {
		direction = 'd';
	}
	else if (rand_val == 4) {
		direction = 'l';
	}
	else if (rand_val == 5) {
		direction = 'n';
	}

	return direction;
}

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
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 32) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 33) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 34) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 35) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 36) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 37) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 38) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 39) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 40) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 41) {
		ext_input('d', speed, gc_firing, g);
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
	else if (t == 201) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 202) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 203) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 204) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 205) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 206) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 207) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 208) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 209) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 210) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 211) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 212) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 213) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 214) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 215) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 216) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 217) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 218) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 219) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 220) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 221) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 222) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 223) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 224) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 225) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 226) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 227) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 228) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 229) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 230) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 231) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 232) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 233) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 234) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 235) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 236) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 237) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 238) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 239) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 240) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 241) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 242) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 243) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 244) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 245) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 246) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 247) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 248) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 249) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 250) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 251) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 252) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 253) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 254) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 255) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 256) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 257) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 258) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 259) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 260) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 261) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 262) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 263) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 264) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 265) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 266) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 267) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 268) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 269) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 270) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 271) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 272) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 273) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 274) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 275) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 276) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 277) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 278) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 279) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 280) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 281) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 282) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 283) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 284) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 285) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 286) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 287) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 288) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 289) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 290) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 291) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 292) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 293) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 294) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 295) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 296) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 297) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 298) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 299) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 300) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 301) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 302) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 303) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 304) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 305) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 306) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 307) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 308) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 309) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 310) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 311) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 312) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 313) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 314) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 315) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 316) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 317) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 318) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 319) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 320) {
		ext_input('n', speed, gc_firing, g);
	}
	else if (t == 321) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 322) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 323) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 324) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 325) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 326) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 327) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 328) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 329) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 330) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 331) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 332) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 333) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 334) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 335) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 336) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 337) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 338) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 339) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 340) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 341) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 342) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 343) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 344) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 345) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 346) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 347) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 348) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 349) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 350) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 351) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 352) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 353) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 354) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 355) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 356) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 357) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 358) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 359) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 360) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 361) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 362) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 363) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 364) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 365) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 366) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 367) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 368) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 369) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 370) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 371) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 372) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 373) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 374) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 375) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 376) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 377) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 378) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 379) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 380) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 381) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 382) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 383) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 384) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 385) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 386) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 387) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 388) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 389) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 390) {
		ext_input('r', speed, gc_firing, g);
	}	
	else if (t == 391) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 392) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 393) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 394) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 395) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 396) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 397) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 398) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 399) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 400) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 491) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 492) {
		ext_input('r', speed, gc_firing, g);
	}
	else if (t == 493) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 494) {
		ext_input('d', speed, gc_firing, g);
	}
	else if (t == 495) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 496) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 497) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 498) {
		ext_input('u', speed, gc_firing, g);
	}
	else if (t == 499) {
		ext_input('l', speed, gc_firing, g);
	}
	else if (t == 500) {
		ext_input('l', speed, gc_firing, g);
	}
	else {
		ext_input(rand_move(), speed, gc_firing, g);
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