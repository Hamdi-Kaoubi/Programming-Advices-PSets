#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitLineRecord(string& LineRecord, string delim)
{
    vector <string> vcClient;
    string OneData;
    int pos = 0;
    while ((pos = LineRecord.find(delim)) != std::string::npos)
    {
        OneData = LineRecord.substr(0, pos);
        if (OneData != "")
            vcClient.push_back(OneData);
        LineRecord.erase(0, pos + delim.length());
    }
    if (LineRecord != "")
        vcClient.push_back(LineRecord);
    return vcClient;
}

stClient FillClientRecord(vector <string> vcClient)
{
    stClient Client;
    Client.AccountNumber = vcClient[0];
    Client.PinCode = vcClient[1];
    Client.Name = vcClient[2];
    Client.Phone = vcClient[3];
    Client.AccountBalance = stod(vcClient[4]);
    return Client;
}



int main()
{
    string LineRecord = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "\nLine Record is : \n" << LineRecord << "\n";
    vector <string> vcClient = SplitLineRecord(LineRecord, "#//#");
    stClient Client = FillClientRecord(vcClient);
    cout << "\nThe following is the extracted client record : \n\n";
    cout << "Account number  : " << Client.AccountNumber << "\n";
    cout << "Pin code        : " << Client.PinCode << "\n";
    cout << "Name            : " << Client.Name << "\n";
    cout << "Phone           : " << Client.Phone << "\n";
    cout << "Account balance : " << Client.AccountBalance << "\n";

}

