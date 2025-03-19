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

bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == DaysInMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short month)
{
    return month == 12;
}

//Adding One day :
sDate IncreaseDateByOneDay(sDate& Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

//Adding X days :
sDate IncreaseDateByXDays(sDate& Date, short XDays)
{
    for (short i = 1; i <= XDays; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

//Adding One week :
sDate IncreaseDateByOneWeek(sDate& Date)
{
    short week = 7;
    Date = IncreaseDateByXDays(Date, week);
    return Date;
}

//Adding X weeks :
sDate IncreaseDateByXWeeks(sDate& Date, short XWeeks)
{
    for (short i = 1; i <= XWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

//Adding One Month :
sDate IncreaseDateByOneMonth(sDate& Date)
{
    if (IsLastMonthInYear(Date.Month))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
        Date.Month++;
    return Date;
}

//Adding X months :
sDate IncreaseDateByXMonths(sDate& Date, short XMonths)
{
    for (short i = 1; i <= XMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

//Adding One Year :
sDate IncreaseDateByOneYear(sDate& Date)
{
    Date.Year++;
    return Date;
}

//Adding X Years slow :
sDate IncreaseDateByXYears(sDate& Date, short XYears)
{
    for (short i = 1; i <= XYears; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

//Adding X Years Faster :
sDate IncreaseDateByXYearsFaster(sDate& Date, short XYears)
{
    Date.Year += XYears;
    return Date;
}

//Adding One Decade :
sDate IncreaseDateByOneDecade(sDate& Date)
{
    short Decade = 10;
    Date = IncreaseDateByXYears(Date, Decade);
    return Date;
}

//Adding X Decades slow :
sDate IncreaseDateByXDecades(sDate& Date, short XDecades)
{
    for (short i = 1; i <= XDecades; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

//Adding X Decades fast :
sDate IncreaseDateByXDecadesFaster(sDate& Date, short XDecades)
{
    Date.Year += 10 * XDecades;
    return Date;
}

//Adding One Century :
sDate IncreaseDateByOneCentury(sDate& Date)
{
    short Century = 100;
    Date = IncreaseDateByXYears(Date, Century);
    return Date;
}

//Adding One Mellinium :
sDate IncreaseDateByOneMellinium(sDate& Date)
{
    short Mellinium = 1000;
    Date = IncreaseDateByXYears(Date, Mellinium);
    return Date;
}



int main()
{
    sDate Date = ReadFullDate();
    cout << "\nDate after :\n\n";
    cout << "01 - Adding one day is              : ";
    Date = IncreaseDateByOneDay(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "02 - Adding 10 days is              : ";
    Date = IncreaseDateByXDays(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "03 - Adding one week is             : ";
    Date = IncreaseDateByOneWeek(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "04 - Adding 10 weeks is             : ";
    Date = IncreaseDateByXWeeks(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "05 - Adding one month is            : ";
    Date = IncreaseDateByOneMonth(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "06 - Adding 10 months is            : ";
    Date = IncreaseDateByXMonths(Date, 5);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "07 - Adding one year is             : ";
    Date = IncreaseDateByOneYear(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "08 - Adding 10 years is             : ";
    Date = IncreaseDateByXYears(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "09 - Adding 10 years (faster) is    : ";
    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "10 - Adding one decade is           : ";
    Date = IncreaseDateByOneDecade(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "11 - Adding 10 decades is           : ";
    Date = IncreaseDateByXDecades(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "12 - Adding 10 decades (faster) is  : ";
    Date = IncreaseDateByXDecadesFaster(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "14 - Adding one century is          : ";
    Date = IncreaseDateByOneCentury(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "13 - Adding one mellinium is        : ";
    Date = IncreaseDateByOneMellinium(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
}
