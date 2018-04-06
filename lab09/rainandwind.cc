#include "library.h"
#include <fstream>

int lengthofmonth(int month)
{
	if (month == 1) return 31;
	else if (month == 2) return 28;
	else if (month == 3) return 31;
	else if (month == 4) return 30;
	else if (month == 5) return 31;
	else if (month == 6) return 30;
	else if (month == 7) return 31;
	else if (month == 8) return 31;
	else if (month == 9) return 30;
	else if (month == 10) return 31;
	else if (month == 11) return 30;
	else if (month == 12) return 31;
}

int dayofyear(int day, int month)
{
	if (month == 1) return day;
	else if (month > 1 && month < 13)
	{
		int number = lengthofmonth(month - 1) + dayofyear(day, month - 1);
		return (number);
	}
	else if (month < 1 || month>12) cout << "INVALID MONTH";
}

void drawmonths(int const x, int const y, int const a, int const b, int const c, int const d)
{
	set_pen_color(color::light_grey);
	move_to(a + x / 24, c + y + 14);
	write_string("JAN", direction::center);

	move_to(a + 3*x / 24, c + y + 14);
	write_string("FEB", direction::center);

	move_to(a + 5 * x / 24, c + y + 14);
	write_string("MAR", direction::center);

	move_to(a + 7 * x / 24, c + y + 14);
	write_string("APR", direction::center);

	move_to(a + 9 * x / 24, c + y + 14);
	write_string("MAY", direction::center);

	move_to(a + 11 * x / 24, c + y + 14);
	write_string("JUN", direction::center);

	move_to(a + 13 * x / 24, c + y + 14);
	write_string("JUL", direction::center);

	move_to(a + 15 * x / 24, c + y + 14);
	write_string("AUG", direction::center);

	move_to(a + 17 * x / 24, c + y + 14);
	write_string("SEP", direction::center);

	move_to(a + 19 * x / 24, c + y + 14);
	write_string("OCT", direction::center);

	move_to(a + 21 * x / 24, c + y + 14);
	write_string("NOV", direction::center);

	move_to(a + 23 * x / 24, c + y + 14);
	write_string("DEC", direction::center);
}

void drawverticallines(int const x, int const y, int const a, int const b, int const c, int const d)
{
	move_to(a + x / 12, c);
	draw_to(a + x / 12, c + y);
	

	move_to(a + 2 * x / 12, c);
	draw_to(a + 2 * x / 12, c + y);

	move_to(a + 3 * x / 12, c);
	draw_to(a + 3 * x / 12, c + y);

	move_to(a + 4 * x / 12, c);
	draw_to(a + 4 * x / 12, c + y);

	move_to(a + 5 * x / 12, c);
	draw_to(a + 5 * x / 12, c + y);

	move_to(a + 6 * x / 12, c);
	draw_to(a + 6 * x / 12, c + y);

	move_to(a + 7 * x / 12, c);
	draw_to(a + 7 * x / 12, c + y);

	move_to(a + 8 * x / 12, c);
	draw_to(a + 8 * x / 12, c + y);

	move_to(a + 9 * x / 12, c);
	draw_to(a + 9 * x / 12, c + y);

	move_to(a + 10 * x / 12, c);
	draw_to(a + 10 * x / 12, c + y);

	move_to(a + 11 * x / 12, c);
	draw_to(a + 11 * x / 12, c + y);

	move_to(a + 12 * x / 12, c);
	draw_to(a + 12 * x / 12, c + y);
}

