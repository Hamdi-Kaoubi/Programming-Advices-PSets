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
sDate ReadStartDate()
{
    sDate StartDate;
    cout << "\nEnter Start Date : \n";
    StartDate.Day = ReadDay();
    StartDate.Month = ReadMonth();
    StartDate.Year = ReadYear();
    return StartDate;
}
sDate ReadEndDate()
{
    sDate EndDate;
    cout << "\nEnter End Date : \n";
    EndDate.Day = ReadDay();
    EndDate.Month = ReadMonth();
    EndDate.Year = ReadYear();
    return EndDate;
}
sPeriod ReadAllPeriod()
{
    sPeriod Period;
    Period.StartDate = ReadStartDate();
    Period.EndDate = ReadEndDate();
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

//My Solution :
bool IsOverlap(sPeriod Period1, sPeriod Period2)
{
    return IsDate1AfterDate2(Period1.EndDate, Period2.StartDate);
}

//Mr Abu Hadhoud Solution :
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


int main()
{
    //My Solution :
    cout << "Read Period 1 : ";
    sPeriod Period1 = ReadAllPeriod();
    cout << "\nRead Period 2 : ";
    sPeriod Period2 = ReadAllPeriod();
    /*if (IsOverlap(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNO, Periods do NOT Overlap\n";*/

    //Mr Abu Hadhoud Solution :
    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNO, Periods do NOT Overlap\n";
}