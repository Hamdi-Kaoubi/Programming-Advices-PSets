#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}

void  UpperAllLetters(string& S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
            S1[i] = toupper(S1[i]);
    }
}

void LowerAllLetters(string& S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
}




int main()
{
    string str = ReadString();
    cout << "\nString after upper : \n";
    UpperAllLetters(str);
    cout << str;
    cout << "\nString after lower : \n";
    LowerAllLetters(str);
    cout << str << "\n";
}

