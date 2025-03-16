#include <iostream>
using namespace std;

struct stDaysHrsMinsSecs
{
    int days;
    int hours;
    int munites;
    int seconds;
};

int ReadYear()
{
    int year;
    cout << "enter a year : ";
    cin >> year;
    return year;
}

bool CheckLeap(int year)
{
    return (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0);
}

stDaysHrsMinsSecs FillYear(int Year)
{
    stDaysHrsMinsSecs DaysHoursMinutesSeconds;
    
    (CheckLeap(Year)) ? DaysHoursMinutesSeconds.days = 366 : DaysHoursMinutesSeconds.days = 365;
 
    DaysHoursMinutesSeconds.hours = DaysHoursMinutesSeconds.days * 24;
    DaysHoursMinutesSeconds.munites = DaysHoursMinutesSeconds.hours * 60;
    DaysHoursMinutesSeconds.seconds = DaysHoursMinutesSeconds.munites * 60;
    
    return DaysHoursMinutesSeconds;
}




int main()
{
    int Year = ReadYear();
    stDaysHrsMinsSecs DaysHoursMinutesSeconds = FillYear(Year);
    cout << "\nNumber of days    in year [" << Year << "] is " << DaysHoursMinutesSeconds.days << "\n";
    cout << "Number of hours   in year [" << Year << "] is " << DaysHoursMinutesSeconds.hours << "\n";
    cout << "Number of munites in year [" << Year << "] is " << DaysHoursMinutesSeconds.munites << "\n";
    cout << "Number of seconds in year [" << Year << "] is " << DaysHoursMinutesSeconds.seconds << "\n";
}

