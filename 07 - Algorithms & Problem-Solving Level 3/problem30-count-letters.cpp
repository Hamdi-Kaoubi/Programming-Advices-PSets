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
char ReadCharacter()
{
    char chr;
    cout << "\nPlease enter a character : \n";
    cin >> chr;
    return chr;
}
int CountCharacterInString(string str, char chr)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        (str[i] == chr) ? counter++ : counter;
    }
    return counter;
}






int main()
{
    string s1 = ReadString();
    char ch1 = ReadCharacter();
    cout << "\n\nLetter '" << ch1 << "' Count = " << CountCharacterInString(s1, ch1)<<"\n";
}

