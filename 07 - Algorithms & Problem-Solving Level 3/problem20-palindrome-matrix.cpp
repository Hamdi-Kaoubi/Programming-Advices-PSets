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
bool IsPalindromeMatrix(int matrx[][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][0] != matrx[i][cols-1])
                return false;
        }
    }
    return true;
}


int main()
{
    //int matrx[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    int matrx[3][3] = { {1,2,1},{5,5,5},{7,3,8} };

    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, 3, 3);
    if (IsPalindromeMatrix(matrx, 3, 3))
        cout << "\nYes: Matrix is Palindrome\n";
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";
}

