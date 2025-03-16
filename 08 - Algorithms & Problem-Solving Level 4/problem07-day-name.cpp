#include <iostream>
using namespace std;

short ReadYear()
{
    short year;
    cout << "Please enter a year : ";
    cin >> year;
    return year;
}
bool CheckLeap(short year)
{
    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
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
short ReadDay()
{
    short day;
    cout << "Please enter a day : ";
    cin >> day;
    return day;
}

void checkValidityOfDays(short year, short month, short day)
{
   /* while (month < 1 or month > 12)
    {
        cout << "Invalid month, please put in a valid month \n";
        month = ReadMonth();
    }*/
    while ((CheckLeap(year) and month == 2 and (day < 1 or day > 29)) or (!CheckLeap(year) and month == 2 and (day < 1 or day > 28)))
    {
        cout << "Invalid day, please put in a valid day \n";
        month = ReadDay();
    }
    while ((month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12) and (day < 1 or day > 31))
    {
        cout << "Invalid day, please put in a valid day \n";
        month = ReadDay();
    }
    while ((month == 4 or month == 6 or month == 9 or month == 11) and (day < 1 or day > 30))
    {
        cout << "Invalid day, please put in a valid day \n";
        month = ReadDay();
    }
}

int DayOrder(short year, short month, short day)
{
    float a = (14 - month) / 12;
    float y = year - a;
    float m = month + 12 * a - 2;
    int d = (int)(day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

string DayName(int dayOrder)
{
    string Day = "";
    string ArrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    for (int i = 0; i < 7; i++)
    {
        if (i == dayOrder)
            Day += ArrDays[i];
    }
    return Day;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();
    checkValidityOfDays(year, month, day);
    cout << "\nDate      : " << day << "/" << month << "/" << year << "\n";
    cout << "Day Order : " << DayOrder(year, month, day) << "\n";
    cout << "Day Name  : " << DayName(DayOrder(year, month, day)) << "\n";
}

