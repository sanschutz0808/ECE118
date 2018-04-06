#include "library.h"

void drawday()
{
	set_pen_color(color::light_blue);
	fill_rectangle(0, 0, 1200, 700);
	set_pen_width(60);
	set_pen_color(color::yellow);
	draw_point(500, 100);
	fill_rectangle(0, 700 - 20, 1201, 21, color::dark_grey);
	fill_rectangle(0, 700 - 40, 1201, 20, color::dark_green);
}

void drawsunset()
{
	set_pen_color(color::orange);
	fill_rectangle(0, 0, 1200, 700);
	set_pen_width(60);
	set_pen_color(color::yellow);
	draw_point(1160, 500);
	fill_rectangle(0, 700 - 20, 1201, 21, color::dark_grey);
	fill_rectangle(0, 700 - 40, 1201, 20, color::dark_green);
}

void drawnight()
{
	set_pen_color(color::black);
	fill_rectangle(0, 0, 1200, 700);
	set_pen_width(60);
	set_pen_color(color::grey);
	draw_point(700, 100);
	fill_rectangle(0, 700 - 20, 1201, 21, color::dark_grey);
	fill_rectangle(0, 700 - 40, 1201, 20, color::dark_green);
}

void drawbackground()
{
	int a = random_in_range(1, 3);
	if (a == 1) drawday();
	if (a == 2) drawsunset();
	if (a == 3) drawnight();
}

void drawwindow(int const x, int const y, int const w, int const h, int const l)
{
	set_pen_color(l);
	fill_rectangle(x, y, w, h);
}

void drawwindowrow(int const n, int const x, int const y, int const w, int const h, int const l, int const a)
{
	if (n > 0)
	{
		drawwindow(x, y, w, h, l);
		drawwindowrow(n - 1, x+w+a, y, w, h, l,a);
	}
}

void drawwindowblock(int const m, int const n, int const x, int const y, int const w, int const h, int const l, int const a, int const b)
{
	if (m > 0)
	{
		drawwindowrow(n, x, y, w, h, l, a);
		drawwindowblock(m - 1, n, x, y + h + b, w, h, l, a, b);
	}
}

void finaldrawwindowblock(int const xf, int const yf, int const wb)
{
	double const s = random_in_range(0, 5);
	double const t = random_in_range(0, 3);
	double const l = make_color_hls(.6666, s / 10, t / 10);
	int const m= random_in_range(3, 10);
	int const n= random_in_range(4, 8);
	int const h= random_in_range(25, 50);
	int const a = random_in_range(10, 15);
	int const b = random_in_range(8, 20);
	double const c = random_in_range(0, 10);
	double const r = random_in_range(2, 10);
	double const d = random_in_range(3,7);
	double const e = make_color_hls(c/10, r / 10, d / 10);
	fill_rectangle(xf, 700-((700-yf)+b*(m+1)+h*m), wb, h*m + b*(m + 1), e);
	drawwindowblock(m, n, xf+a, yf-m*h-m*b, (wb-(n+1)*a)/n, h, l, a, b);
}

void drawskyscraper(int const x)
{
	int const wb = random_in_range(100, 250);
	finaldrawwindowblock(x, 680, wb);
}

void drawhousewindowwithcurtains(int const x, int const y, int const w, int const h, int const color)
{
	fill_rectangle(x, y, w, h, color::black);
	set_pen_color(color::red);
	start_shape();
	move_to(x,y);
	note_position();
	move_to(x+10,y);
	note_position();
	move_to(x+4,y+14);
	note_position();
	move_to(x+10,y+h-1);
	note_position();
	move_to(x, y + h-1);
	note_position();
	set_pen_width(1);
	fill_shape();

	start_shape();
	move_to(x+w, y);
	note_position();
	move_to(x +w- 10, y);
	note_position();
	move_to(x + w-4, y + 14);
	note_position();
	move_to(x+w - 10, y + h - 1);
	note_position();
	move_to(x+w, y + h - 1);
	note_position();
	set_pen_width(1);
	fill_shape();

}

void drawhousewindow(int const x, int const y, int const w, int const h, int const color)
{
	fill_rectangle(x, y, w, h, color::black);

}

