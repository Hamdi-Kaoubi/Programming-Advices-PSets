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

bool IsFirstDayInMonth(sDate Date)
{
    return Date.Day == 1;
}
bool IsFirstMonthInYear(short month)
{
    return month == 1;
}

//decrease date by one day :
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

//decrease date by X days :
sDate DecreaseDateByXDays(sDate& Date, short XDays)
{
    for (short i = 1; i <= XDays; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

//decrease date by one week :
sDate DecreaseDateByOneWeek(sDate& Date)
{
    short week = 7;
    return DecreaseDateByXDays(Date, week);
}

//decrease date by X weeks :
sDate DecreaseDateByXWeeks(sDate& Date, short XWeeks)
{
    for (short i = 1; i <= XWeeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

//decrease date by one month :
sDate DecreaseDateByOneMonth(sDate& Date)
{
    if (IsFirstMonthInYear(Date.Month))
    {
        Date.Year--;
        Date.Month = 12;
    }
    else
        Date.Month--;
    return Date;
}

//decrease date by X months :
sDate DecreaseDateByXMonths(sDate& Date, short XMonths)
{
    for (short i = 1; i <= XMonths; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

//decrease date by one year :
sDate DecreaseDateByOneYear(sDate& Date)
{
    Date.Year--;
    return Date;
}

//decrease date by X years :
sDate DecreaseDateByXYears(sDate& Date, short XYears)
{
    for (short i = 1; i <= XYears; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

//decrease date by X years faster :
sDate DecreaseDateByXYearsFaster(sDate& Date, short XYears)
{
    Date.Year -= XYears;
    return Date;
}

//decrease date by one decade :
sDate DecreaseDateByOneDecade(sDate& Date)
{
    short decade = 10;
    return DecreaseDateByXYears(Date, decade);
}

//decrease date by X decades :
sDate DecreaseDateByXDecades(sDate& Date, short XDecades)
{
    for (short i = 1; i <= XDecades; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

//decrease date by X decades faster :
sDate DecreaseDateByXDecadesFaster(sDate& Date, short XDecades)
{
    Date.Year -= 10 * XDecades;
    return Date;
}

//decrease date by one century :
sDate DecreaseDateByOneCentury(sDate& Date)
{
    short century = 100;
    if (Date.Year > century)
        Date.Year -= century;
    return Date;
}

//decrease date by one millennium :
sDate DecreaseDateByOneMillennium(sDate& Date)
{
    short millennium = 1000;
    if (Date.Year > millennium)
        Date.Year -= millennium;
    return Date;
}





int main()
{
    sDate Date = ReadFullDate();
    cout << "\nDate After : \n\n";
    cout << "01-Substracting one day is             : ";
    Date = DecreaseDateByOneDay(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "02-Substracting 10 days is             : ";
    Date = DecreaseDateByXDays(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "03-Substracting one week is            : ";
    Date = DecreaseDateByOneWeek(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "04-Substracting 10 weeks is            : ";
    Date = DecreaseDateByXWeeks(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "05-Substracting one month is           : ";
    Date = DecreaseDateByOneMonth(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "06-Substracting 5 months is            : ";
    Date = DecreaseDateByXMonths(Date, 5);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "07-Substracting one year is            : ";
    Date = DecreaseDateByOneYear(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "08-Substracting 10 years is            : ";
    Date = DecreaseDateByXYears(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "09-Substracting 10 years (faster) is   : ";
    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "10-Substracting one decade is          : ";
    Date = DecreaseDateByOneDecade(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "11-Substracting 10 decades is          : ";
    Date = DecreaseDateByXDecades(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "12-Substracting 10 decades (faster) is : ";
    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "13-Substracting one century is         : ";
    Date = DecreaseDateByOneCentury(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    cout << "14-Substracting one millennium is      : ";
    Date = DecreaseDateByOneMillennium(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
}

