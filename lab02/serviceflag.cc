void draw_star(int const x, int const y, int const side, int const colorside, int const width, int const colorfill)
	{start_shape();
	move_to(x,y);
	note_position();
	set_pen_color(colorside);
	set_pen_width(width);
	turn_right_by_degrees(162);
	draw_distance(side);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(side);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(side);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(side);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(side);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(side);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(side);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(side);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(side);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(side);
	note_position();
	set_pen_width(1);
	set_pen_color(colorfill);
	fill_shape();}

void main()
	{double const width=500;
	double const height=width*0.66666;
	make_window (width, height);
	fill_rectangle(0.0,0.0,width,height, color::red);
	fill_rectangle(0.1456 *width,0.180785*height,0.70879*width,0.63843*height, color::white);
	draw_star(0.5*width, 0.33*height, 0.09*width, color::blue, 1, color::blue);}

