#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Problem 31:
/*int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}*/
/*void Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}*/
/*int ReadpositiveNumber(string message)
{
    int number;
    cout << "\n" << message;
    cin >> number;
    return number;
}*/
/*void FillArrayWithOrder(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}*/
/*void PrintArray(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}*/
/*void ShuffleArray(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        Swap(arr[RandomNumber(1, size) - 1], arr[RandomNumber(1, size) - 1]);
    }
}*/

//Problem 32:
//int ReadpositiveNumber(string message)
//{
//    int number;
//    cout << "\n" << message;
//    cin >> number;
//    return number;
//}
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArrayWithRandomNumbers(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(1, 100);
//    }
//}
//void ReverseArray(int arr[100], int arr2[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        arr2[i] = arr[size - 1 - i];
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}

//problem 33:
//enum letters { small = 1, capital = 2, special = 3, digit = 4 };
//int ReadNumberOfKeys(string message)
//{
//    int keysNumber;
//    cout << message;
//    cin >> keysNumber;
//    return keysNumber;
//}
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//char GetRandomCharacter(letters charType)
//{
//    switch (charType)
//    {
//    case letters::small:
//        return char(RandomNumber(97, 122));
//        break;
//    case letters::capital:
//        return char(RandomNumber(65, 90));
//        break;
//    case letters::special:
//        return char(RandomNumber(33, 47));
//        break;
//    case letters::digit:
//        return char(RandomNumber(48, 57));
//        break;
//    default:
//        break;
//    }
//}
//string GenerateWord(letters charType, short length)
//{
//    string characters = "";
//    for (int i = 1; i <= length; i++)
//    {
//        characters += GetRandomCharacter(charType);
//    }
//    return characters;
//}
//string GenerateKey()
//{
//    string Key = "";
//    Key = Key + GenerateWord(letters::capital, 4) + "-";
//    Key = Key + GenerateWord(letters::capital, 4) + "-";
//    Key = Key + GenerateWord(letters::capital, 4) + "-";
//    Key = Key + GenerateWord(letters::capital, 4);
//    return Key;
//}
//void FillArrayWithKeys(string arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = GenerateKey();
//    }
//}
//void PrintArray(string arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << "Array[" << i << "] : " << arr[i] << endl;
//    }
//}

//Problem 34/35:
//int ReadPositiveNumber(string message)
//{
//    int Number;
//    cout << message;
//    cin >> Number;
//    return Number;
//}
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArray(int arr[100], int& arrLength)
//{
//    cout << "\nEnter the number of elements: \n";
//    cin >> arrLength;
//    for (int i = 0; i < arrLength; i++)
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
//}
//int CheckRepetetions(int arr[100], int arrLength, int check)
//{
//    for (int i = 0; i < arrLength; i++)
//    {
//        if (arr[i] == check)
//            return i;
//    }
//    return -1;
//}
//bool VerifyRepetition(int arr[100], int arrLength, int check)
//{
//    return CheckRepetetions(arr, arrLength, check) != -1;
//}
//void PrintCheckIndexAndOrder(bool repetetion)
//{
//    if (repetetion)
//        cout << "\nYes, The number is found :-)" << endl;
//    else
//        cout << "\nNo, The number is not found :-( " << endl;
//}

//Problem 36:
//int ReadNumber()
//{
//    int Number;
//    cout << "\nEnter a number : ";
//    cin >> Number;
//    return Number;
//}
//void AddArrayElement(int number, int arr[100], int& size)
//{
//    size++;
//    arr[size - 1] = number;
//} 
//void InputUserNumbersInArray(int arr[100], int& size)
//{
//    bool AddMore = true;
//    do
//    {
//        AddArrayElement(ReadNumber(), arr, size);
//        cout << "\nDo You want to add more numbers ? [0]: No, [1]: Yes?";
//        cin >> AddMore;
//    } while (AddMore);
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}

//Problem 37/38:
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void FillArrayWithRandomNumbers(int arr[100], int& size)
//{
//    cout << "enter number of elements : ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(1, 100);
//    }
//}
//void AddArrayElement(int number, int arr[100], int& size)
//{
//    size++;
//    arr[size - 1] = number;
//}
//void CopyArrayWithAddElement(int source[100], int destination[100], int size1, int& size2)
//{
//    for (int i = 0; i < size1; i++)
//    {
//        if ((source[i] % 2) != 0)
//            AddArrayElement(source[i], destination, size2);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
// cout << "\n";
//}

