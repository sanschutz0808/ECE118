#include "library.h"

int year()
{
	int const x = get_calendar_date();
	int const year = x / 10000;
	return(year);
}

int month()
{
	int const x = get_calendar_date();
	int const month = (x / 100) % 100;
	return(month);
}

int day()
{
	int const x = get_calendar_date();
	int const day = x % 100;
	return(day);
}

int hourmt()
{
	int const y = get_clock_time();
	int const hour = y / 10000;
	return(hour);
}

int hour()
{
	int const y = get_clock_time();
	int const hour = y / 10000;
	if (hour > 12)
	{
		return(hour - 12);
	}
	else
	{
		return(hour);
	}
}

int minute()
{
	int const y = get_clock_time();
	int const minute = (y / 100) % 100;
	return(minute);
}

int second()
{
	int const y = get_clock_time();
	int const second = y % 100;
	return(second);
}

void get_times()
{
	print("  year: ");  print(year());   new_line();
	print(" month: ");  print(month());  new_line();
	print("   day: ");  print(day());    new_line();
	print("  hour: "); print(hour()); new_line();
	print("minute: ");  print(minute()); new_line();
	print("second: ");  print(second()); new_line();
}

void draw_second_ticks(double const n)
{
	if (n > 0)
	{
		move_to(250, 315);
		double const x = 6*(60-n);
		set_pen_width(2);
		set_heading_degrees(x);
		set_pen_color(color::white);
		draw_distance(137);
		set_pen_color(0.0 +(60-n) /70.0, 0.0 + (60 - n) / 70.0, 0.0 + (60 - n) / 70.0);
		draw_distance(13);
		draw_second_ticks(n - 1);
	}
}

void draw_hour_ticks(double const n)
{
	if (n > 0)
	{
		move_to(250, 315);
		set_pen_width(4);
		double const x = 30 * (12 - n);
		set_heading_degrees(x);
		set_pen_color(color::white);
		draw_distance(132);
		set_pen_color((1.0 - (12-n) / 12.0, 0.0, 0.0 + (12-n) / 12.0));
		draw_distance(18);
		draw_hour_ticks(n - 1);
	}
}

void draw_second_hand()
{
	move_to(250,315);
	set_pen_width(3);
	double const a = second();
	set_pen_color(0.0 + a / 70.0, 0.0 + a / 70.0, 0.0 + a / 70.0);
	set_heading_degrees(6 * second());
	draw_distance(-15);
	draw_distance(121);
}

void draw_minute_hand()
{
	move_to(250, 315);
	set_pen_width(5);
	double const a = second();
	double const b = minute();
	set_pen_color(0.0 + b / 70.0, 0.0 + b / 70.0, 0.0 + b / 70.0);
	set_heading_degrees((6 * (b + (a / 60))));
	draw_distance(-15);
	draw_distance(121);
}

void draw_hour_hand()
{
	move_to(250, 315);
	set_pen_width(7);
	double const a = second();
	double const b = minute();
	double const c = hour();
	set_pen_color(color::black);
	set_heading_degrees(30.0 *( c + b/60 +a/3600));
	draw_distance(-10);
	draw_distance(90);
}

void draw_hands()
{
	draw_second_hand();
	draw_minute_hand();
	draw_hour_hand();
}

void print_time()
{
	move_to(150, 100);
	set_font_size(60);
	write_string(hour());
	write_string(":");
	if (minute() >= 10)
	{
		write_string(minute());
	}
	if (minute() < 10)
	{
		write_string("0");
		write_string(minute());
	}

	if (hourmt() < 12)
	{
		write_string(" AM");
	}
	if (hourmt() >= 12)
	{
		write_string(" PM");
	}
}

string month_name()
{
	if (month() == 1)
	{
		return("Janury ");
	}
	if (month() == 2)
	{
		return("February ");
	}
	if (month() == 3)
	{
		return("March ");
	}
	if (month() == 4)
	{
		return("Apirl ");
	}
	if (month() == 5)
	{
		return("May ");
	}
	if (month() == 6)
	{
		return("June ");
	}
	if (month() == 7)
	{
		return("July ");
	}
	if (month() == 8)
	{
		return("August ");
	}
	if (month() == 9)
	{
		return("September ");
	}
	if (month() == 10)
	{
		return("October ");
	}
	if (month() == 11)
	{
		return("November ");
	}
	if (month() == 12)
	{
		return("December ");
	}

}

void print_date()
{
	move_to(40, 550);
	write_string(day());
	if ((day() == 1) || (day() == 21) || (day() == 31))
	{
		write_string("st ");
	}
	if ((day() == 2) || (day() == 22))
	{
		write_string("nd ");
	}
	if ((day() == 3)|| (day() == 23))
	{
		write_string("rd ");
	}
	if (((day()>3)&&(day()<21))|| ((day()>23) && (day()<31)))
	{
		write_string("th ");
	}
	
	write_string(month_name());
	write_string(year());


}

void main()
{
	make_window(500, 630);
	draw_second_ticks(60);
	draw_hour_ticks(12);
	print_time();
	print_date();
	get_times();
		while (true)
		{
			draw_hands();
			wait(.7);
			set_pen_color(color::white);
			set_pen_width(219);
			draw_point(250, 315);
		}
}

