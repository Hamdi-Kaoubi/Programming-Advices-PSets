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

struct stCapitalsAndSmalls
{
    short Capitals = 0;
    short Smalls = 0;
    short NoLetters = 0;
};

stCapitalsAndSmalls GetCapitalsFromString(string str)
{
    stCapitalsAndSmalls GetAllCapsAndSmalls;
    for (short i = 0; i < str.length(); i++)
    {
        isupper(str[i]) ? GetAllCapsAndSmalls.Capitals++ 
            : islower(str[i]) ? GetAllCapsAndSmalls.Smalls++ 
            : GetAllCapsAndSmalls.NoLetters++;
    }
    return GetAllCapsAndSmalls;
}



int main()
{
    string s1 = ReadString();
    cout << "\nString length = " << s1.length() << "\n";
    cout << "Capital letters count = " << GetCapitalsFromString(s1).Capitals << "\n";
    cout << "Small letters count = " << GetCapitalsFromString(s1).Smalls << "\n";
}

