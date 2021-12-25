/*
	boundary cells

	based on methods in (Hardcastle, 2015)
*/

struct angle_details
{
	double boundary_angle = 0.0;
	double boundary_angle_2 = 0.0;
	bool boundary_found = false;
	bool boundary_found_2 = false;
};

angle_details detect_boundary(double x, double y, G *g) {
	struct angle_details a;

	if (y >= 0 && y < g->r_d) {
		a.boundary_found = true;
		a.boundary_angle = 180.0;
	}
	else if (y <= g->layer_y && y > (g->layer_y - g->r_d)) {
		if (a.boundary_found) {
			a.boundary_found_2 = true;
			a.boundary_angle_2 = 0.0;
		}
		else {
			a.boundary_found = true;
			a.boundary_angle = 0.0;
		}
	}
	else if (x <= g->layer_x && x > (g->layer_x - g->r_d)) {
		if (a.boundary_found) {
			a.boundary_found_2 = true;
			a.boundary_angle_2 = 90.0;
		}
		else {
			a.boundary_found = true;
			a.boundary_angle = 90.0;
		}
	}
	else if (x >= 0 && x < g->r_d) {
		if (a.boundary_found) {
			a.boundary_found_2 = true;
			a.boundary_angle_2 = 270.0;
		}
		else {
			a.boundary_found = true;
			a.boundary_angle = 270.0;
		}
	}

	return a;
}

void create_bc_firing(double x, double y, double *gc_firing, G *g) {
	/*
		create firing based on a boundary being active
	*/

	double mex_hat, d;
	int gc_i;

	for (int gcy = 0; gcy < g->layer_y; gcy++) {
		for (int gcx = 0; gcx < g->layer_x; gcx++) {
			gc_i = (gcy * g->layer_x) + gcx;
			d = get_distance(x, y, gcx, gcy, 'n', g);

			if (d < g->dist_thresh) { 
				mex_hat = get_mex_hat(d, g);
				gc_firing[gc_i] = gc_firing[gc_i] + (g->bc_firing_scale * mex_hat);
			}
		}
	}
}

void periodic_firing(double x, double y, double *gc_firing, angle_details *a, G *g) {
	/* 
		Add periodic firing based on boundary angle. The periods of
		firing are the expected distance between bumps. E.g., for
		every bump expected there is firing.
	*/

	if (a->boundary_angle == 90 || a->boundary_angle == 270) {
		for (int i = 1; i < g->bumps_x; i++) {
			create_bc_firing((x + (g->bump_dist*i)), y, gc_firing, g);
		}
	}
	else {
		for (int i = 1; i < g->bumps_y; i++) {
			create_bc_firing(x, (y + (g->bump_dist*i)), gc_firing, g);
		}	
	}
}

void boundary_cell_firing(double *gc_firing, G *g) {
	/*
		generate boundary cell firing
	*/

	struct angle_details a;

	for (int y = 0; y < g->layer_y; y++) {
		for (int x = 0; x < g->layer_x; x++) {
			a = detect_boundary(x, y, g);

			if (a.boundary_found) {
				create_bc_firing(x, y, gc_firing, g);
				periodic_firing(x, y, gc_firing, &a, g);
			}
			if (a.boundary_found_2) {
				create_bc_firing(x, y, gc_firing, g);
				periodic_firing(x, y, gc_firing, &a, g);
			}
		}
	}
}