#include <iostream>
using namespace std;

enum enCompareDates { before = -1, equal = 0, after = 1 };
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

int main()
{
    cout << "Enter Date 1 : ";
    sDate Date1 = ReadFullDate();
    cout << "\nEnter Date 2 : ";
    sDate Date2 = ReadFullDate();
    cout << "\nCompare Result = " << CompareDates(Date1, Date2) << "\n";
}