void drawhorizontallines(int const x, int const y, int const a, int const b, int const c, int const d)
{
	move_to(a, c + y / 10);
	draw_to(a + x, c + y / 10);
	move_to(a-5, c + y / 10);
	write_string("90", direction::west);

	move_to(a, c + 2*y / 10);
	draw_to(a + x, c + 2*y / 10);
	move_to(a-5, c + 2 * y / 10);
	write_string("80", direction::west);

	move_to(a, c + 3 * y / 10);
	draw_to(a + x, c + 3 * y / 10);
	move_to(a-5, c + 3 * y / 10);
	write_string("70", direction::west);

	move_to(a, c + 4 * y / 10);
	draw_to(a + x, c + 4 * y / 10);
	move_to(a-5, c + 4 * y / 10);
	write_string("60", direction::west);

	move_to(a, c + 5 * y / 10);
	draw_to(a + x, c + 5 * y / 10);
	move_to(a-5, c + 5 * y / 10);
	write_string("50", direction::west);

	move_to(a, c + 6 * y / 10);
	draw_to(a + x, c + 6 * y / 10);
	move_to(a-5, c + 6 * y / 10);
	write_string("40", direction::west);

	move_to(a, c + 7 * y / 10);
	draw_to(a + x, c +7 * y / 10);
	move_to(a-5, c + 7 * y / 10);
	write_string("30", direction::west);

	move_to(a, c + 8 * y / 10);
	draw_to(a + x, c + 8 * y / 10);
	move_to(a-5, c + 8 * y / 10);
	write_string("20", direction::west);

	move_to(a, c + 9 * y / 10);
	draw_to(a + x, c + 9 * y / 10);
	move_to(a-5, c + 9 * y / 10);
	write_string("10", direction::west);

	move_to(a, c + 10 * y / 10);
	draw_to(a + x, c + 10 * y / 10);
	move_to(a-5, c + 10 * y / 10);
	write_string("0", direction::west);

	move_to(a - 5, c);
	write_string("100", direction::west);

}

void drawgrid(int const x, int const y, int const a, int const b, int const c, int const d)
{

	set_pen_color(color::light_grey);
	move_to(a, c);
	draw_to(x + a, c);
	draw_to(x + a, y+c);
	draw_to(a, y +c);
	draw_to(a, c);

	drawverticallines(x, y, a, b, c, d);
	drawhorizontallines(x, y, a, b, c, d);
}

void drawotherhorizontallines(int const x, int const y, int const a, int const b, int const c, int const d)
{
	move_to(a, c + y / 7);
	draw_to(a + x, c + y / 7);
	move_to(a - 5, c + y /7);
	write_string("60", direction::west);

	move_to(a, c + 2 * y / 7);
	draw_to(a + x, c + 2 * y / 7);
	move_to(a - 5, c + 2 * y / 7);
	write_string("50", direction::west);

	move_to(a, c + 3 * y / 7);
	draw_to(a + x, c + 3 * y / 7);
	move_to(a - 5, c + 3 * y / 7);
	write_string("40", direction::west);

	move_to(a, c + 4 * y / 7);
	draw_to(a + x, c + 4 * y / 7);
	move_to(a - 5, c + 4 * y / 7);
	write_string("30", direction::west);

	move_to(a, c + 5 * y / 7);
	draw_to(a + x, c + 5 * y / 7);
	move_to(a - 5, c + 5 * y / 7);
	write_string("20", direction::west);

	move_to(a, c + 6 * y / 7);
	draw_to(a + x, c + 6 * y / 7);
	move_to(a - 5, c + 6 * y / 7);
	write_string("10", direction::west);

	move_to(a, c + 7 * y / 7);
	draw_to(a + x, c + 7 * y / 7);
	move_to(a - 5, c + 7 * y / 7);
	write_string("0", direction::west);

	move_to(a - 5, c);
	write_string("70", direction::west);
}

void drawothergrid(int const x, int const y, int const a, int const b, int const c, int const d)
{

	set_pen_color(color::light_grey);
	move_to(a, c);
	draw_to(x + a, c);
	draw_to(x + a, y + c);
	draw_to(a, y + c);
	draw_to(a, c);

	drawverticallines(x, y, a, b, c, d);
	drawotherhorizontallines(x, y, a, b, c, d);
}

void pencolor(int const l)
{
	if (l == 1) set_pen_color(color::red);
	if (l == 2) set_pen_color(color::orange);
	if (l == 3) set_pen_color(color::dark_green);
	if (l == 4) set_pen_color(color::blue);
	if (l == 5) set_pen_color(color::purple);
}



