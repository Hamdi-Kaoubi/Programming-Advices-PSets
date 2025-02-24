#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Problem1:
/*void printTitle()
{
    cout << "\t\t\t" << "Multiplication Table from 1 to 10" << "\n\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n__________________________________________________________________________________\n";
}*/
/*string columnSuparator(int i)
{
    if (i < 10)
        return "    |";
    else
        return "   |";
}*/
/*void multiplicationTable()
{
    printTitle();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << columnSuparator(i) << "\t";
        for(int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}*/

//Problem 2:
/*int readNumber()
{
    int num;
    cout << "enter number: ";
    cin >> num;
    return num;
}*/
/*bool check(int n)
{
    return (n != 2 and n % 2 == 0) or (n != 3 and n % 3 == 0) or (n != 5 and n % 5 == 0);
}*/
/*void printPrime(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (!check(i))
            cout << i << endl;
    }
}*/

//Problem 3:
/*int readPerfect()
{
    int perf;
    cout << "enter number: ";
    cin >> perf;
    return perf;
}*/
/*int checkPerfection(int perf)
{
    int sum = 0;
    for (int i = 1; i < perf; i++)
    {
        if (perf % i == 0)
            sum += i;
    }
    return sum;
}*/
/*void printPerfect(int perf)
{
    if (checkPerfection(perf) == perf)
        cout << perf << " is Perfect" << endl;
    else
        cout << perf << " is Not Perfect" << endl;
}*/

//Problem 4:
/*int readNumber()
{
    int num;
    cout << "enter number: ";
    cin >> num;
    return num;
}*/
/*bool getPerfect(int num)
{
    int sum = 0;
        for (int j = 1; j < num; j++)
        {
            if(num % j == 0)
                sum += j;
        }
        return num == sum;
}*/
/*void printPerfect(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (getPerfect(i))
            cout << i << endl;
    }
}*/

//Problem 5:
/*int readNumber(string message)
{
    int num;
    cout << message;
    cin >> num;
    while (num <= 9)
    {
        cout << message;
        cin >> num;
    }
    return num;
}*/
/*string convertNumberToString(int num)
{
    return to_string(num);
}*/
/*void printStringElementsInversed(string s)
{
    for (int i = s.length(); i > 0; i--)
    {
        cout << i << endl;
    }
}*/

//Problem 5 abu hadhoud solution:
/*int readPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}*/
/*void printDigits(int num)
{
    int remainder = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        cout << remainder << endl;
    }
}*/

//Problem 6:
/*int readPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}*/
/*void printDigits(int num)
{
    int remainder = 0;
    int sum = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        sum += remainder;
    }
    cout << sum << endl;
}*/

//Problem 7:
/*int readPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}*/
/*int ReversedDigits(int num)
{
    int remainder = 0;
    int sum = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        sum = sum * 10 + remainder;
    }
    return sum;
}*/

//problem 8:
/*void readNumberAndDigit(int& num, int& dig)
{
    do
    {
        cout << "enter a positive number: ";
        cin >> num;
        cout << "enter just one digit: ";
        cin >> dig;
    } while (num <= 0 or dig > 9);
}*/
/*int DigitFrequency(int num, int dig)
{
    int remainder = 0;
    int frequency = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        if (remainder == dig)
            frequency++;
    }
    return frequency;
}*/

//Problem 9:
/*int readPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}*/
/*int countDigitFrequency(short digit, int num)
{
    int remainder = 0;
    int frequency = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        if (remainder == digit)
            frequency++;
    }
    return frequency;
}*/
/*void printDigitFrequency(int num)
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        short digitfrequency = 0;
        digitfrequency = countDigitFrequency(i, num);
        if (digitfrequency > 0)
        {
            cout << "digit " << i << " frequency is "
                << digitfrequency << " Time(s)." << endl;
        }
    }
}*/

//Problem 10:
/*int readPositiveNumber(string message)
{
    int num = 0;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}*/
/*int ReversedDigits(int num)
{
    int remainder = 0;
    int sum = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        sum = sum * 10 + remainder;
    }
    return sum;
}*/
/*void printDigits(int num)
{
    int remainder = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        cout << remainder << endl;
    }
}*/


int main()
{
    //Problem 1:
    /*multiplicationTable();*/

    //Problem 2:
    /*printPrime(readNumber());*/

    //Problem 3:
    //printPerfect(readPerfect());

    //Problem 4:
    /*printPerfect(readNumber());*/

    //Problem 5:
    /*string message = "enter a number has two or more digits: ";
    printStringElementsInversed(convertNumberToString(readNumber(message)));*/

    //Problem 5 abu hadhoud solution:
    /*printDigits(readPositiveNumber("Please enter a positive number: "));*/

    //Problem 6:
    /*printDigits(readPositiveNumber("Please enter a positive number: "));*/

    //Problem 7
    /*cout <<  "Reversed number of N is: ";
    cout << ReversedDigits(readPositiveNumber("Please enter a positive number: "));
    cout << endl;*/

    //Problem 8:
    /*int num, dig;
    readNumberAndDigit(num, dig);
    cout << "\n digit " << dig << " Frequency is " << DigitFrequency(num, dig) << " Times" << endl;*/

    //Problem 9:
    /*int num = readPositiveNumber("Enter a positive number: ");
    printDigitFrequency(num);*/

    //Problem 10:
    /*printDigits(ReversedDigits(readPositiveNumber("enter positive number please: "))); */
}

