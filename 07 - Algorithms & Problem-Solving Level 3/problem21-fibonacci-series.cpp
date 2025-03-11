#include <iostream>
#include <vector>
using namespace std;

void PrintFibNumber(short Num)
{
	int FibNumber = 0;
	int prev1 = 0, prev2 = 1;
	cout << "1\t";
	for (short i = 2; i <= Num; i++)
	{
		FibNumber = prev1 + prev2;
		cout << FibNumber << "\t";
		prev1 = prev2;
		prev2 = FibNumber;
	}
	cout << "\n";
}


int main()
{
	PrintFibNumber(10);
}

