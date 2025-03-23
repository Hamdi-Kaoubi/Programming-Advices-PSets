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
short ReadVacationDays()
{
    short VacationDays;
    cout << "\nPlease enter vacation days : ";
    cin >> VacationDays;
    return VacationDays;
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
short DayOrder(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOrder(sDate Date)
{
    return DayOrder(Date.Year, Date.Month, Date.Day);
}
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}
bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == DaysInMonth(Date.Year, Date.Month));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
sDate IncreaseDateByOneDay(sDate Date)
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
bool IsWeekEnd(sDate Date)
{
    return DayOrder(Date) == 5 or DayOrder(Date) == 6;
}
bool IsBusinessDay(sDate Date)
{
    //Weekends are Sun,Mon,Tue,Wed and Thur
    /* short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex >= 5 && DayIndex <= 4);
    */
    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(Date);
}

sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
{
    short weekendCounter = 0;
    //in case the data is weekend keep adding one day until you reach business day
    //we get rid of all weekends before the business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    //here we increase the vacation days to add all weekends to it
    for (short i = 1; i <= VacationDays + weekendCounter; i++)
    {
        if (IsWeekEnd(DateFrom))
            weekendCounter++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    //in case return date is weekend keep adding one day until you reach business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DateFrom;
}




int main()
{
    cout << "\nVacation Starts: ";
    sDate DateFrom = ReadFullDate();

    short VacationDays = ReadVacationDays();

    sDate ReturnDate = CalculateVacationReturnDate(DateFrom, VacationDays);

    cout << "\n\nReturn Date: " << DayShortName(DayOrder(ReturnDate)) << " , "
        << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;
}