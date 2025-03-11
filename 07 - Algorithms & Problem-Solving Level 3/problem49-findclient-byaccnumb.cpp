#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

vector<stClient> LoadDataFromFile(string FileName)
{
    stClient Client;
    vector<string> vcClient;
    vector<stClient> vcAllClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            vcClient = SplitLineRecord(line, "#//#");
            Client = FillClientRecord(vcClient);
            vcAllClients.push_back(Client);
        }
        MyFile.close();
    }
    return vcAllClients;
}

string ReadSearchedAccountNumber()
{
    string Target;
    cout << "Please enter AccountNumber : ";
    getline(cin, Target);
    return Target;
}

void PrintAccountNumberIfExist(vector<stClient> vcClients, string Target)
{
    bool NotExist = true;
    for (stClient& Client : vcClients)
    {
        if (Client.AccountNumber == Target)
        {
            cout << "\nThe following are the client details : \n\n";
            cout << "Account number  : " << Client.AccountNumber << "\n";
            cout << "Pin code        : " << Client.PinCode << "\n";
            cout << "Name            : " << Client.Name << "\n";
            cout << "Phone           : " << Client.Phone << "\n";
            cout << "Account balance : " << Client.AccountBalance << "\n";
            NotExist = false;
        }
    }
    if (NotExist)
        cout << "\nClient with Account Number (" << Target << ") NOT found !\n";
}





int main()
{
    string Target = ReadSearchedAccountNumber();
    vector<stClient> vcClients = LoadDataFromFile("ClientsData.txt");
    PrintAccountNumberIfExist(vcClients, Target);
}

