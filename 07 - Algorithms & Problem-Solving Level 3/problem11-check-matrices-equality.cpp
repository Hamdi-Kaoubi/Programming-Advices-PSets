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
            printf("%02d\t", matrx[i][j]);
        }
        cout << "\n";
    }
}
int SumOfMatrix(int matrx[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrx[i][j];
        }
    }
    return sum;
}
bool CompareTwoMatrices(int matrx1[3][3], int matrx2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            return (SumOfMatrix(matrx1, rows, cols) == SumOfMatrix(matrx2, rows, cols));
        }
    }
}
void PrintComparedMatrices(bool comparedMatrices)
{
    if (comparedMatrices)
        cout << "\nYes, Matrices are equal\n";
    else
        cout << "\nNo, Matrices are NOT equal\n";
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
    PrintComparedMatrices(CompareTwoMatrices(matrx1, matrx2, 3, 3));

}
