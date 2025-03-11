#include <iostream>
#include <string>
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
char InvertLetterCase(char chr)
{
    if (islower(chr))
        return toupper(chr);
    else
        return tolower(chr);
}
int CountCharacterCaseInString(string str, char chr, bool MatchCase=true)
{
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (MatchCase)
        {
            if (str[i] == chr)
                counter++;
        }
        else
        {
            if (tolower(str[i]) == tolower(chr))
                counter++;
        }
    }
    return counter;
}


int main()
{
    string s1 = ReadString();
    char ch1 = ReadCharacter();
    cout << "\n\nLetter '" << ch1 << "' Count = " << CountCharacterCaseInString(s1, ch1) << "\n";
    cout << "\n\nLetter '" << ch1 << "' Or '" << InvertLetterCase(ch1) << "' Count = " << CountCharacterCaseInString(s1, ch1, false) << "\n";
}

