#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Problem 21:
/*enum letters { small = 1, capital = 2, special = 3, digit = 4 };
int ReadNumberOfKeys(string message)
{
    int keysNumber;
    cout << message;
    cin >> keysNumber;
    return keysNumber;
}*/
/*int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}*/
/*char GetRandomCharacter(letters charType)
{
    switch (charType)
    {
    case letters::small:
        return char(RandomNumber(97, 122));
        break;
    case letters::capital:
        return char(RandomNumber(65, 90));
        break;
    case letters::special:
        return char(RandomNumber(33, 47));
        break;
    case letters::digit:
        return char(RandomNumber(48, 57));
        break;
    default:
        break;
    }
}*/
/*string GenerateWord(letters charType, short length)
{
    string characters = "";
    for (int i = 1; i <= length; i++)
    {
        characters += GetRandomCharacter(charType);
    }
    return characters;
}*/
/*string GenerateKey()
{
    string Key = "";
    Key = Key + GenerateWord(letters::capital, 4) + "-";
    Key = Key + GenerateWord(letters::capital, 4) + "-";
    Key = Key + GenerateWord(letters::capital, 4) + "-";
    Key = Key + GenerateWord(letters::capital, 4);
    return Key;
}*/
/*void GenerateKeys(int key)
{
    for (int i = 1; i <= key; i++)
    {
        cout << "Key[" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}*/

//Problem 22:
/*int ReadNumber(string message)
{
    int Number;
    cout << message;
    cin >> Number;
    return Number;
}*/
/*void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter the number of elements: \n";
    cin >> arrLength;
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element[" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}*/
/*void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}*/
/*int CheckRepetetions(int arr[100], int arrLength, int check)
{
    int repetetions = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == check)
            repetetions++;
    }
    return repetetions;
}*/

//Problem 23/24/25/26/27:
/*int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}*/
/*void FillArrayWithRandom(int arr[100], int& arrLength)
{
    cout << "\nEnter the number of elements: \n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}*/
/*void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}*/
/*int GetMaxOfArray(int arr[100], int arrLength)
{
    int max = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}*/
/*int GetMinOfArray(int arr[100], int arrLength)
{
    int min = 0;
    min = arr[0];
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}*/
/*int GetSumOfArray(int arr[100], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}*/
/*float GetAverageOfArray(int arr[100], int arrLength)
{
    return (float) GetSumOfArray(arr, arrLength) / arrLength;
}*/

//Problem 28/29:
/*int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}*/
/*void FillArrayWithRandom(int arr[100], int& arrLength)
{
    cout << "\nEnter the number of elements: \n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}*/
/*void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}*/
/*void FillCopyOfArray(int arr[100], int copy[100], int arrLenth)
{
    for (int i = 0; i < arrLenth; i++)
    {
        copy[i] = arr[i];
    }
}*/
/*bool CheckPrime(int number)
{
    bool result = true;
    int M = round(number / 2);
    for (int counter = 2; counter <= M; counter++)
    {
        if (number % counter == 0)
            result = false;
    }
    return result;
}*/
/*void FillCopyOfPrimeNumbersArray(int arr[100], int copy2[100], int arrLenth, int& arr2Length)
{
    int counter = 0;
    for (int i = 0; i < arrLenth; i++)
    {
        if (CheckPrime(arr[i]))
        {
            copy2[counter] = arr[i];
            counter++;
        }
    }
    arr2Length = --counter;
}*/

//Problem 30:
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandom(int arr[100], int& arrLength)
{
    cout << "\nEnter the number of elements: \n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void SumArrays(int arrSum[100], int arr1[100], int arr2[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    //Problem 21:
    /*GenerateKeys(ReadNumberOfKeys("Enter a positive number : "));*/

    //Problem 22:
    /*int arr[100], arrLength, numberToCheck;
    ReadArray(arr, arrLength);
    numberToCheck = ReadNumber("Enter the number you want to check : ");
    cout << "\nOriginal array :";
    PrintArray(arr, arrLength);
    cout << "\nNumber " << numberToCheck;
    cout << " is repeated " << CheckRepetetions(arr, arrLength, numberToCheck);
    cout << " time(s).\n";*/

    //Problem 23/24/25/26/27:
    /*int arr[100], arrLength;
    FillArrayWithRandom(arr, arrLength);
    cout << "\nArray Elements : ";
    PrintArray(arr, arrLength);
    cout << "\nMax number is : " << GetMaxOfArray(arr, arrLength) << endl;
    cout << "\nMin number is : " << GetMinOfArray(arr, arrLength) << endl;
    cout << "\nSum of all numbers is : " << GetSumOfArray(arr, arrLength) << endl;
    cout << "\nAverage of all numbers is : " << GetAverageOfArray(arr, arrLength) << endl;*/

    //Problem 28/29:
    /*int arr[100], arrLength;
    FillArrayWithRandom(arr, arrLength);
    int copy[100], copy2[100], copy2Length=0;
    FillCopyOfArray(arr, copy, arrLength);
    FillCopyOfPrimeNumbersArray(arr, copy2, arrLength, copy2Length);
    cout << "\nArray 1 Elements : ";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Elements after copy : ";
    PrintArray(copy, arrLength);
    cout << "\nPrime numbers of array 2 : ";
    PrintArray(copy2, copy2Length);*/

    //Problem 30:
    int arr1[100], arr2[100], arrLength;
    FillArrayWithRandom(arr1, arrLength);
    FillArrayWithRandom(arr2, arrLength);
    cout << "\nArray 1 Elements : ";
    PrintArray(arr1, arrLength);
    cout << "\nArray 2 Elements : ";
    PrintArray(arr2, arrLength);
    int arrSum[100];
    SumArrays(arrSum, arr1, arr2, arrLength);
    cout << "\nSum Of Array1 And Array2 Elements : ";
    PrintArray(arrSum, arrLength);
}


