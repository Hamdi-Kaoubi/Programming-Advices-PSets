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
            if (matrx[i][j] < 10)
                printf("0%d", matrx[i][j]);
            else
                printf("%d", matrx[i][j]);
            cout << "\t";
        }
        cout << "\n";
    }
}
void MultiplyTwoMatrices(int matrx1[3][3], int matrx2[3][3], int result[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrx1[i][j] * matrx2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int matrx1[3][3], matrx2[3][3], result[3][3];
    FillThreeByThreeMatrixRandomly(matrx1, 3, 3);
    FillThreeByThreeMatrixRandomly(matrx2, 3, 3);
    cout << "Matrix 1 : \n";
    PrintThreeByThreeMatrix(matrx1, 3, 3);
    cout << "\nMatrix 2 : \n";
    PrintThreeByThreeMatrix(matrx2, 3, 3);
    MultiplyTwoMatrices(matrx1, matrx2, result, 3, 3);
    cout << "\nResults : \n";
    PrintThreeByThreeMatrix(result, 3, 3);
}


