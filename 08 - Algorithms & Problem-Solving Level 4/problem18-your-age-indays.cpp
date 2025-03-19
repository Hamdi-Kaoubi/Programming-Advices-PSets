#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <cctype>
#include <sstream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};
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
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
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

bool IsLessThan(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == DaysInMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short month)
{
    return month == 12;
}
sDate IncreaseDateByOneDay(sDate& Date)
{
    if (IsLastDayInMonth(Date))
    {
        Date.Day = 1;
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
            Date.Month++;
    }
    else
        Date.Day++;
    return Date;
}
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsLessThan(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

sDate GetTodayTime()
{
    stringstream ss; //object used to convert string to integer
    sDate Date;
    string Months[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    time_t t = time(0);
    char* dt = ctime(&t);
    string TodayDateString = "";
    while (TodayDateString.length() <= 24)
    {
        TodayDateString += *dt;
        dt++;
    }
    ss << TodayDateString.substr(8, 2);
    ss >> Date.Day;
    ss.clear();
    for (short i = 0; i < 13; i++)
    {
        if (Months[i] == TodayDateString.substr(4, 3))
            Date.Month = i;
    }
    ss << TodayDateString.substr(20, 4);
    ss >> Date.Year;
    ss.clear();
    return Date;
}



int main()
{
    sDate YourAge = ReadFullDate();
    sDate DateNow = GetTodayTime();
    cout << "\nYour Age is : " << GetDifferenceInDays(YourAge, DateNow, true) << " Day(s).\n";
}

