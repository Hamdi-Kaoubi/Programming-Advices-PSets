#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
void FillThreeByThreeMatrixRandomly(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrx[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintThreeByThreeMatrix(int matrx[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3);
            printf("%0*d", 2, matrx[i][j]);
            cout << "\t";
        }
        cout << "\n";
    }
}
void TransposeThreeByThreeMatrix(int matrx[3][3], int matrxDestination[3][3], short rows, short cols)
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrxDestination[i][j] = matrx[j][i];
        }
    }
}
void GetRowsOrColsOfMiddleMatrix(int matrx[3][3], int arr[3], short rows)
{
    for (short i = 0; i < rows; i++)
    {
            arr[i] = matrx[(int)rows/2][i];
    }
}
void PrintArrayElements(int arr[3], short rows)
{
    for (short i = 0; i < rows; i++)
    {
        cout << setw(3); 
        printf("%0*d",2, arr[i]);
        cout << "\t";
    }
    cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

    int matrx1[3][3], matrx2[3][3], rowsArray[3], colsArray[3];

    FillThreeByThreeMatrixRandomly(matrx1, 3, 3);
    cout << "Matrix 1 : \n";
    PrintThreeByThreeMatrix(matrx1, 3, 3);
    
    GetRowsOrColsOfMiddleMatrix(matrx1, rowsArray, 3);
    cout << "\nMiddle rows of Matrix is : \n";
    PrintArrayElements(rowsArray, 3);

    TransposeThreeByThreeMatrix(matrx1, matrx2, 3, 3);
    GetRowsOrColsOfMiddleMatrix(matrx2, colsArray, 3);
    cout << "\nMiddle cols of Matrix is : \n";
    PrintArrayElements(colsArray, 3);
}

