#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

string Lower(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

string JoinString(vector<string> vString, string separator)
{
    string S1 = "";
    for (string& s : vString)
    {
        S1 = S1 + s + separator;
    }
    return S1.substr(0, S1.length() - separator.length());
}

string ReplaceWordUsingSplit(string S1, string Original, string Target, bool IsMatch = true)
{
    vector<string> vString = SplitString(S1, " ");
    for (string& St : vString)
    {
        if (IsMatch)
        {
            if (St == Original)
                St = Target;
        }
        else
        {
            if (Lower(St) == Lower(Original))
                St = Target;
        }
    }
    return JoinString(vString, " ");
}








int main()
{
    string S1 = "welcome to Jordan , Jordan is a nice country , I love Jordan";
    string Original = "jordan";
    string Target = "USA";
    cout << "\nOriginal String : \n" << S1 << "\n";
    cout << "\nReplace with match case : \n";
    cout << ReplaceWordUsingSplit(S1, Original, Target) << "\n";
    cout << "\nReplace without match case : \n";
    cout << ReplaceWordUsingSplit(S1, Original, Target, false) << "\n";
}
