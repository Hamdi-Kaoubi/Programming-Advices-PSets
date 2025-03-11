#include <iostream>
#include <iomanip>
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
int CountNumberInMatrix(int matrx[][3], short rows, short cols)
{
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][j] == 0)
                counter++;
        }
    }
    return counter;
}


int main()
{
    int matrx[3][3] = { {0,0,7,},{0,0,10},{0,0,5} };
    //int matrx[3][3] = { {0,15,7,},{2,0,10},{4,0,5} };
    int rows = 3, cols = 3;
    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, rows, cols);

    int counter = CountNumberInMatrix(matrx, rows, cols);
    int NumberOfMatrixElements = rows * cols;
    if (counter > NumberOfMatrixElements / 2)
        cout << "\nYes, this matrix is Sparse\n";
    else
        cout << "\nNo, it's NOT Sparse\n";
}

