#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrix(int matrx[][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter your element : ";
            cin >> matrx[i][j];
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
            printf("%d\t", matrx[i][j]);
        }
        cout << "\n";
    }
}
bool IsIdentityMatrix(int matrx[][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && matrx[i][j] != 1)
                return false;
            else if (i != j && matrx[i][j] != 0)
                return  false;
        }
    }
    return true;
}



int main()
{
    int matrx[3][3];
    FillMatrix(matrx, 3, 3);
    cout << "\nEntered matrix : \n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    if (IsIdentityMatrix(matrx, 3, 3))
        cout << "\nYes, Matrix is Identity\n";
    else
        cout << "\nNo, Matrix is NOT Identity\n";
}

