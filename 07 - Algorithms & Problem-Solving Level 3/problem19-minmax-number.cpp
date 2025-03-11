#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void PrintThreeByThreeMatrix(int matrx[][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3);
            printf("%d\t", matrx[i][j]);
        }
        cout << "\n";
    }
}

int GetMaxOfMatrix(int matrx[][3], short rows, short cols)
{
    int Max = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][j] > Max)
                Max = matrx[i][j];
        }
    }
    return Max;
}

int GetMinOfMatrix(int matrx[][3], short rows, short cols)
{
    int Min = GetMaxOfMatrix(matrx, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][j] < Min)
                Min = matrx[i][j];
        }
    }
    return Min;
}





int main()
{
    int matrx[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    cout << "\nMin Number is : " << GetMinOfMatrix(matrx, 3, 3) << "\n";
    cout << "\nMax Number is : " << GetMaxOfMatrix(matrx, 3, 3) << "\n";
}

