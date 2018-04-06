#include "library.h"

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
	fill_shape();
	set_heading_degrees(0);}

void draw_stripes(double const height, double const width)
	{set_pen_color(color::red);
	fill_rectangle(0.0, 0.0, width, 0.076923*height);
	fill_rectangle(0.0, 0.15385*height, width, 0.076923*height);
	fill_rectangle(0.0, 0.30769*height, width, 0.076923*height);
	fill_rectangle(0.0, 0.46154*height, width, 0.076923*height);	
	fill_rectangle(0.0, 0.61538*height, width, 0.076923*height);
	fill_rectangle(0.0, 0.76923*height, width, 0.076923*height);													
	fill_rectangle(0.0, 0.92308*height, width, 0.076923*height);}

void draw_six_stars(double const height, double const width, double const x)	
	{draw_star(0.033333*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.1000000*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.1666666*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.2333333*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.3000000*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.3666666*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);}

void draw_rows_of_six(double const height, double const width, double const x)
	{draw_six_stars(height,width,1);
	draw_six_stars(height,width,5);
	draw_six_stars(height,width,9);
	draw_six_stars(height,width,13);
	draw_six_stars(height,width,17);}

void draw_five_stars(double const height, double const width, double const x)
	{draw_star(0.066666*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.1333333*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.2000000*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.2666666*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);
	draw_star(0.3333333*width, 0.026923*x*height, 0.011111*width, color::white, 1, color::white);}

void draw_rows_of_five(double const height, double const width, double const x)
	{draw_five_stars(height,width,3);
	draw_five_stars(height,width,7);
	draw_five_stars(height,width,11);
	draw_five_stars(height,width,15);}

void main()
	{double const height=700;
	double const width=1.9*height;
	make_window(width,height);
	draw_stripes(height, width);
	fill_rectangle(0.0,0.0,0.4*width, 0.538463*height, color::blue);
	draw_rows_of_six(height, width, 1);
	draw_rows_of_five(height, width, 1);}


