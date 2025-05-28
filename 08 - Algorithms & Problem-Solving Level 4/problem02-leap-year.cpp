#include <iostream>
using namespace std;

int ReadYear()
{
    int year;
    cout << "enter a year : ";
    cin >> year;
    return year;
}

bool CheckLeap(int year)
{
    return (year % 400 == 0 or (year % 100 != 0 and year % 4 == 0));
}


int main()
{
    int Year = ReadYear();
    if (CheckLeap(Year))
        cout << "Yes, Year [" << Year << "] is a Leap Year.\n";
    else
        cout << "No, Year [" << Year << "] is NOT a Leap Year.\n";
}

