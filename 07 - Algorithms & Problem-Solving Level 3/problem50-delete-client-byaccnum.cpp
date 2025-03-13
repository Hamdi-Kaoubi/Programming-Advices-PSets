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
    string Target;
    cout << "Please enter AccountNumber : ";
    getline(cin, Target);
    return Target;
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

stClient FillClientRecord(string LineRecord, string delim = "#//#")
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
            Client = FillClientRecord(line);
            vcAllClients.push_back(Client);
        }
        MyFile.close();
    }
    return vcAllClients;
}

bool FindClientByAccountNumber(string Target, vector<stClient> vcClients, stClient& Client)
{
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == Target)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vcClients)
{
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <stClient> SaveClientsDataToFile(string FileName, vector<stClient> vcClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient C : vcClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vcClients;
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

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber,vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to delete this client ? (y/n) : ";
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vcClients);
            SaveClientsDataToFile(ClientsFileName, vcClients);
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
    DeleteClientByAccountNumber(AccountNumber, vcClients);
}

