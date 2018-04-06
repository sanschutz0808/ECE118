#include "library.h"

void drawbutton(double const x, double const y, double const w, double const h)
{
	fill_rectangle(x, y, w, h, color::light_grey);
	set_pen_width(2);
	set_pen_color(color::black);
	move_to(x, y);
	turn_right_by_degrees(90);
	draw_distance(w);
	turn_right_by_degrees(90);
	draw_distance(h);
	turn_right_by_degrees(90);
	draw_distance(w);
	turn_right_by_degrees(90);
	draw_distance(h + 1);
}

void drawbuttonnames(double const x, double const y, double const w, double const h, double const a, double b)
{
	set_font_size(50);
	move_to(x + w / 2, y + h / 2);
	set_pen_color(color::black);
	write_string("+", direction::center);

	move_to(x+(5 * (a / 21.0)) + w / 2, y + h / 2);
	write_string("7", direction::center);

	move_to(x+(5 *2* (a / 21.0)) + w / 2, y + h / 2);
	write_string("8", direction::center);

	move_to(x+(5 *3* (a / 21.0)) + w / 2, y + h / 2);
	write_string("9", direction::center);

	move_to(x + w / 2, y +5 * (b / 26.0)+ h / 2);
	write_string("-", direction::center);

	move_to(x + (5 * (a / 21.0)) + w / 2, y + 5 * (b / 26.0) + h / 2);
	write_string("4", direction::center);

	move_to(x + (5 *2* (a / 21.0)) + w / 2, y + 5 * (b / 26.0) + h / 2);
	write_string("5", direction::center);

	move_to(x + (5 *3* (a / 21.0)) + w / 2, y + 5 * (b / 26.0) + h / 2);
	write_string("6", direction::center);
	
	move_to(x + w / 2, y + 5 *2* (b / 26.0) + h / 2);
	write_string("*", direction::center);

	move_to(x + (5  * (a / 21.0)) + w / 2, y + 5 *2* (b / 26.0) + h / 2);
	write_string("1", direction::center);

	move_to(x + (5 *2* (a / 21.0)) + w / 2, y + 5 * 2 * (b / 26.0) + h / 2);
	write_string("2", direction::center);

	move_to(x + (5 *3* (a / 21.0)) + w / 2, y + 5 * 2 * (b / 26.0) + h / 2);
	write_string("3", direction::center);

	move_to(x + w / 2, y + 5 * 3 * (b / 26.0) + h / 2);
	write_string("/", direction::center);

	move_to(x + (5 * (a / 21.0)) + w / 2, y + 5 * 3 * (b / 26.0) + h / 2);
	write_string("=", direction::center);

	move_to(x + (5 * 2 * (a / 21.0)) + w / 2, y + 5 * 3 * (b / 26.0) + h / 2);
	write_string("0", direction::center);

	move_to(x + (5 * 3 * (a / 21.0)) + w / 2, y + 5 * 3 * (b / 26.0) + h / 2);
	write_string("C", direction::center);
}

void drawbuttonrow(double const x, double const y, double const w, double const h, int const n, double const a, double const b)
{
	if (n>0)
	{ 
		drawbutton(x, y, h, w);
		drawbuttonrow(x + 5 * (a / 21.0), y, w, h,n-1, a, b);
	}
}

void drawallbuttons(double const x, double const y, double const w, double const h, int const t, double const a, double const b)
{
	if (t > 0)
	{
		drawbuttonrow(x, y, w, h, 4, a, b);
		drawallbuttons(x, y+5*(b/26.0), w, h, t-1, a, b);
	}
}


void finaldrawbuttons(double const a, double const b)
{
	double const x = a / 21.0;
	double const y = b *(6 / 26.0);
	double const w = a*(4 / 21.0);
	double const h = b * (4 / 26.0);
	drawallbuttons(x, y, w, h, 4, a, b);
	drawbuttonnames(x, y, w, h,a,b);
}

int clickbuttonscolumn(double const a, double const b, double const xc, double const yc)
{
	double const x = a / 21.0;
	double const y = b *(6 / 26.0);
	double const w = a*(4 / 21.0);
	double const h = b * (4 / 26.0);

	if ((x <= xc) && (xc <= x + w))
	{
		return 1;
	}
	if ((x + 5 * (a / 21.0) <= xc) && (xc <= (x + 5 * (a / 21.0)) + w))
	{
		return 2;
	}
	if ((x + 2 * 5 * (a / 21.0) <= xc) && (xc <= (x + 2 * 5 * (a / 21.0)) + w))
	{
		return 3;
	}
	if ((x + 3 * 5 * (a / 21.0) <= xc) && (xc <= (x + 3 * 5 * (a / 21.0)) + w))
	{
		return 4;
	}
}

