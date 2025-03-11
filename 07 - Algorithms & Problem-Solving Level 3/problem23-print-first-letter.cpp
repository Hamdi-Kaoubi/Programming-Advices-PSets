#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}

/*vector<char> GetFirstLetter(string str)
{
    vector<char> vcFirstLetters;
    vcFirstLetters.push_back(str[0]);
    for (int i = 1; i < str.length()-1; i++)
    {
        if (str[i] == ' ')
            vcFirstLetters.push_back(str[i + 1]);
    }
    return vcFirstLetters;
}*/

/*void PrintFirstLetter(vector<char>& vcFirstLetters)
{
    for (char& FirstLetter : vcFirstLetters)
    {
        if (!isdigit(FirstLetter) && !ispunct(FirstLetter))
            cout << (char)toupper(FirstLetter) << endl;
        else
            cout << FirstLetter << endl;
    }
}*/


//Mr Abu-Hadhoud solution :
void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}




int main()
{
    /*string str = ReadString();
    vector<char> vcFirstLetters = GetFirstLetter(str);
    PrintFirstLetter(vcFirstLetters);*/
    
    //Mr Abu-Hadhoud solution :
    PrintFirstLetterOfEachWord(ReadString());
}

