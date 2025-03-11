#include <iostream>
#include <iomanip>
using namespace std;


int ReadNumber()
{
    int num;
    cout << "\nEnter the number to count in matrix: ";
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

int CountNumberInMatrix(int matrx[][3], short rows, short cols, int number)
{
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrx[i][j] == number)
                counter++;
        }
    }
    return counter;
}



int main()
{
    int matrx[3][3] = { {5,0,7,},{0,5,0},{7,0,5} };

    cout << "Matrix : \n";
    PrintThreeByThreeMatrix(matrx, 3, 3);

    int Number = ReadNumber();

    int counter = CountNumberInMatrix(matrx, 3, 3, Number);

    if (counter != 0)
        cout << "\nNumber " << Number << " count in matrix " << counter << " Times.\n";
    else
        cout << "\nThis number doesn't exist in the matrix.\n";
}

