#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
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

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}
string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}






int main()
{
    string DateString = ReadDate("Please Enter Date dd/mm/yyyy ? ");
    sDate Date = StringToDate(DateString);
    cout << "\n" << FormateDate(Date) << "\n";
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
}