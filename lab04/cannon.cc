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
	double const w = (a - 2)*pi / 180;
	set_heading_degrees(0);
	move_to(x + r*sin(w), y - r*cos(w));
	set_heading_radians(w);
	draw_distance(r*3.7);
	set_heading_degrees(a - 90);
	draw_distance(1.25*r);
	set_heading_degrees(a - 175.25);
	draw_distance(r*6.5);
	set_heading_degrees(a - 270);
	draw_distance(2 * r);
	draw_to(x - r*sin(w), y + r*cos(w));
	set_pen_width(5);
	draw_point(x, y);
}

void draw_final_canon(double const a)
{
	int const x = 75;
	int const y = 640;
	int const r = 20;
	int const n = 360;
	int const angle = 360 / n;
	set_heading_degrees(90);
	draw_circle(x, y, r);
	draw_canon(x, y, a, r);
}

void draw_platform()
{
	set_pen_width(3);
	move_to(15, 700);
	set_heading_degrees(0);
	draw_distance(40);
	set_heading_degrees(90);
	draw_distance(120);
	set_heading_degrees(180);
	draw_distance(40);
}

void draw_enemy(double const k)
{
	set_pen_width(3);


	move_to(k, 700.0);
	set_heading_degrees(0);
	draw_distance(150);
	set_heading_degrees(90);
	draw_distance(120);
	set_heading_degrees(180);
	draw_distance(150);

	move_to(k + 10, 600.0);
	set_heading_degrees(0);
	draw_distance(15);
	set_heading_degrees(90);
	draw_distance(35);
	set_heading_degrees(180);
	draw_distance(15);
	set_heading_degrees(270);
	draw_distance(35);

	move_to(k + 73.0, 600.0);
	set_heading_degrees(0);
	draw_distance(15);
	set_heading_degrees(90);
	draw_distance(35);
	set_heading_degrees(180);
	draw_distance(15);
	set_heading_degrees(270);
	draw_distance(35);
}

double calc_height(double const v, double const t, double const w2)
{
	const double pi = acos(-1.0);
	double const h = v*t*cos(w2) - (0.5*32.174*t*t);
	return (h);
}

double calc_distance(double const v, double const t, double const w2)
{
	const double pi = acos(-1.0);
	double const d = v*t*sin(w2);
	return (d);
}

void invalid_velocity()
{
	make_window(300, 200);
	move_to(25, 50);
	write_string("INVALID VELOCITY. ");
	move_to(25, 100);
	write_string("LOSE A TRY. #YOUSUCK");
}

void you_lose_ta()
{
	make_window(300, 200);
	move_to(25, 100);
	write_string("YOU LOSE, TRY AGAIN");
}

void game_over()
{
	make_window(300, 200);
	move_to(25, 100);
	write_string("GAME OVER");
}

void tabulate(double const v, double const t, double const w2, double const k)
{
	double const h = calc_height(v, t, w2);
	double const d = calc_distance(v, t, w2);

	if (((700 - h) - 90 - (75 * cos(w2)) <= 700) && (((d + 75 + 85 * sin(w2)) <= 1100)) && (v <= 250) && (v >= 0))
		//within window
	{
		if ((d + 75 + 85 * sin(w2) > k) && (550 < (700 - h) - 90 - (75 * cos(w2))) &&
			(d + 75 + 85 * sin(w2) < k + 120) && (700> (700 - h) - 90 - (75 * cos(w2))))
			//within emeny
		{
			make_window(300, 200);
			move_to(50, 100);
			write_string("YOU WIN");
			exit();
		}

		else
		{
			double const j = random_in_range(0.0, 1.0);
			set_pen_width(5);
			set_pen_color(0.0 + 0.2*t, j + 0.1*t, 1.0 - 0.2*t);
			wait(0.01);
			draw_point(d + 75 + 85 * sin(w2), (700 - h) - 90 - (75 * cos(w2)));
			tabulate(v, t + 0.01, w2, k);
		}
	}
	else if ((v > 250) || (v<0))
	{
		invalid_velocity();
	}
	else
	{
		you_lose_ta();
	}
}

double velocity()
{
	print("What velocity would you like to use? (Between 0 and 250) ");
	const double velocity = read_int();
	return (velocity);
	new_line();
}

double angle()
{
	print("What angle would you like to use? ");
	const double angle = read_int();
	return (angle);
	new_line();
}

void try_try(int const n, int const k)
{
	

	if (n > 0)
	{
		make_window(1100, 700);
		draw_final_canon(75);
		draw_enemy(k);
		draw_platform();

		double const v = velocity();
		double const a = angle();

		set_pen_color(color::white);
		draw_final_canon(75);
		//get rid of canon at 75

		set_pen_color(color::black);
		draw_final_canon(a);

		const double pi = acos(-1.0);
		double const w = (a - 2)*pi / 180;
		double const w2 = ((a)*pi) / 180;

		tabulate(v, 0, w2, k);
		wait(2);
		try_try(n - 1,k);
	}
	
	if (n == 0) game_over();

}

void main()
{
	double const k = random_in_range(300, 980);
	try_try(3,k);
}

