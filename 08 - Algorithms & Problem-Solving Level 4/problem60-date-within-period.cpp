#include <iostream>
using namespace std;

enum enCompareDates { before = -1, equal = 0, after = 1 };
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
enCompareDates CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDates::before;
    else if (IsDate1AfterDate2(Date1, Date2))
        return enCompareDates::after;
    else
        return enCompareDates::equal;
}

bool IsDateWithinPeriod(sPeriod Period, sDate Date)
{
    return (CompareDates(Period.StartDate, Date) == enCompareDates::before) and
        (CompareDates(Period.EndDate, Date) == enCompareDates::after);
}


int main()
{
    cout << "Read Period : ";
    sPeriod Period = ReadAllPeriod();
    cout << "\nEnter Date to check : ";
    sDate Date = ReadFullDate();
    if (IsDateWithinPeriod)
        cout << "\nYes, Date is within Period.\n";
    else
        cout << "\nNo, Date isn't within Period.\n";
}