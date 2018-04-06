#include "library.h"

void write_numbers(int const a, int const b)
{
	int const x = 1.609344*a;
	double const y = (int)(100*a / 60.0 +0.5);
	double const z = y / 100;
	if (a == b)
	{
		print(b);
		print(" mph is ");
		print(x);
		print(" kph or ");
		print(z);
		print(" mpm.");
		new_line();
	}
		
	else if (a < b)
	{
		print(a);
		print(" mph is ");
		print(x);
		print(" kph or ");
		print(z);
		print(" mpm.");
		new_line();
		return(write_numbers(a+5, b));
	
	}
}

void main()
{
	write_numbers(10, 90);
}

