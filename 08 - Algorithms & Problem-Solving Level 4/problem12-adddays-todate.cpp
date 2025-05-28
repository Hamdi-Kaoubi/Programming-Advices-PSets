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
    cout << "\nPlease enter a year : ";
    cin >> year;
    return year;
}
short ReadMonth()
{
    short month;
    cout << "\nPlease enter a month : ";
    cin >> month;
    return month;
}
short ReadDay()
{
    short day;
    cout << "Please enter a day : ";
    cin >> day;
    return day;
}
short ReadDaysToAdd()
{
    short daysToAdd;
    cout << "\nHow many days to ad ? ";
    cin >> daysToAdd;
    return daysToAdd;
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


sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + DaysFromBeginning(Date.Year, Date.Month, Date.Day);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = DaysInMonth(Date.Year, Date.Month);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}



int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();
    Date = DateAddDays(Days, Date);
    cout << "\nDate after adding [" << Days << "] days is : "
         << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
}