void drawdoor(double const x, double const y, double const w, double const h, double const color)
{
	fill_rectangle(x, y, w, h, color::dark_blue);
}

void drawonestory(double const xf, double const yf, double const wh, double const h)
{

	double const x = random_in_range(1, 3);
	double const a = random_in_range(5, 7);
	double const w = (wh - 4 * a) / 3;
	int const b = random_in_range(1, 2);
	if (b == 1)
	{
		if (x == 3)
		{
			drawhousewindow(xf + a, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindow(xf + 2 * a + w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + 3 * a + 2 * w, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
		if (x == 2)
		{
			drawhousewindow(xf + a, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindow(xf + 3 * a + 2 * w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + 2 * a + w, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
		if (x == 1)
		{
			drawhousewindow(xf + 3 * a + 2 * w, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindow(xf + 2 * a + w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + a, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
	}
	else
	{
		if (x == 3)
		{
			drawhousewindowwithcurtains(xf + a, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindowwithcurtains(xf + 2 * a + w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + 3 * a + 2 * w, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
		if (x == 2)
		{
			drawhousewindowwithcurtains(xf + a, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindowwithcurtains(xf + 3 * a + 2 * w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + 2 * a + w, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
		if (x == 1)
		{
			drawhousewindowwithcurtains(xf + 3 * a + 2 * w, yf - h + 0.3 * h, (wh - 4 * a) / 3, h / 3, color::black);
			drawhousewindowwithcurtains(xf + 2 * a + w, yf - h + 0.3 * h, w, h / 3, color::black);
			drawdoor(xf + a, yf - h + 0.5*h, w, h * 0.5, color::black);
		}
	}
}

void drawtwostory(double const xf, double const yf, double const wh, double const h)
{
	double const x = random_in_range(1, 3);
	double const a = random_in_range(5, 7);
	double const w = (wh - 4 * a) / 3;
	int const c = random_in_range(1, 2);
	if (c == 1)
	{
		drawhousewindow(xf + a, yf - h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
		drawhousewindow(xf + 2 * a + w, yf - h + 0.1*h, w, h / 4, color::black);
		drawhousewindow(xf + 3 * a + 2 * w, yf - h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
		if (x == 3)
		{
			drawhousewindow(xf + a, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindow(xf + 2 * a + w, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + 3 * a + 2 * w, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
		if (x == 2)
		{
			drawhousewindow(xf + 3 * a + 2 * w, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindow(xf + a, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + 2 * a + w, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
		if (x == 1)
		{
			drawhousewindow(xf + 3 * a + 2 * w, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindow(xf + 2 * a + w, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + a, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
	}
	else
	{
		drawhousewindowwithcurtains(xf + a, yf - h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
		drawhousewindowwithcurtains(xf + 2 * a + w, yf - h + 0.1*h, w, h / 4, color::black);
		drawhousewindowwithcurtains(xf + 3 * a + 2 * w, yf - h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
		if (x == 3)
		{
			drawhousewindowwithcurtains(xf + a, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindowwithcurtains(xf + 2 * a + w, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + 3 * a + 2 * w, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
		if (x == 2)
		{
			drawhousewindowwithcurtains(xf + 3 * a + 2 * w, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindowwithcurtains(xf + a, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + 2 * a + w, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
		if (x == 1)
		{
			drawhousewindowwithcurtains(xf + 3 * a + 2 * w, yf - h + 0.333 * h + 0.1*h + 0.1*h, (wh - 4 * a) / 3, h / 4, color::black);
			drawhousewindowwithcurtains(xf + 2 * a + w, yf - h + 0.333 * h + 0.1*h + 0.1*h, w, h / 4, color::black);
			drawdoor(xf + a, yf - h + 0.6*h, w, h * 0.4, color::black);
		}
	}
}

void drawroof(double const xf, double const yf, double const wh, double const h)
{
	double const a = make_color_hls(0.125, 0.15, 0.5);
	set_pen_color(a);
	//chimmney
	double const x = random_in_range(1, 2);
	if (x == 1)
	{
		double const a = make_color_hls(0.125, 0.15, 0.5);
		set_pen_color(a);
		fill_rectangle(xf, yf - h - 20.0 - 3.0, 8.0, 20.0,a);
		fill_rectangle(xf + 2.0, yf - h - 5.0 - 20.0, 2.0, 2.0, color::black);
	}
	start_shape();
	move_to(xf + wh / 2.0, yf-h-0.4*h);
	note_position();
	move_to(xf + wh*1/20.0+wh, yf - h);
	note_position();
	move_to(xf - wh *1 / 20.0, yf - h);
	note_position();

	set_pen_width(1);
	
	fill_shape();
	
	
}

void drawcastle(int const xf, int const yf,int const wh)
{
	fill_rectangle(xf+wh-30.0, 700.0 -220.0, 50.0, 200.0, color::light_grey);
	fill_rectangle(xf + wh - 30.0, 700.0 - 220.0 - 10.0, 8.0, 10.0, color::light_grey);
	fill_rectangle(xf + wh - 30.0+5.0+8.0, 700.0 - 220.0 - 10.0, 8.0, 10.0, color::light_grey);
	fill_rectangle(xf + wh - 30.0+10.0+16.0, 700.0 - 220.0 - 10.0, 8.0, 10.0, color::light_grey);
	fill_rectangle(xf + wh - 30.0+15.0+27.0, 700.0 - 220.0 - 10.0, 8.0, 10.0, color::light_grey);
}

void drawhouse(double const xf, double const yf, double const wh)
{
	//castle
	double const x = random_in_range(1, 2);
	if (x == 1)
	{
		drawcastle(xf, yf, wh);
	}
	double const h = random_in_range(80, 150);

	double const r = random_in_range(0, 10);
	double const s = random_in_range(3, 7);
	double const t = random_in_range(1, 9);
	double const l = make_color_hls(r/10, s / 10, t / 10);
	fill_rectangle(xf, yf - h, wh, h, l);
	if (h < 110) drawonestory(xf,yf,wh,h);
	if (h >= 110) drawtwostory(xf, yf, wh, h);
	drawroof(xf,yf,wh,h);

}

void finaldrawhouse(int const xf, int const yf)
{
	int const wh = random_in_range(100, 150);
	drawhouse(xf, xf, wh);
}

void cityscape(int const xf)
{
	int const a = random_in_range(5, 40);
	if (xf < 1200)
	{
		int const x = random_in_range(1, 2);
		if (x == 1)
		{
			int const wh = random_in_range(100, 150);
			drawhouse(xf+a, 680, wh);
			cityscape(xf + a + wh);
		}
		if (x == 2)
		{
			int const wb = random_in_range(100, 250);
			finaldrawwindowblock(xf+a, 680, wb);
			cityscape(xf + a + wb);
		}
	}
}

void drawcircle(int const x, int const y)
{
	double const s = random_in_range(2, 8);
	double const t = random_in_range(5, 10);
	double const l= make_color_hls(.3333, s/10, t/10);
	int const r = random_in_range(2, 15);
	int const a = random_in_range(100, 225);
	int const b = random_in_range(100, 225);
	int const c = random_in_range(100, 225);
	set_pen_color(l);
	set_pen_width(r);
	draw_point(x, y);	
}

void treebody(int const n, int const x, int const h, int const w)
{
	if (n > 0)
	{
		int const p = random_in_range(x -40, x + 40+w);
		int const m = random_in_range(700-20-h-h,700-20-h);
		drawcircle(p,m);
		treebody(n - 1, x, h, w);
	}
}

void tree(int const n)
{
	if (n > 0)
	{
		int const x = random_in_range(0, 1200);
		int const h = random_in_range(70, 130);
		int const w = random_in_range(10, 20);
		fill_rectangle(x, 700 - h - 20, w, h, color::brown);
		treebody(370, x, h, w);
		tree(n - 1);
	}
}

void trees()
{
	int const n = random_in_range(1, 7);
	tree(n);
}

void main()
{
	int const p = random_in_range(30, 50);
	make_window(1200, 700);
	drawbackground();
	cityscape(0);
	trees();
}

