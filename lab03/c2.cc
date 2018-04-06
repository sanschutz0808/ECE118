#include "library.h"

void line_and_turn(int const n, double const side, int const angle)
{
	if (n > 0)
	{	
		draw_distance(side);
		turn_right_by_degrees(angle);
		line_and_turn(n - 1, side, angle);
	}
}


void draw_circle(double const x, double const y, double const r)
{
	const double pi = acos(-1.0);
	double const c = 2 * r * pi;
	double const side = c / 360;
	set_pen_width(3);
	move_to(x, y - r);
	line_and_turn(360, side, 1);
}


void draw_canon(int const x, int const y, int const a, int const r)
{

	const double pi = acos(-1.0);
	double const w = (a-2)*pi / 180;
	set_heading_degrees(0);
	move_to(x + r*sin(w), y - r*cos(w));
	set_heading_radians(w);
	draw_distance(r*3.7);
	set_heading_degrees(a-90);
	draw_distance(1.25*r);
	set_heading_degrees(a-175.25);
	draw_distance(r*6.5);
	set_heading_degrees(a-270);
	draw_distance(2 * r);
	draw_to(x - r*sin(w), y + r*cos(w));
	set_pen_width(5);
	draw_point(x, y);
}


void main()
{
	int const x = 200;
	int const y = 610;
	int const a = 30;
	int const r = 50;
	int const n = 360;
	int const angle = 360 / n;
	make_window(1000, 700);
	set_heading_degrees(90);
	draw_circle(x, y, r);
	draw_canon(x, y, a, r);
}

