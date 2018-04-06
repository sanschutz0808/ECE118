#include "library.h"

void readfile(string arr[], int const size, int & maxrow)
{
	ifstream fin("examplemaze.txt");

	if (fin.fail())
	{
		cout << "can't open input file" << endl;
	}
	else
	{
		cout << "file opened properly" << endl;

		int i = 0;

		while (true)
		{
			fin >> arr[i];
			maxrow = i;
			if (fin.eof()) break;
			i++;
		}
		
		fin.close();
	}
}

void findaandb(string arr[], int const size, int & xa, int & ya, int & xb, int & yb, int & xe, int & ye)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < arr[i].length(); j++)
		{
			if (arr[i][j] == 'A')
			{
				xa = j;
				ya = i;
			}
			if (arr[i][j] == 'B')
			{
				xb = j;
				yb = i;
			}
			if (arr[i][j] == 'E')
			{
				xe = j;
				ye = i;
			}
		}
	}
	//cout << endl << xa << "," << ya << endl << xb << "," << yb << endl << xe << "," << ye << endl << arr[0].length();
}

void drawverticallines(string arr[],int maxrow, int squaresize)
{
	int numbercolumns = arr[0].length();
	int i=0;
	for (i = 0; i <= numbercolumns;  i++)
	{
		set_pen_color(color::black);
		set_pen_width(2);
		move_to(i*squaresize, 0);
		draw_to(i*squaresize, squaresize * maxrow);
	}
}

void drawhorizontallines(string arr[], int maxrow, int squaresize)
{
	int numbercolumns = arr[0].length();
	int i = 0;
	for (i = 0; i <= maxrow; i++)
	{
		set_pen_color(color::black);
		set_pen_width(2);
		move_to(0, i*squaresize);
		draw_to(squaresize*(numbercolumns), i*squaresize);
	}
}

void drawgrid(string arr[], int maxrow, int squaresize)
{
	make_window((squaresize * arr[0].length()), squaresize * maxrow);
	drawverticallines(arr, maxrow, squaresize);
	drawhorizontallines(arr, maxrow, squaresize);
}

void fillingrid(string arr[], int maxrow, int squaresize)
{
	for (int i = 0; i < maxrow; i++)
	{
		for (int j = 0; j < arr[0].length(); j++)
		{
			if (arr[i][j] == '#') set_pen_color(color::dark_grey);
			else if (arr[i][j] == '.') set_pen_color(color::white);
			else if (arr[i][j] == 'A') set_pen_color(color::green);
			else if (arr[i][j] == 'B') set_pen_color(color::red);
			fill_rectangle(j * squaresize + 1, i * squaresize + 1, squaresize-2, squaresize-2);
		}
	}
}

void enemy(string arr[], int maxrow, int numbercolumns, int squaresize, int & xa, int & ya, int & xb, int & yb, int & xe, int & ye)
{
	
	while (true)
	{
		
		int s = random_in_range(1, 4);
		if ((s == 1)&&(ye+1<=maxrow-1))//down
		{
			if (!(arr[ye + 1][xe] == '#'))
			{
				set_pen_color(color::purple);
				fill_rectangle(xe * squaresize + 1, (ye + 1) * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xe* squaresize + 1, (ye)* squaresize + 1, squaresize - 2, squaresize - 2);
				ye = ye + 1;
				break;
			}
		}
		if ((s == 2)&&(xe+1<=numbercolumns-1))//right
		{
			if (!(arr[ye][xe + 1] == '#') )
			{
				set_pen_color(color::purple);
				fill_rectangle((xe + 1) * squaresize + 1, ye * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xe* squaresize + 1, (ye)* squaresize + 1, squaresize - 2, squaresize - 2);
				xe = xe + 1;
				break;
			}
		}
		if ((s == 3)&&(ye-1>=0))//up
		{
			if (!(arr[ye - 1][xe] == '#') )
			{
				set_pen_color(color::purple);
				fill_rectangle(xe * squaresize + 1, (ye - 1) * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xe* squaresize + 1, (ye)* squaresize + 1, squaresize - 2, squaresize - 2);
				ye = ye - 1;
				break;
			}
		}
		if ((s == 4)&&(xe-1>=0))//left
		{
			if (!(arr[ye][xe - 1] == '#'))
			{
				set_pen_color(color::purple);
				fill_rectangle((xe - 1) * squaresize + 1, ye * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xe* squaresize + 1, (ye)* squaresize + 1, squaresize - 2, squaresize - 2);
				xe = xe - 1;
				break;
			}
		}
		char w = wait_for_key_typed(0.05);
		if ((ya == ye) && (xa == xe))
		{
			break;
		}
	}
}

