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
bool IsScalarMatrix(int matrx[][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && matrx[i][j] != matrx[0][0])
                return false;
            else if (i != j && matrx[i][j] != 0)
                return  false;
        }
    }
    return true;
}


int main()
{
    int matrx[3][3] = { {5,0,0,},{0,5,0},{0,0,5} };
    //int matrx[3][3] = { {9,0,0,},{0,9,10},{0,5,9} };
    //int matrx[3][3] = { {9,0,0,},{0,3,0},{0,0,9} };
    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    if (IsScalarMatrix(matrx, 3, 3))
        cout << "\nYes, this Matrix is Scalar\n";
    else
        cout << "\nNo, this Matrix is NOT Scalar\n";
}


