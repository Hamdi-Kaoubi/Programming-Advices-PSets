#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> vcNames, string splitter)
{
    string JoinedString = "";
    vector<string>::iterator iter;
    for (iter = vcNames.begin(); iter != vcNames.end(); iter++)
    {
        if(iter == vcNames.end()-1)
            JoinedString += *iter;
        else
            JoinedString += *iter + splitter;
    }
    return JoinedString;
}


int main()
{
    vector<string> vcNames{ "Mohammed", "Ali", "Maher","Fadi", "Amal"};
    cout << "Vector after join : " << endl;
    cout << JoinString(vcNames, " - ") << endl;
}


