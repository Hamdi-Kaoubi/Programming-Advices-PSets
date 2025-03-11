#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "MyLibrary.h"
using namespace std;

//Problem 1:
/*void FillThreeByThreeMatrix(int cols, int rows)
{
    printf("The following is 3x3 Random Matrix : \n");
    for (int i = 1; i <= rows; i++)
    {
        int* arr = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            *(arr + j) = MyEveryTimeFunctions::RandomNumber(1, 100);
            cout << setw(3) << *(arr + j) << "\t";
        }
        printf("\n");
        delete[] arr;
        arr = nullptr;
    }
}*/

//Problem 3 :
/*void GetSumOfEachRowInArray(int matrx[3][3], short rows, short cols, int arr[3])
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrx[i][j];
        }
        *(arr+i) = sum;
        sum = 0;
    }
}

void PrintSumOfEachRow(int arr[], short rows)
{
    for (short i = 0; i < rows; i++)
    {
        cout << "Row " << i +1 << " Sum = " << arr[i] << endl;
    }
}*/

//Problem 4 :
/*int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillThreeByThreeMatrix(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrx[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintThreeByThreeMatrix(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << matrx[i][j] << "\t";
        }
        cout << "\n";
    }
}

int ColSum(int matrx[3][3], short rows, short cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += matrx[i][cols];
    }
    return sum;
}

void SumMatrixColsInArray(int matrx[3][3], int arr[3], short rows, short cols)
{
    for (short j = 0; j < rows; j++)
    {
        arr[j] = ColSum(matrx, rows, j);
    }
}

void PrintColsSumArray(int arr[3], short cols)
{
    cout << "\nThe the following are the sum of each row in the matrix:\n";
        for (short j = 0; j < cols; j++)
        {
            cout << " Col " << j + 1 << " Sum = " << arr[j] << endl;
        }
}*/

//Problem 6 :
/*void FillThreeByThreeOrderedMatrix(int matrx[3][3], short rows, short cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            count++;
            matrx[i][j] = count;
        }
    }
}
void PrintThreeByThreeMatrix(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            std::cout << std::setw(3) << matrx[i][j] << "\t";
        }
        std::cout << "\n";
    }
}*/

//Problem 7 :
void FillThreeByThreeOrderedMatrix(int matrx[3][3], short rows, short cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            count++;
            matrx[i][j] = count;
        }
    }
}

void TransposeThreeByThreeOrderedMatrix(int matrx[3][3], int arr[3][3], short rows, short cols)
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = matrx[j][i];
        }
    }
}

void PrintThreeByThreeMatrix(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            std::cout << std::setw(3) << matrx[i][j] << "\t";
        }
        std::cout << "\n";
    }
}






int main()
{
    srand((unsigned)time(NULL));

    //Problem 1 :
    //FillThreeByThreeMatrix(3, 3);

    //Problem 3 :
    /*int matrx[3][3]; short rows = 3, cols = 3;
    MyEveryTimeFunctions::FillThreeByThreeMatrix(matrx, rows, cols);
    cout << "The following is 3x3 Random Matrix : \n";
    MyEveryTimeFunctions::PrintThreeByThreeMatrix(matrx, rows, cols);
    cout << "\n";
    int* arr = new int[3];
    GetSumOfEachRowInArray(matrx, rows, cols, arr);
    PrintSumOfEachRow(arr, rows);
    delete[] arr;
    arr = nullptr;*/

    //Problem 4 :
    /*int matrx[3][3], arr[3];
    FillThreeByThreeMatrix(matrx, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    SumMatrixColsInArray(matrx, arr, 3, 3);
    PrintColsSumArray(arr, 3);*/

    //Problem 6 :
    /*int matrx[3][3];
    FillThreeByThreeOrderedMatrix(matrx, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintThreeByThreeMatrix(matrx, 3, 3);*/

    //Problem 7 :
    int matrx[3][3];
    FillThreeByThreeOrderedMatrix(matrx, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    int arr[3][3];
    TransposeThreeByThreeOrderedMatrix(matrx,arr, 3, 3);
    cout << "\nThe following is a transposed matrix:\n";
    PrintThreeByThreeMatrix(arr, 3, 3);
}
