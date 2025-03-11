#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemovePunct(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (ispunct(str[i]))
            str.erase(i, 1);
    }
    return str;
}




int main()
{
    string S1 = "welcome to Jordan, Jordan is a nice country; it's amazing.";
    cout << "\nOriginal String : \n" << S1 << "\n";
    cout << "\nPunctuations Removed : \n" << RemovePunct(S1) << "\n";
}

