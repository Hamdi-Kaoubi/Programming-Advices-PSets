#include <iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
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
bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == DaysInMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short month)
{
    return month == 12;
}
bool IsFirstDayInMonth(sDate Date)
{
    return Date.Day == 1;
}
bool IsFirstMonthInYear(short month)
{
    return month == 1;
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
sDate DecreaseDateByOneDay(sDate& Date)
{
    if (IsFirstDayInMonth(Date))
    {
        if (IsFirstMonthInYear(Date.Month))
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = DaysInMonth(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
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
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualsDate2(Date1, Date2))
        return enDateCompare::Equal;
    return enDateCompare::After;
}
bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) ==
        enDateCompare::Before
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) ==
        enDateCompare::After
        )
        return false;
    else
        return true;
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
short PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}
bool IsDateWithinPeriod(sPeriod Period, sDate Date)
{
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
        || CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDateWithinPeriod(Period2, Period1.StartDate))
                OverlapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateWithinPeriod(Period1, Period2.StartDate))
                OverlapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
}




int main()
{
    cout << "Read Period 1 : ";
    sPeriod Period1 = ReadAllPeriod();
    cout << "\nRead Period 2 : ";
    sPeriod Period2 = ReadAllPeriod();
    cout << "\nOverlap Days Count is: " << CountOverlapDays(Period1, Period2) << "\n";
}