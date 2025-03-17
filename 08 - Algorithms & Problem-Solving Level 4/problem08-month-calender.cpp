#include <iostream>
#include <string>
#include <iomanip>
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
    do
    {
        cout << "Please enter a month : ";
        cin >> month;
    } while (month < 1 or month > 12);
    return month;
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
short DayOrder(short year, short month, short day = 1)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintMonthCalender(short month, short daysInMonth, short dayOrder, short day = 1)
{
    string Months[] = { "", "Jan", "Feb", "Mar", "Aprl", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    string Days[] = { "Sun   ", "Mon   ", "Tue   ", "Wed   ", "Thu   ", "Fri   ", "Sat" };
    cout << "\n\t__________________" << Months[month] << "__________________\n\n";
    cout << "\t";
    for (short i = 0; i < 7; i++)
    {
        cout << Days[i];
    }
    cout << "\n\t";
        for (short i = 0; i < 5; i++)
        {
            for (short j = 0; j < 7; j++)
            {
                while ( i == 0 and j < dayOrder)
                {
                    cout << "      ";
                    j++;
                }
                if (day <= daysInMonth)
                {
                    cout << setw(3) << right << day << "   ";
                    day++;
                }
            }
            cout << "\n\t";
        }
    cout << "_______________________________________\n";
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short days = DaysInMonth(year, month);
    short dayOrder = DayOrder(year, month);
    PrintMonthCalender(month, days, dayOrder);
}