void averagetemp(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}
	bool prevNegative = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);

		if ((s == 90) || (s == 242) || (s==302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}

		else if ((s != 1) && (avg != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (avg*5.1)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}


	}
	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void minimum(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}
	bool prevNegative = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);

		if ((s == 90) || (s == 242) || (s == 302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}
		else if ((s != 1) && (min != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (min*5.1)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (min*5.1)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (min*5.1)) + c);
			prevNegative = true;
		}

	}

	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void maximum(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}
	bool prevNegative = false;
	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);
		if ((s == 90) || (s == 242) || (s == 302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}
		else if ((s != 1) && (max != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (max*5.1)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (max*5.1)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (max*5.1)) + c);
			prevNegative = true;
		}

	}

	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void snow(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}

	bool prevNegative = false;

	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);
		if ((s == 90) || (s == 242) || (s == 302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}
		else if ((s != 1) && (snow != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (snow*5.1)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (snow*5.1)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (snow*5.1)) + c);
			prevNegative = true;
		}

	}

	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void rain(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}

	bool prevNegative = false;

	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);
		if ((s == 90) || (s == 242) || (s == 302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}
		else if ((s != 1) && (rain != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (rain*7.29)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (rain*7.29)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (rain*7.29)) + c);

			prevNegative = true;
		}

	}

	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void wind(int const x, int const y, int const a, int const c, int const d, string p, int l)
{
	pencolor(l);
	ifstream fin(p);
	if (fin.fail())
	{
		cout << "error in open";
		exit(1);
	}

	bool prevNegative = false;

	while (true)
	{
		set_pen_width(3);
		double year, month, day, min, avg, max, snow, rain, wind;
		fin >> year >> month >> day >> min >> avg >> max >> snow >> rain >> wind;
		if (fin.fail())
		{
			cout << "Not enough data in the file!";
			break;
		}

		double s = dayofyear(day, month);
		if ((s == 90) || (s == 242) || (s == 302))
		{
			move_to((s*2.20) + a, (y - (avg*5.1)) + c);

			prevNegative = true;
		}
		else if( (s != 1) && ( wind != -1) && (prevNegative == false))
		{
			draw_to(((s)*2.2) + a, (y - (wind*7.29)) + c);
			prevNegative = false;
		}
		else if (prevNegative == true)
		{
			move_to((s*2.20) + a, (y - (wind*7.29)) + c);
			prevNegative = false;
		}
		else
		{
			move_to((s*2.20) + a, (y - (wind*7.29)) + c);
		
			prevNegative = true;
		}

	}

	set_pen_color(color::white);
	fill_rectangle(a, y + c + 1, x, d);
	fill_rectangle(a, 0, x, c - 1);
	fin.close();
}

void input(int const x, int const y, int const a, int const b, int const c, int const d, string p)
{
	int f;
	cout << "what would you like to see?" << endl << "press 1 for averages" << endl << "press 2 for mins and maxs" << endl
		<< "press 3 for snow" << endl << "press 4 for rain" << endl << "press 5 for wind" << endl;
	cin >> f;

	cout << "What color do you want the line to be?" << endl;
	cout << "press 1 for red" << endl << "press 2 for orange" << endl << "press 3 for green" << endl << "press 4 for blue" << endl << "press 5 for purple" << endl;
	int l;
	cin >> l;

	if (f == 1)
	{
		make_window(x + a + b, y + c + d);
		set_caption(p);
		drawgrid(x, y, a, b, c, d);
		averagetemp(x, y, a, c, d,p,l);
		drawmonths(x, y, a, b, c, d);
	}
	else if (f == 2)
	{
		cout << "What color do you want the other line to be?" << endl;
		cout << "press 1 for red" << endl << "press 2 for orange" << endl << "press 3 for green" << endl << "press 4 for blue" << endl << "press 5 for purple" << endl;
		int u;
		cin >> u;

		make_window(x + a + b, y + c + d);
		set_caption(p);

		drawgrid(x, y, a, b, c, d);
		minimum(x, y, a, c, d,p,l);
		maximum(x, y, a, c, d,p,u);
		drawmonths(x, y, a, b, c, d);
	}
	else if (f == 3)
	{
		make_window(x + a + b, y + c + d);
		set_caption(p);

		drawgrid(x, y, a, b, c, d);
		snow(x, y, a, c, d,p,l);
		drawmonths(x, y, a, b, c, d);
	}
	else if (f == 4)
	{
		make_window(x + a + b, y + c + d);
		set_caption(p);

		drawothergrid(x, y, a, b, c, d);
		rain(x, y, a, c, d,p,l);
		drawmonths(x, y, a, b, c, d);
	}
	else if (f == 5)
	{
		make_window(x + a + b, y + c + d);
		set_caption(p);

		drawothergrid(x, y, a, b, c, d);
		wind(x, y, a, c, d,p,l);
		drawmonths(x, y, a, b, c, d);
	}
	else cout << "invalid input";
}

void main()
{
	int const a = 50;
	int const b = 15;
	int const c = b;
	int const d =35;
	double const x = 803;
	double const y = 510.0;

	string p= "KANSAS-CITY-MO.txt";

	input(x,y,a,b,c,d,p);
}

