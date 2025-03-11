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

char InvertLetter(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

string InvertAllLetters(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = InvertLetter(str[i]);
    }
    return str;
}


int main()
{
    string str = ReadString();
    cout << "\nString after Inverting All Letters Case:\n";
    str = InvertAllLetters(str);
    cout << str << endl;
}

