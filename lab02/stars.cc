#include "library.h"

void draw_star(int const x, int const y, int const side, int const colorside, int const width, int const rotation, int const colorfill)
	{start_shape();
	move_to(x,y);
	note_position();
	set_pen_color(colorside);
	set_pen_width(width);
	set_heading_degrees(rotation);
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
	{make_window(500,500);
	draw_star(250,200,100,color::indigo,5,0,color::magenta);
	draw_star(150,100,50,color::purple,5,45,color::pink);
	draw_star(350,100,50,color::dark_grey,5,-45,color::mauve);
	draw_star(250,50,25,color::blue,5,0,color::light_blue);}


