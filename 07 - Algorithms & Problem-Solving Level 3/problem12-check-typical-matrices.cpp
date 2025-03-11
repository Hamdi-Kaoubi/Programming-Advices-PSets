#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
void FillThreeByThreeMatrixRandomly(int matrx[][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrx[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintThreeByThreeMatrix(int matrx[][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3);
            printf("%02d\t", matrx[i][j]);
        }
        cout << "\n";
    }
}
bool CheckTypicalMatrices(int matrx1[][3], int matrx2[][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx1[i][j] == matrx2[i][j])
                return false;
        }
    }
    return true;
}
void PrintComparedMatrices(bool comparedMatrices)
{
    if (comparedMatrices)
        cout << "\nYes, Matrices are Typical\n";
    else
        cout << "\nNo, Matrices are NOT Typical\n";
}


int main()
{
    srand((unsigned)time(NULL));

    int matrx1[3][3], matrx2[3][3];

    cout << "\nMatrix 1: \n";
    FillThreeByThreeMatrixRandomly(matrx1, 3, 3);
    PrintThreeByThreeMatrix(matrx1, 3, 3);

    cout << "\nMatrix 2: \n";
    FillThreeByThreeMatrixRandomly(matrx2, 3, 3);
    PrintThreeByThreeMatrix(matrx2, 3, 3);

    PrintComparedMatrices(CheckTypicalMatrices(matrx1, matrx2, 3, 3));
}

