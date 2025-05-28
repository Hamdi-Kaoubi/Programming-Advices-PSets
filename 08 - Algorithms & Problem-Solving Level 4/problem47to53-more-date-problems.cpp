#pragma warning (disable : 4996)
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//My Stupid Solution :

//struct sDate
//{
//    short Day;
//    short Month;
//    short Year;
//};
//short ReadYear()
//{
//    short year;
//    cout << "Please enter a year : ";
//    cin >> year;
//    return year;
//}
//short ReadMonth()
//{
//    short month;
//    cout << "Please enter a month : ";
//    cin >> month;
//    return month;
//}
//short ReadDay()
//{
//    short day;
//    cout << "\nPlease enter a day : ";
//    cin >> day;
//    return day;
//}
//sDate ReadFullDate()
//{
//    sDate Date;
//    Date.Day = ReadDay();
//    Date.Month = ReadMonth();
//    Date.Year = ReadYear();
//    return Date;
//}

//bool CheckLeap(short year)
//{
//    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
//}
//short DaysInMonth(short year, short month)
//{
//    if (month < 1 or month > 12)
//        return 0;
//    short DaysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    return (month == 2) ? (CheckLeap(year) ? 29 : 28) : DaysOfMonth[month - 1];
//}
//short DaysFromBeginning(short year, short month, short day)
//{
//    short FromBeginning = 0;
//    for (short i = 1; i < month; i++)
//    {
//        FromBeginning += DaysInMonth(year, i);
//    }
//    FromBeginning += day;
//    return FromBeginning;
//}

//short DayOrder(short year, short month, short day)
//{
//    short a = (14 - month) / 12;
//    short y = year - a;
//    short m = month + 12 * a - 2;
//    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//short DayOrder(sDate Date)
//{
//    short a = (14 - Date.Month) / 12;
//    short y = Date.Year - a;
//    short m = Date.Month + 12 * a - 2;
//    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//string DayShortName(short DayOfWeekOrder)
//{
//    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//    return arrDayNames[DayOfWeekOrder];
//}

//void PrintDayDate(sDate Date, short DayOrder)
//{
//    cout << "\nToday is " << DayShortName(DayOrder) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
//}

//bool IsEndOfWeek(short DayOrder)
//{
//    return DayOrder == 6;
//}
//bool IsWeekEnd(short DayOrder)
//{
//    return (DayOrder == 5) or (DayOrder == 6);
//}
//bool IsBusiness(short DayOrder)
//{
//    return (DayOrder != 5) and (DayOrder != 6);
//}
//short DaysUntilEndOfWeek(short DayOrder)
//{
//    return 6 - DayOrder;
//}
//short DaysUntilEndOfMonth(sDate Date, short day, bool EncludeEndDay=false)
//{
//    return EncludeEndDay ? DaysInMonth(Date.Year, Date.Month) - day + 1 : DaysInMonth(Date.Year, Date.Month) - day;
//}
//short DaysUntilEndOfYear(sDate Date, bool EncludeEndDay = false)
//{
//    short DaysOfYear = 0;
//    short DaysFromBeginningOfYear = DaysFromBeginning(Date.Year, Date.Month, Date.Day);
//    CheckLeap ? DaysOfYear = 366 : DaysOfYear = 365;
//    return EncludeEndDay ? DaysOfYear - DaysFromBeginningOfYear + 1 : DaysOfYear - DaysFromBeginningOfYear;
//}

//Mr Abu Hadhoud Solution :
struct sDate
{
    short Day;
    short Month;
    short Year;
};
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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
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
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}
sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

bool IsEndOfWeek(sDate Date)
{
    return DayOrder(Date) == 6;
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
short DaysUntilEndOfWeek(sDate Date)
{
    return 6 - DayOrder(Date);
}
short DaysUntilEndOfMonth(sDate Date)
{
    sDate EndOfMonthDate;
    EndOfMonthDate.Day = DaysInMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}
short DaysUntilEndOfYear(sDate Date)
{
    sDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfYearDate, true);
}



int main()
{
    //My Stupid Solution :
    /*sDate Date = ReadFullDate();
    short dayOrder = DayOrder(Date);
    PrintDayDate(Date, dayOrder);
    cout << "\nIs it end of week ?\n";
    if (IsEndOfWeek(dayOrder))
        cout << "Yes, it is end of week.\n";
    else
        cout << "No, it is NOT end of week.\n";
    cout<< "\nIs it week end?\n";
    if (IsWeekEnd(dayOrder))
        cout << "Yes, it is week end.\n";
    else
        cout << "No, it is NOT week end.\n";
    cout << "\nIs it business day ?\n";
    if (IsBusiness(dayOrder))
        cout << "Yes, it is business day.\n";
    else
        cout << "No, it is NOT business day.\n";
    cout << "\nDays until end of week : " << DaysUntilEndOfWeek(dayOrder) << " Day(s).";
    cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date, Date.Day, true) << " Day(s).";
    cout << "\nDays until end of year : " << DaysUntilEndOfYear(Date) << " Day(s).\n";*/

    //Mr Abu Hadhoud Solution :
    sDate Date = GetSystemDate();
    cout << "\nToday is " << DayShortName(DayOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    //------------------------------
    cout << "\n\nIs it End of Week?\n";
    if(IsEndOfWeek(Date))
        cout << "Yes it is end of Week.";
    else
        cout << "No it's Not end of week.";
    //------------------------------
    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(Date))
        cout << "Yes it is a week end.";
    else
        cout << "No today is " << DayShortName(DayOrder(Date)) << ", Not a weekend.";
    //------------------------------
    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(Date))
        cout << "Yes it is a business day.";
    else
        cout << "No it is NOT a business day.";
    //------------------------------
    cout << "\n\nDays until end of week : " << DaysUntilEndOfWeek(Date) << " Day(s).";
    //------------------------------
    cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date) << " Day(s).";
    //------------------------------
    cout << "\nDays until end of year : " << DaysUntilEndOfYear(Date) << " Day(s).\n";
    //------------------------------
}
