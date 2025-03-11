#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> vString, string separator)
{
    string S1 = "";
    for (string& s : vString)
    {
        S1 = S1 + s + separator;
    }
    return S1.substr(0, S1.length() - separator.length());
}

string JoinString(string ArrayOfStrings[], short size, string separator)
{
    string S1 = "";
    for (short i = 0; i < size; i++)
    {
        S1 = S1 + ArrayOfStrings[i] + separator;
    }
    return S1.substr(0, S1.length() - separator.length());
}



int main()
{
    vector<string> vString = { "Mohammed","Faid","Ali","Maher" };
    const short size = 4;
    string ArrayOfString[size] = { "Mohammed","Faid","Ali","Maher" };
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ") << "\n";
    cout<< "\nArray after join: \n";
    cout << JoinString(ArrayOfString, size, ", ") << "\n";
    
}

