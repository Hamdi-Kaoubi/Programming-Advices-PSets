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
    } while (Month != 2);
    return Month;
}

bool CheckLeap(short year)
{
    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
}

short DaysInMonth(short year)
{
    return CheckLeap(year) ? 29 : 28;
}

short HoursInMonth(short year)
{
    return DaysInMonth(year) * 24;
}

int MunitesInMonth(short year)
{
    return HoursInMonth(year) * 60;
}

int SecondsInMonth(short year)
{
    return MunitesInMonth(year) * 60;
}


int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    cout << "\nNumber of days    in month [" << month << "] is " << DaysInMonth(year) << "\n";
    cout << "Number of hours   in month [" << month << "] is " << HoursInMonth(year) << "\n";
    cout << "Number of munites in month [" << month << "] is " << MunitesInMonth(year) << "\n";
    cout << "Number of seconds in month [" << month << "] is " << SecondsInMonth(year) << "\n";
}

