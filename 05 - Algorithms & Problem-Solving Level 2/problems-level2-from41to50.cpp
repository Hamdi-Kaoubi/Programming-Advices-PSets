#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//Problem 41: is palindrome array
//void FillArray(int arr[100], int& size)
//{
//    cout << "enter number of elements: ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        cout << "enter element : ";
//        cin >> arr[i];
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//}
//bool IsPalindromeArray(int arr[100], int Length)
//{
//    for (int i = 0; i < Length; i++)
//    {
//        if (arr[i] != arr[Length - i - 1])
//        {
//            return false;
//        }
//    };
//    return true;
//}
//void CheckPalindrome(int arr[100], int size)
//{
//        if (IsPalindromeArray(arr, size))
//            cout << "\nYes array is Palindrome\n";
//        else
//            cout << "\nNo array is Not Palindrome\n";
//}

//Problem 42: count odd numbers in array
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArray(int arr[100], int& size)
//{
//    cout << "\nenter number of elements: ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(1, 100);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//}
//int OddNumbersInArray(int arr[100], int size)
//{
//    int count = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] % 2 != 0)
//            count++;
//    }
//    return count;
//}

//Problem 43:
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArray(int arr[100], int& size)
//{
//    cout << "\nenter number of elements: ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(1, 100);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//}
//int EvenNumbersInArray(int arr[100], int size)
//{
//    int count = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] % 2 == 0)
//            count++;
//    }
//    return count;
//}

//Problem 44: count positive numbers in array:
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArray(int arr[100], int& size)
//{
//    cout << "\nenter number of elements: ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(-100, 100);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//}
//int PositiveNumbersInArray(int arr[100], int size)
//{
//    int count = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] > 0)
//            count++;
//    }
//    return count;
//}

//Problem 45: count negative numbers in array:
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArray(int arr[100], int& size)
//{
//    cout << "\nenter number of elements: ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(-100, 100);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
//}
//int NegativeNumbersInArray(int arr[100], int size)
//{
//    int count = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] < 0)
//            count++;
//    }
//    return count;
//}

//Problem 46: Absolute of number:
//int ReadNumber(string message)
//{
//    int Number;
//    cout << message;
//    cin >> Number;
//    return Number;
//}
//int absoluteOfNumber(int number)
//{
//    if (number < 0)
//        return number * -1;
//    else
//        return number;
//}
//void PrintAbsolute(int number)
//{
//    cout << "\nMy abs Result : " << absoluteOfNumber(number) << "\n"; 
//    cout << "\n C++ abs Result : " << abs(number) << "\n";
//}

//Problem 47: round of a number:
//float ReadNumber()
//{
//    float Number;
//    cout << "Enter a number : ";
//    cin >> Number;
//    return Number;
//}
//float GetFractionPart(float number)
//{
//    return number - int(number);
//}
//int RoundNumber(float number)
//{
//    int IntPart;
//    IntPart = int(number);
//    float FractionPart = GetFractionPart(number);
//    if (abs(FractionPart) >= .5)
//    {
//        if (number > 0)
//            return ++IntPart;
//        else
//            return --IntPart;
//    }
//    else
//        return IntPart;
//
//}
//void PrintRound(float number)
//{
//    cout << "\nMy Round Result : " << RoundNumber(number) << "\n"; 
//    cout << "\n C++ Round Result : " << round(number) << "\n";
//}

//Problem 48: floor of number
//float ReadNumber()
//{
//    float Number;
//    cout << "Enter a number : ";
//    cin >> Number;
//    return Number;
//}
//int FloorNumber(float number)
//{
//    if (number > 0)
//        return int(number);
//    else
//        return int(number) - 1;
//}
//void PrintFloor(float number)
//{
//    cout << "\nMy Floor Result : " << FloorNumber(number) << "\n"; 
//    cout << "\n C++ Floor Result : " << floor(number) << "\n";
//}

//Problem 49: ceil of number
//float ReadNumber()
//{
//    float Number;
//    cout << "Enter a number : ";
//    cin >> Number;
//    return Number;
//}
//int CeilNumber(float number)
//{
//    if (number > 0)
//        return int(number)+1;
//    else
//        return int(number);
//}
//void PrintCeil(float number)
//{
//    cout << "\nMy Ceil Result : " << CeilNumber(number) << "\n";
//    cout << "\n C++ Ceil Result : " << ceil(number) << "\n";
//}

//Problem 50: square route of number
//float ReadNumber()
//{
//    int Number;
//    cout << "Enter a number : ";
//    cin >> Number;
//    return Number;
//}
//float SqrtNumber(float number)
//{
//    return pow(number, 0.5);
//}
//void PrintSqrt(float number)
//{
//    cout << "\nMy Sqrt Result : " << SqrtNumber(number) << "\n";
//    cout << "\n C++ Sqrt Result : " << sqrt(number) << "\n";
//}



int main()
{
    srand((unsigned)time(NULL));

    //Problem 41: is palindrome array
    /*int arr[100], size;
    FillArray(arr, size);
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    CheckPalindrome(arr, size);*/

    //Problem 42: count odd numbers in array
    /*int arr[100], size;
    FillArray(arr, size);
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    cout << "\nOdd numbers count is : ";
    cout << OddNumbersInArray(arr, size) << "\n";*/

    //Problem 43:
    /*int arr[100], size;
    FillArray(arr, size);
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    cout << "\nOdd numbers count is : ";
    cout << EvenNumbersInArray(arr, size) << "\n";*/

    //Problem 44:
    /*int arr[100], size;
    FillArray(arr, size);
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    cout << "\nOdd numbers count is : ";
    cout << PositiveNumbersInArray(arr, size) << "\n";*/

    //Problem 45:
    /*int arr[100], size;
    FillArray(arr, size);
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    cout << "\nOdd numbers count is : ";
    cout << NegativeNumbersInArray(arr, size) << "\n";*/

    //Problem 46:
    /*int num = ReadNumber("Enter a number : ");
    PrintAbsolute(num);*/

    //Problem 47:
    /*float num = ReadNumber();
    PrintRound(num);*/

    //Problem 48:
    /*float num = ReadNumber();
    PrintFloor(num);*/

    //Problem 49:
    /*float num = ReadNumber();
    PrintCeil(num);*/

    //Problem 50:
    /*float num = ReadNumber();
    PrintSqrt(num);*/
}

