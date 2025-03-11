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

void UpperFirstLetterOfEachWord(string& S1)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}




int main()
{
    string str = ReadString();
    UpperFirstLetterOfEachWord(str);
    cout << "\nString After Conversion : \n";
    cout << "\n" << str << "\n";
}

