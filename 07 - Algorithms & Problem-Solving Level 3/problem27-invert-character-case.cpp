#include <iostream>
#include <cctype>
using namespace std;

char ReadCharacter()
{
    char chr;
    cout << "Please enter a character : \n";
    cin >> chr;
    return chr;
}

void PrintInvertedCharacter(char& chr)
{
    if (isupper(chr))
    {
        chr = tolower(chr);
        cout << chr << endl;
    }
    else
    {
        chr = toupper(chr);
        cout << chr << endl;
    }
}

int main()
{
    char chr = ReadCharacter();
    cout << "\nCharacter after invert case : \n";
    PrintInvertedCharacter(chr);
}

