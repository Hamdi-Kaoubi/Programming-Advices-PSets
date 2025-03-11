#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
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

string Tabs(short num)
{
    string Tabs = "";
    for (short i = 1; i <= num; i++)
    {
        Tabs += "\t";
    }
    return Tabs;
}

string Horizontal(short num)
{
    string Horiz = "";
    for (short i = 1; i <= num; i++)
    {
        Horiz += "__________";
    }
    return Horiz;
}

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

short GetNumberOfClientsFromFile(string FileName)
{
    short counter = 0;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            counter++;
        }
        MyFile.close();
    }
    return counter;
}

void PrintHeader(short ClientsNumber)
{
    cout << Tabs(5) << "Client List(" << ClientsNumber << ") Client(s).\n";
    cout << Horizontal(10) << "\n\n";
    cout << setw(20) << left << "| Account Number";
    cout << setw(15) << left << "| Pin Code";
    cout << setw(35) << left << "| Client Name";
    cout << setw(20) << left << "| Phone";
    cout << "| Balance\n";
    cout << Horizontal(10) << "\n";
}

void PrintBody(vector<stClient> vcAllClients)
{
    cout << "\n";
    for (stClient& st : vcAllClients)
    {
        cout << "| " << setw(18) << left << st.AccountNumber;
        cout << "| " << setw(13) << left << st.PinCode;
        cout << "| " << setw(33) << left << st.Name;
        cout << "| " << setw(18) << left << st.Phone;
        cout << "| " << st.AccountBalance << "\n";
    }
    cout << Horizontal(10) << "\n";
}


int main()
{   
    vector<stClient> vcAllClients = LoadDataFromFile("ClientsData.txt");
    PrintHeader(GetNumberOfClientsFromFile("ClientsData.txt"));
    PrintBody(vcAllClients);
}

