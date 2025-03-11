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

bool IsNumberExistInMatrix(int matrx[][3], short rows, short cols, int number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][j] == number)
                return true;
        }
    }
    return false;
}

vector<int> GetIntersectedNumbers(int matrx1[][3], int matrx2[][3], int rows, int cols)
{
    vector<int> vcIntersectedNumbers;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (IsNumberExistInMatrix(matrx2, rows, cols, matrx1[i][j]))
                vcIntersectedNumbers.push_back(matrx1[i][j]);
        }
    }
    return vcIntersectedNumbers;
}




int main()
{
    int matrx1[3][3] = { {77,5,12},{22,20,1},{12,1,9} };
    int matrx2[3][3] = { {5,80,90,},{22,77,1},{10,8,33} };

    cout << "Matrix 1 : \n";
    PrintThreeByThreeMatrix(matrx1, 3, 3);

    cout << "\nMatrix 2 : \n";
    PrintThreeByThreeMatrix(matrx2, 3, 3);

    vector<int> vcIntersectedNumbers = GetIntersectedNumbers(matrx1, matrx2, 3, 3);

    cout << "\nIntersected Numbers are : \n";
    for (int& Intersected : vcIntersectedNumbers)
    {
        cout << setw(3) << Intersected << "\t";
    }
    cout << "\n";
}