//Problem 39: Copy Prime numbers to a new array : Using CheckPrime() and AddArayEelement() functions.
//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//void AddArrayElement(int number, int arr[100], int& size)
//{
//    size++;
//    arr[size - 1] = number;
//}
//void FillArrayWithRandomNumbers(int arr[100], int& size)
//{
//    cout << "enter number of elements : ";
//    cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = RandomNumber(1, 100);
//    }
//}
//bool CheckPrime(int number)
//{
//    bool result = true;
//    int M = round(number / 2);
//    for (int counter = 2; counter <= M; counter++)
//    {
//        if (number % counter == 0)
//            result = false;
//    }
//    return result;
//}
//void CopyArrayPrimeWithAddElement(int source[100], int destination[100], int size1, int& size2)
//{
//    for (int i = 0; i < size1; i++)
//    {
//        if (CheckPrime(source[i]))
//            AddArrayElement(source[i], destination, size2);
//    }
//}
//void PrintArray(int arr[100], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
// cout << "\n";
//}

//Problem 40: Copy Distinct numbers to Array :
void FillArray(int arr[100], int& size) //hard Coded
{
    size = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
} 
void PrintArray(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void AddArrayElement(int number, int arr[100], int& size)
{
    size++;
    arr[size - 1] = number;
}
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;//return the index
    }
    //if you reached here, this means the number is not found
    return -1;
}
bool IsNumberInArray(int number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(number, arr, arrLength) != -1;
}
void CopyDistinctNumbersToArray(int source[100], int destination[100], int size1, int& size2)
{
    for (int i = 0; i < size1; i++)
    {
        if(!IsNumberInArray(source[i], destination, size2))
            AddArrayElement(source[i], destination, size2);
    }
}




int main()
{
    srand((unsigned)time(NULL));

    //Problem 31:
    /*int arr[100],  size;
    size = ReadpositiveNumber("Enter a positive number please: ");
    FillArrayWithOrder(arr, size);
    cout << "\nArray Elements Before Shuffle : ";
    PrintArray(arr, size);
    ShuffleArray(arr, size);
    cout << "\nArray Elements After Shuffle : ";
    PrintArray(arr, size);*/

    //Problem 32:
    /*int arr[100], arr2[100], size;
    size = ReadpositiveNumber("Enter a positive number please: ");
    FillArrayWithRandomNumbers(arr, size);
    cout << "\nArray 1 Elements: \n";
    PrintArray(arr, size);
    ReverseArray(arr, arr2, size);
    cout << "\nArray 2 Elements After copying Array 1 in reversed order: \n";
    PrintArray(arr2, size);*/

    //Problem 33:
    /*int size;
    string arr[100];
    size = ReadNumberOfKeys("\nenter a positive number : ");
    FillArrayWithKeys(arr, size);
    cout << "\nArray elements : \n\n";
    PrintArray(arr, size);*/

    //Problem 34/35:
    /*int arr[100], arrLenth, check;
    FillArray(arr, arrLenth);
    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLenth);
    check = ReadPositiveNumber("\n\nPlease enter a number to search for : \n");
    cout << "\n Number You are looking for is : " << check << endl;
    PrintCheckIndexAndOrder(VerifyRepetition(arr, arrLenth, check));*/

    //Problem 36:
    /*int arr[100], size = 0;
    InputUserNumbersInArray(arr, size);
    cout << "\nArray length : " << size << endl;
    cout << "\nArray elements : ";
    PrintArray(arr, size);
    cout << "\n";*/

    //Problem 37/38:
    /*int arr[100], arrLength = 0, arr2Legth = 0;
    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    CopyArrayWithAddElement(arr, arr2, arrLength, arr2Legth);
    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements : ";
    PrintArray(arr2, arr2Legth);*/

    //Problem 39:
    /*int arr[100], arrLength = 0, arr2Legth = 0;
    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    CopyArrayPrimeWithAddElement(arr, arr2, arrLength, arr2Legth);
    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Prime numbers : ";
    PrintArray(arr2, arr2Legth); */

    //Problem 40:
    int arraySource[100], sourceLength = 0, arrayDestination[100], destinationLength = 0;
    FillArray(arraySource, sourceLength);
    cout << "\nArray 1 elements : ";
    PrintArray(arraySource, sourceLength);
    CopyDistinctNumbersToArray(arraySource, arrayDestination, sourceLength, destinationLength);
    cout << "\nArray 2 distinct elements : ";
    PrintArray(arrayDestination, destinationLength);
}
