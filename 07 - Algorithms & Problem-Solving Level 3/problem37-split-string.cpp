#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}


vector<string> SplitString(string& str, string delim)
{
    vector<string> vcSplits;
    string sword;
    short pos = 0;
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sword = str.substr(0, pos);
        if(sword != "")
            vcSplits.push_back(sword);
        str.erase(0, pos + delim.length());
    }
    if (str != "")
        vcSplits.push_back(str);
    return vcSplits;
}




int main()
{
    string s1 = ReadString();
    vector<string> vcSplits = SplitString(s1, " ");
    cout << "\nTokens = " << vcSplits.size() << "\n";
    for (string& OneSplit : vcSplits)
    {
        cout << OneSplit << endl;
    }
}

