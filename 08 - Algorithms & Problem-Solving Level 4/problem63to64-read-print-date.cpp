#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sDate
{
    int Day;
    int Month;
    int Year;
};
string ReadDate(string Message)
{
    string date;
    cout << Message;
    getline(cin >> ws, date);
    return date;
}
vector<string> SplitString(string& str, string delim = "/")
{
    vector<string> vcSplits;
    string sword;
    short pos = 0;
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sword = str.substr(0, pos);
        if (sword != "")
            vcSplits.push_back(sword);
        str.erase(0, pos + delim.length());
    }
    if (str != "")
        vcSplits.push_back(str);
    return vcSplits;
}

sDate StringToDate(string& str)
{
    sDate Date;
    vector<string> vcDate = SplitString(str);
    Date.Day = stoi(vcDate[0]);
    Date.Month = stoi(vcDate[1]);
    Date.Year = stoi(vcDate[2]);
    return Date;
}
string DateToString(sDate Date, string separator = "/")
{
    string DateString = "";
    DateString += to_string(Date.Day) + separator;
    DateString += to_string(Date.Month) + separator;
    DateString += to_string(Date.Year);
    return DateString;
}

int main()
{
    string DateString = ReadDate("Please Enter Date dd/mm/yyyy ? ");
    sDate Date = StringToDate(DateString);
    cout << "\nDay: " << Date.Day << "\n";
    cout << "Month: " << Date.Month << "\n";
    cout << "Year: " << Date.Year << "\n";
    cout << "\nYou Entered: " << DateToString(Date) << "\n";
}