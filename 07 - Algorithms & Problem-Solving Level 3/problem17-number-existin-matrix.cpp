#include <iostream>
#include <iomanip>
using namespace std;


int ReadNumber()
{
    int num;
    cout << "\nPlease enter the number to look for in matrix: ";
    cin >> num;
    return num;
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


int main()
{
    int matrx[3][3] = { {77,5,12},{22,20,1},{12,1,9} };
    //int matrx[3][3] = { {0,15,7,},{2,0,10},{4,0,5} };
    int rows = 3, cols = 3;

    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, rows, cols);

    int NumberToLookFor = ReadNumber();

    if (IsNumberExistInMatrix(matrx, rows, cols, NumberToLookFor))
        cout << "\nYes it is there\n";
    else
        cout << "\nNo it isn't there\n";
}

