#include "library.h"

int lengthofmonth(int month, int year)
{
        if (month == 1) return 31;
        else if (month == 2)
        {
                if (year % 4 == 0)
                {
                        if (year % 100==0)
                        {
                                if (!(year % 400==0)) return 28;
                                else return 29;
                        }
                        else return 29;
                }
                else return (28);
        }
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

int dayofyear(int day, int month, int year)
{
        if (month == 1) return day;
        else if (month > 1 && month < 13)
        {
                int number = lengthofmonth(month - 1, year) + dayofyear(day, month - 1, year);
                return (number);
        }
        else if (month < 1 || month>12) cout << "INVALID MONTH";
}

int dayofforever(int day, int month, int year)
{
        if (year == 0) return (dayofyear(day, month, year)-1);

        else if (year>0)
        {
                return(dayofyear(31, 12, year-1) + dayofforever(day, month, year - 1));
        }
        else if (year < 0) cout << "INVALID YEAR";
}

int dayofforeverreal(int const day, int const month, int const year)
{
        if ((lengthofmonth(2, year) == 28) && (dayofyear(day, month, year) >= 60))
        {
                int final = dayofforever(day, month, year);
                return final;
        }
        else return (dayofforever(day, month, year)) +1;
}

void main()
{
        int day;
        int month;
        int year;
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
        print("Day of forever: ");
        print(dayofforeverreal(day,month,year));
        new_line();
}



