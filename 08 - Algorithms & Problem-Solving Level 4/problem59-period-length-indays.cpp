#include <iostream>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};
struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
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
sPeriod ReadAllPeriod()
{
    sPeriod Period;
    cout << "\nEnter Start Date : \n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date : \n";
    Period.EndDate = ReadFullDate();
    return Period;
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
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

short GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    short Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}
short GetDifferenceInDays(sPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}



int main()
{
    cout << "Read Period : ";
    sPeriod Period = ReadAllPeriod();
    cout << "\nPeriod Length is: " << GetDifferenceInDays(Period);
    cout << "\nPeriod Length (including end day) is: " << GetDifferenceInDays(Period, true) << "\n";
}
