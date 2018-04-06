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

int dayoftheweek(int const day, int const month, int const year)
{
        int d = day + 5;
        return(dayofforever(d, month, year) % 7);
}

int firstdayofmonth(int const month, int const year)
{
        return(dayofforever(6, month, year) % 7);
}

void monthname(int const month)
{
        if (month == 1) print ("JANUARY  ");
        else if (month == 2) print("FEBRUARY ");
        else if (month == 3) print("MARCH    ");
        else if (month == 4) print("APRIL    ");
        else if (month == 5) print("MAY      ");
        else if (month == 6) print("JUNE     ");
        else if (month == 7) print("JULY     ");
        else if (month == 8) print("AUGUST   ");
        else if (month == 9) print("SEPTEMBER");
        else if (month == 10) print("OCTOBER  ");
        else if (month == 11) print("NOVEMBER ");
        else if (month == 12) print("DECEMBER ");
}

void line()
{
        print("+---+---+---+---+---+---+---+");
}

void topofcalendar(int month, int year)
{
        line();
        new_line();
        print("|       "); monthname(month); print(" "); print(year); print("      |");
        new_line();
        line();
        new_line();
        print("|Sun|Mon|Tue|Wed|Thu|Fri|Sat|");
        new_line();
        line();
        new_line();
}

void dayofmonth(int const day, int const month, int const year)
{
        int const numberdays = lengthofmonth(month, year);
        int d = day-1;
        if (day<=numberdays)
        {
                int const weekday = dayoftheweek(day,month,year);
                if (day < 10)
                {
                        if (weekday == 0)
                        {
                                print("| ");
                                print(d + 1);
                                print(" ");
                        }
                        else if (weekday == 6)
                        {
                                print("| ");
                                print(d + 1);
                                print(" |");
                                new_line();
                                line();
                                new_line();

                        }
                        else
                        {
                                print("| ");
                                print(d + 1);
                                print(" ");

                        }
                }
                else if (day >= 10)
                {
                        if (weekday == 0)
                        {
                                        print("| ");
                                        print(d + 1);
                        }
                        else if (weekday == 6)
                        {
                                print("| ");
                                print(d + 1);
                                print("|");
                                new_line();
                                line();
                                new_line();
                        }
                        else
                        {
                                print("| ");
                                print(d + 1);
                        }
                }
                        dayofmonth(day + 1, month, year);
        }
}

void restofcalendar( int const month, int const year)
{

        if (firstdayofmonth(month, year) == 1)
                print("|   ");
        if (firstdayofmonth(month, year) == 2)
                print("|   |   ");
        if (firstdayofmonth(month, year) == 3)
                print("|   |   |   ");
        if (firstdayofmonth(month, year) == 4)
                print("|   |   |   |   ");
        if (firstdayofmonth(month, year) == 5)
                print("|   |   |   |   |   ");
        if (firstdayofmonth(month, year) == 6)
                print("|   |   |   |   |   |   ");
        dayofmonth(1, month, year);
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 0)
        {
                print("|   |   |   |   |   |   |");
                new_line();
                line();
        }
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 1)
        {
                print("|   |   |   |   |   |");
                new_line();
                line();
        }
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 2)
        {
                print("|   |   |   |   |");
                new_line();
                line();
        }
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 3)
        {
                print("|   |   |   |");
                new_line();
                line();
        }
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 4)
        {
                print("|   |   |");
                new_line();
                line();
        }
        if (dayoftheweek(lengthofmonth(month, year), month, year) == 5)
        {
                print("|   |");
                new_line();
                line();
                new_line();
        }
}

void main()
{
        int month;
        int year;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
        topofcalendar(month, year);
        restofcalendar( month, year);
        new_line();
}

