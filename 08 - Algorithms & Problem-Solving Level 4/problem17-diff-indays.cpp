#include <iostream>
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

int GetDifference(sDate Date1, sDate Date2, bool IncludeEndDay=false)
{
    int DaysOfYear = 0, DaysOfYearsBetween = 0, DaysFromDate1 = 0, DaysFromDate2 = 0;
    if (IsLessThan(Date1, Date2))
    {
        DaysFromDate1 = DaysFromBeginning(Date1.Year, Date1.Month, Date1.Day);
        while (Date1.Year < Date2.Year)
        {
            if (CheckLeap(Date1.Year))
            {
                DaysOfYear = 366;
            }
            else
            {
                DaysOfYear = 365;
            }
            DaysOfYearsBetween += DaysOfYear;
            Date1.Year++;
        }
        DaysFromDate2 = DaysFromBeginning(Date2.Year, Date2.Month, Date2.Day) + DaysOfYearsBetween;
    }
    return (IncludeEndDay) ? (DaysFromDate2 - DaysFromDate1) + 1 : DaysFromDate2 - DaysFromDate1;
}

//Mr Abu Hadhoud solution :
/*bool IsLastDayInMonth(sDate Date)
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
}*/




int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    cout << "\nDifference is : " << GetDifference(Date1, Date2) << " Day(s).\n";
    cout << "Difference (including end day) is : " << GetDifference(Date1, Date2, true) << " Day(s).\n";
    //Mr abu hadhoud solution :
    /*cout << "\nDifference is : " << GetDifferenceInDays(Date1, Date2) << " Day(s).\n";
    cout << "Difference (including end day) is : " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).\n";*/
}
