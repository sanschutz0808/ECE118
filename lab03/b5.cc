#include "library.h"

void stars(int const n)
{
	if (n > 0)
	{
		print("*");
		stars(n - 1);
	}
}

void dots(int const n)
{
	if (n > 0)
	{
		print(".");
		dots(n - 1);
	}
}

void dotssstars(int const a, int const b)
{
	dots(a);
	stars(b);
	dots(a);
}

void triangle(int const x, int const y)
{
	if (x>0)
	{
		dotssstars(x-1,y);
		new_line();
		triangle(x-1,y+2);
	}
	
}

void main()
{
	triangle(5, 1);
	
}

