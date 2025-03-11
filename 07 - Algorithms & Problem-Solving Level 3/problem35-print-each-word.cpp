#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

//My Solution :
/*string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}

vector<string> GetWordsFromString(string str)
{
    vector<string> vcWords;
    string word = "";
    for (int i = 0; i < str.length(); i++)
    {
        word += str[i];
        if (str[i] == ' ' or i == str.length()-1)
        {
            vcWords.push_back(word);
            word = "";
        }
    }
    return vcWords;
}*/

//Mr Abu-Hadhoud Solution :
/*string ReadString()
{
    string str;
    cout << "Please enter your String : \n";
    getline(cin, str);
    return str;
}

void PrintEachWordInString(string str)
{
    string delim = " "; //delimiter
    cout << "\nYour string words are : \n\n";
    short pos = 0;
    string sWord; // define string variable
    //use find() function to get the position of the delimiters
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sWord = str.substr(0, pos); //store the word
        if (sWord != "")
            cout << sWord << endl;
        str.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (str != "")
        cout << str << endl;
}*/




int main()
{
    //My Solution :
    /*string S1 = ReadString();
    vector<string> vcWords = GetWordsFromString(S1);
    cout << "\n\nYour string words are : \n\n";
    for (string& word : vcWords)
    {
        cout << word << endl;
    }*/

    //Mr Abu-Hadhoud Solution :
    //PrintEachWordInString(ReadString());
}


