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
    chr = tolower(chr);
    return (chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u');
}
int CountVowelsInString(string str)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
            counter++;
    }
    return counter;
}




int main()
{
    string S1 = ReadString();
    cout << "\nNumber of vowels is : " << CountVowelsInString(S1) << "\n";
}


