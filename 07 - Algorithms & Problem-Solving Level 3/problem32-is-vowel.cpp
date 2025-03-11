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

bool IsVowel(char& chr)
{
    chr= tolower(chr);
    return (chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u');
}




int main()
{
    char ch1 = ReadCharacter();
    if(IsVowel(ch1))
        cout << "\nYes Letter \'" << ch1 << "\' is Vowel";
    else
        cout << "\nNo Letter \'" << ch1 << "\' is NOT Vowel";
}


