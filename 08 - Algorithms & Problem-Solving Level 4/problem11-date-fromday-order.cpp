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
    cout << "Please enter a day : ";
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
short DaysFromBeginning(short year, short month, short day)
{
    short FromBeginning = 0;
    for (short i = 1; i < month; i++)
    {
        FromBeginning += DaysInMonth(year, i);
    }
    FromBeginning += day;
    return FromBeginning;
}

void PrintDateFromDay(short year, short dayFromBeginning)
{
    short monthsCounter = 1;
    short daysInMonth = DaysInMonth(year, monthsCounter);
    while (dayFromBeginning >= daysInMonth)
    {
        dayFromBeginning -= daysInMonth;
        monthsCounter++;
        daysInMonth = DaysInMonth(year, monthsCounter);
    }
    cout << dayFromBeginning << "/" << monthsCounter << "/" << year << "\n";
}






int main()
{
    short day = ReadDay();
    short month = ReadMonth();
    short year = ReadYear();
    short daysFromBeginning = DaysFromBeginning(year, month, day);
    cout << "\nNumber of days from the beginning of the year is : " << daysFromBeginning << "\n";
    cout << "\nDate for [" << daysFromBeginning << "] is : ";
    PrintDateFromDay(year, daysFromBeginning);
}

