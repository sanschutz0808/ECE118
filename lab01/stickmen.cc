#include "library.h"

void main()
	{make_window(500,500);
	set_pen_width(5);
	move_to(250,180);
	turn_right_by_degrees(180);
	draw_distance(150);
	turn_right_by_degrees(30);
	draw_distance(80);
	move_to(250,330);
	turn_left_by_degrees(60);
	draw_distance(80);
	move_to(250,230);
	turn_right_by_degrees(60+30);
	draw_distance(65);
	move_to(250,230);
	set_heading_degrees(50);
	draw_distance(65);
	set_pen_width(70);
	draw_point(250,145);
	set_pen_color(color::white);
	set_pen_width(60);
	draw_point(250,145);}

