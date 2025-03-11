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
void PrintSumOfMatrix(int matrx[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrx[i][j];
        }
    }
    cout << "\nSum of Matrix is : " << sum << endl;
}




int main()
{
	srand((unsigned)time(NULL));
    int matrx1[3][3];
    FillThreeByThreeMatrixRandomly(matrx1, 3, 3);
    cout << "Matrix 1 : \n";
    PrintThreeByThreeMatrix(matrx1, 3, 3);
    PrintSumOfMatrix(matrx1, 3, 3);
}
