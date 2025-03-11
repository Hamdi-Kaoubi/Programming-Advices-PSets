#include <iostream>
#include <string>
using namespace std;


string TrimLeft(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        while (str[0] == ' ')
        {
            str.erase(0, 1);
        }
    }
    return str;
}

string TrimRight(string str)
{
    for (int i = str.length(); i > 0; i--)
    {
        while (str[str.length()] == ' ')
        {
            str.erase(str.end());
        }
    }
    return str;
}

string Trim(string str)
{
    str = TrimLeft(str);
    str = TrimRight(str);
    return str;
}


int main()
{
    string s1 = "     Mohammed Abu-Hadhoud     ";
    cout << "String     = " << s1 << endl;
    cout << "Trim Left  = " << TrimLeft(s1)<< endl;
    cout << "Trim Right = " << TrimRight(s1)<< endl;
    cout << "Trim       = " << Trim(s1) << endl;

}