void automatic(string arr[], int maxrow, int numbercolumns, int squaresize, int & xa, int & ya, int & xb, int & yb, int & xe, int & ye)
{
	while (true)
	{
		if (xa == xb && yb == ya)
		{
			break;
		}
		int s= random_in_range(1, 4);
		if ((s == 1)&&(ya+1<=maxrow-1))//down
		{
			if (!(arr[ya + 1][xa] == '#')   )
			{
				set_pen_color(color::green);
				fill_rectangle(xa * squaresize + 1, (ya + 1) * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
				ya = ya + 1;
			}
		}
		if((s==2)&&(xa+1<=numbercolumns-1))//right
		{ 
			if (!(arr[ya][xa+1] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle((xa+1) * squaresize + 1, ya * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya) * squaresize + 1, squaresize - 2, squaresize - 2);
				xa = xa + 1;
			}
		}
		if ((s == 3)&&(ya-1>=0))//up
		{ 
			if (!(arr[ya-1][xa] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle(xa * squaresize + 1, (ya - 1) * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
				ya = ya - 1;
			}
		}
		if((s==4)&&(xa-1>=0))//left
		{ 
			if (!(arr[ya][xa - 1] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle((xa - 1) * squaresize + 1, ya * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
				xa = xa - 1;
			}
		}
		enemy(arr, maxrow, numbercolumns, squaresize, xa, ya, xb, yb, xe, ye);
		if ((ya == ye) && (xa == xe))
		{
			set_pen_color(color::black);
			fill_rectangle(xa * squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
			wait(0.8);
			make_window(300, 200);
			move_to(65, 120);
			set_font_size(50);
			set_pen_color(color::blue);
			write_string("You Lose");
			break;
		}
		char w= wait_for_key_typed(0.05);
		
		if (w == 'm') break;
		if (w == 'x') break;
	}
}

void robotmove(string arr[], int maxrow, int numbercolumns, int squaresize, int & xa, int & ya, int & xb, int & yb, int & xe, int & ye)
{
	set_pen_color(color::purple);
	fill_rectangle(xe * squaresize + 1, (ye)* squaresize + 1, squaresize - 2, squaresize - 2);
	while (true)
	{
		if (xa==xb && yb==ya)
		{
			set_pen_color(color::yellow);
			fill_rectangle(xa * squaresize + 1, (ya ) * squaresize + 1, squaresize - 2, squaresize - 2);
			wait(0.8);
			make_window(300, 200);
			move_to(65, 120);
			set_font_size(50);
			set_pen_color(color::blue);
			write_string("You win!!!");
			break;
		}
		char c = wait_for_key_typed();
		if ((c == -88)&&(ya+1<=maxrow-1)) //down
		{
			if (!(arr[ya + 1][xa] == '#'))
			{
					set_pen_color(color::green);
					fill_rectangle(xa * squaresize + 1, (ya + 1) * squaresize + 1, squaresize - 2, squaresize - 2);
					set_pen_color(color::white);
					fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
					ya = ya + 1;
				
			}
		}
		if ((c == -89)&&(xa+1<=numbercolumns-1))//right
		{ 
			if (!(arr[ya][xa+1] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle((xa+1) * squaresize + 1, ya * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya) * squaresize + 1, squaresize - 2, squaresize - 2);
				xa = xa + 1;
			}
		}
		if ((c == -90)&&(ya-1>=0))//up
		{ 
			if (!(arr[ya-1][xa] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle(xa * squaresize + 1, (ya - 1) * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
				ya = ya - 1;
			}
		}
		if ((c == -91)&&(xa-1>=0))//left
		{ 
			if (!(arr[ya][xa - 1] == '#'))
			{
				set_pen_color(color::green);
				fill_rectangle((xa - 1) * squaresize + 1, ya * squaresize + 1, squaresize - 2, squaresize - 2);
				set_pen_color(color::white);
				fill_rectangle(xa* squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
				xa = xa - 1;
			}
		}
		enemy(arr, maxrow, numbercolumns, squaresize, xa, ya, xb, yb, xe, ye);
		if ((ya == ye) && (xa == xe))
		{
			set_pen_color(color::black);
			fill_rectangle(xa * squaresize + 1, (ya)* squaresize + 1, squaresize - 2, squaresize - 2);
			wait(0.8);
			make_window(300, 200);
			move_to(65, 120);
			set_font_size(50);
			set_pen_color(color::blue);
			write_string("You Lose");
			break;
		}

		if (c == 'x') break;
		if (c == 'a')
		{
			automatic(arr, maxrow, numbercolumns, squaresize, xa,ya,xb,yb,xe,ye);
		}
	}
}

void playgame()
{
	int xa, ya, xb, yb, xe, ye;

	int squaresize = 25;
	int const size = 100;
	string arr[size];
	int maxrow = 0;
	readfile(arr, size, maxrow);
	findaandb(arr, size, xa, ya, xb, yb,xe,ye);

	int numbercolumns = arr[0].length();

	drawgrid(arr, maxrow, squaresize);
	fillingrid(arr, maxrow, squaresize);
	
	robotmove(arr, maxrow, numbercolumns, squaresize, xa, ya, xb, yb,xe,ye);
}

void main()
{
	cout << "To enter automatic mode press a" << endl << "To return to manual mode push m" << endl << "To exit game push x"<<endl<<"Don't run into the purple enemy!"<<endl;
	playgame();
}

