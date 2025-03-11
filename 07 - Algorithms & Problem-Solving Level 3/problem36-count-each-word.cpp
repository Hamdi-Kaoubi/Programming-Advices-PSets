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

void PrintEachWordInString(string str)
{
    string delim = " ";
    short pos = 0;
    int sWord=0; 
    
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sWord++; 
        str.erase(0, pos + delim.length()); 
    }
    if (str != "")
        sWord++;
        cout << "The number of words in your string is : " << sWord << endl;
}

int main()
{
    PrintEachWordInString(ReadString());
}


