#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string ClientsFileName = "ClientsData.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

string ReadSearchedAccountNumber()
{
    string AccountNumber;
    cout << "Please enter AccountNumber : ";
    getline(cin, AccountNumber);
    return AccountNumber;
}

vector<string> SplitLineRecord(string LineRecord, string delim)
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

stClient FillClientRecordToStruct(string LineRecord, string delim = "#//#")
{
    stClient Client;
    vector <string> vcClient;
    vcClient = SplitLineRecord(LineRecord, delim);
    Client.AccountNumber = vcClient[0];
    Client.PinCode = vcClient[1];
    Client.Name = vcClient[2];
    Client.Phone = vcClient[3];
    Client.AccountBalance = stod(vcClient[4]);
    return Client;
}

string ConvertRecordToLine(stClient Client, string separator = "#//#")
{
    string DataLine = "";
    DataLine += Client.AccountNumber + separator;
    DataLine += Client.PinCode + separator;
    DataLine += Client.Name + separator;
    DataLine += Client.Phone + separator;
    DataLine += to_string(Client.AccountBalance);
    return DataLine;
}

vector<stClient> LoadDataFromFile(string FileName)
{
    vector<stClient> vcAllClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        stClient Client;
        string line;
        while (getline(MyFile, line))
        {
            Client = FillClientRecordToStruct(line);
            vcAllClients.push_back(Client);
        }
        MyFile.close();
    }
    return vcAllClients;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vcClients, stClient& Client)
{
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n";
}

stClient UpdateStruct(string AccountNumber)
{
    stClient Client;
            Client.AccountNumber = AccountNumber;
            cout << "\nEnter PinCode ? ";
            getline(cin >> ws, Client.PinCode);
            cout << "Enter Name ? ";
            getline(cin, Client.Name);
            cout << "Enter Phone : ";
            getline(cin, Client.Phone);
            cout << "Enter Account Balance ? ";
            cin >> Client.AccountBalance;
            Client.MarkForDelete = false;
    return Client;
}

vector <stClient> SaveClientsDataToFile(string FileName, string AccountNumber, vector<stClient>& vcClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient C : vcClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C = UpdateStruct(AccountNumber);
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to Update this client ? (y/n) : ";
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            SaveClientsDataToFile(ClientsFileName, AccountNumber, vcClients);
            //Refresh Clients :
            vcClients = LoadDataFromFile(ClientsFileName);
            cout << "\n\nClient deleted successfully\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return false;
    }
}

int main()
{
    vector<stClient> vcClients = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadSearchedAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vcClients);
}