int clickbuttonsrow(double const a, double const b,double const xc, double const yc)
{
	double const x = a / 21.0;
	double const y = b *(6 / 26.0);
	double const w = a*(4 / 21.0);
	double const h = b * (4 / 26.0);

	if ((y <= yc) && (yc <= y + h))
	{
		return 1;
	}
	if ((y + 5 * (b / 26.0) <= yc) && (yc <= y + 5 * (b / 26.0) + h))
	{
		return 2;
	}
	if ((y + 2 * 5 * (b / 26.0) <= yc) && (yc <= y + 2 * 5 * (b / 26.0) + h))
	{
		return 3;
	}
	if ((y + 3 * 5 * (b / 26.0) <= yc) && (yc <= y + 3 * 5 * (b / 26.0) + h))
	{
		return 4;
	}
}

int translatebuttons(double const a, double const b)
{
	wait_for_mouse_click();
	const int xc = get_click_x(), yc = get_click_y();
	int z = clickbuttonsrow(a,b,xc,yc);
	int w = clickbuttonscolumn(a, b, xc, yc);
	if ((z == 1) && (w == 2))
	{
		return 7;
	}
	else if ((z == 1) && (w == 3))
	{
		return 8;
	}
	else if ((z == 1) && (w == 4))
	{
		return 9;
	}
	else if ((z == 2) && (w == 2))
	{
		return 4;
	}
	else if ((z == 2) && (w == 3))
	{
		return 5;
	}
	else if ((z == 2) && (w == 4))
	{
		return 6;
	}
	else if ((z == 3) && (w == 2))
	{
		return 1;
	}
	else if ((z == 3) && (w == 3))
	{
		return 2;
	}
	else if ((z == 3) && (w == 4))
	{
		return 3;
	}
	else if ((z == 4) && (w == 3))
	{
		return 0;
	}
	else if ((z == 1) && (w == 1))
	{
		return 11;
		//+
	}
	else if ((z == 2) && (w == 1))
	{
		return 12;
		//-
	}
	else if ((z == 3) && (w == 1))
	{
		return 13;
		//*
	}
	else if ((z == 4) && (w == 1))
	{
		return 14;
		// /
	}
	else if ((z == 4) && (w == 2))
	{
		return 15;
		// =
	}
	else if ((z == 4) && (w == 4))
	{
		return 16;
		// C
	}
}

int number(double const a, double const b)
{
	int num = 0;
	int newnum = 0;
	{
		num = translatebuttons(a, b);
		if (num < 10)
		{
			newnum = newnum * 10 + num;
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			set_pen_color(color::light_blue);
			write_string(newnum, direction::west);
		}
		
	}
	return newnum;
}

void storenumber(double const a, double const b)
{
	int num = 0;
	int newnum = 0;
	fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
	while (true)
	{
		num = translatebuttons(a, b);
		if (num < 10)
		{
			newnum = newnum * 10 + num;
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			set_pen_color(color::light_blue);
			write_string(newnum, direction::west);
		}
		if (num == 11)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			set_pen_color(color::light_blue);
			write_string("+", direction::west);


			int savenum = newnum;
			int new_num = number(a, b);
			newnum = savenum + new_num;
		}

		if (num == 12)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			set_pen_color(color::light_blue);
			write_string("-", direction::west);


			int savenum = newnum;
			int new_num = number(a, b);
			newnum = savenum - new_num;
		}
		if (num == 13)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			set_pen_color(color::light_blue);
			write_string("*", direction::west);


			int savenum = newnum;
			int new_num = number(a, b);
			newnum = savenum * new_num;
		}
		if (num == 14)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			set_pen_color(color::light_blue);
			write_string("/", direction::west);


			int savenum = newnum;
			int new_num = number(a, b);
			newnum = savenum / new_num;
		}
		if (num == 15)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			move_to(20 * (a / 21.0) - 10, 3 * (b / 26.0));
			set_pen_color(color::light_blue);
			write_string(newnum, direction::west);
		}
		if (num == 16)
		{
			fill_rectangle((a / 21.0), (b / 26.0), a*19.0 / 21.0, b*(4.0 / 26.0), color::black);
			storenumber(a, b);
		}
	}
}

void main()
{
	double const a = 580.0;
	double const b = 700.0;
	make_window(a, b);
	finaldrawbuttons(a, b);
	storenumber(a, b);

}

