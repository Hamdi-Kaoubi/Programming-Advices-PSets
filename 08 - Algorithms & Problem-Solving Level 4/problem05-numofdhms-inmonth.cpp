#include <iostream>
using namespace std;

short ReadYear()
{
    short year;
    cout << "enter a year to check : ";
    cin >> year;
    return year;
}

short ReadMonth()
{
    short Month;
        do
            {
                cout << "Enter a month to check : ";
                cin >> Month;
            } while(Month < 1 and Month > 12);
    return Month;
}

bool CheckLeap(short year)
{
    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
}

short DaysInMonth(short year, short month)
{
    return (month == 2 and CheckLeap(year)) ? 29 : (month == 2 and !CheckLeap(year)) ? 28 :
        (month == 4 or month == 6 or month == 9 or month == 11) ? 30 : 31;
}

short HoursInMonth(short year, short month)
{
    return DaysInMonth(year, month) * 24;
}

int MunitesInMonth(short year, short month)
{
    return HoursInMonth(year, month) * 60;
}

int SecondsInMonth(short year, short month)
{
    return MunitesInMonth(year, month) * 60;
}


int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    cout << "\nNumber of days    in month [" << month << "] is " << DaysInMonth(year, month) << "\n";
    cout << "Number of hours   in month [" << month << "] is " << HoursInMonth(year, month) << "\n";
    cout << "Number of munites in month [" << month << "] is " << MunitesInMonth(year, month) << "\n";
    cout << "Number of seconds in month [" << month << "] is " << SecondsInMonth(year, month) << "\n";
}

