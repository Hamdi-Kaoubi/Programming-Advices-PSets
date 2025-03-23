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
bool IsDate1EqualsDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? Date1.Day == Date2.Day ? true : false : false) : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) and !IsDate1EqualsDate2(Date1, Date2);
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
void SwapDates(sDate& Date1, sDate& Date2)
{
    sDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;
    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;
    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualsDate2(Date1, Date2))
        return enDateCompare::Equal;
    /* if (IsDate1AfterDate2(Date1,Date2))
    return enDateCompare::After;*/
    //this is faster
    return enDateCompare::After;
}
short GetDifferenceInDays(sDate Date1, sDate Date2)
{
    short Days = 0;
    short SawpFlagValue = 1;
    if (CompareDates(Date1, Date2) == enDateCompare::After)
    {
        //Swap Dates
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }
    /*f (CompareDates(Date1, Date2) == enDateCompare::Equal)
    {
        Days = 0;
    }*/
    while (CompareDates(Date1, Date2) == enDateCompare::Before)
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return Days * SawpFlagValue;
}
short GetDifferenceInDays(sPeriod Period, bool IncludeEndDay = false)
{
    short Days = GetDifferenceInDays(Period.StartDate, Period.EndDate);
    return IncludeEndDay ? ++Days : Days;
}



int main()
{
    cout << "Read Period : ";
    sPeriod Period = ReadAllPeriod();
    cout << "\nPeriod Length is: " << GetDifferenceInDays(Period);
    cout << "\nPeriod Length (including end day) is: " << GetDifferenceInDays(Period, true) << "\n";
}