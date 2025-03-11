#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}
bool IsVowel(char& chr)
{
    char chr1 = tolower(chr);
    return (chr1 == 'a') || (chr1 == 'e') || (chr1 == 'i') || (chr1 == 'o') || (chr1 == 'u');
}
void PrintVowels(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
            cout << str[i] << "\t";
    }
}




int main()
{
    string S1 = ReadString();
    cout << "\nVowels in string are : ";
    PrintVowels(S1);
    cout << "\n";
}

