#include <iostream>
#include <string>
#include <vector>
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

vector<string> ReplaceWord(vector<string> vString, string Original, string Target)
{
    for (string& St : vString)
    {
        while (St == Original)
        {
            St = Target;
        }
    }
    return vString;
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


int main()
{
    string S1 = "welcome to Jordan , Jordan is a nice country , I love Jordan";
    cout << "\nOriginal String : \n" << S1 << "\n";
    cout << "\nString After Replace : \n";
    cout << JoinString(ReplaceWord(SplitString(S1, " "), "Jordan", "USA"), " ") << "\n";
}


