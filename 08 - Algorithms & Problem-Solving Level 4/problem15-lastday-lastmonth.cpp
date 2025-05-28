#include <iostream>
using namespace std;

short ReadYear()
{
    short year;
    cout << "Please enter a year : ";
    cin >> year;
    return year;
}
short ReadMonth()
{
    short month;
    cout << "Please enter a month : ";
    cin >> month;
    return month;
}
short ReadDay()
{
    short day;
    cout << "\nPlease enter a day : ";
    cin >> day;
    return day;
}
bool CheckLeap(short year)
{
    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
}
short DaysInMonth(short year, short month)
{
    if (month < 1 or month > 12)
        return 0;
    short DaysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (CheckLeap(year) ? 29 : 28) : DaysOfMonth[month - 1];
}

bool IsLastDayInMonth(short year, short month, short day)
{
    return day == DaysInMonth(year, month);
}
bool IsLastMonthInYear(short month)
{
    return month == 12;
}


int main()
{
    short day = ReadDay();
    short month = ReadMonth();
    short year = ReadYear();
    if (IsLastDayInMonth(year, month, day))
        cout << "\nYes, " << day << " is last day in " << month << ".\n";
    else
        cout << "\nNo, " << day << " is NOT last day in " << month << ".\n";
    if(IsLastMonthInYear(month))
        cout << "\nYes, " << month << " is last month in " << year << ".\n";
    else
        cout << "\No, " << month << " is NOT last month in " << year << ".\n";
}