<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

const string ClientsFileName = "ClientsData.txt";

void ManagePages(string FileName);

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkDeleted = false;
};

//Load Record From File :
vector<string> SplitLineRecord(string& LineRecord, string delim = "#//#")
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
            vcClient = SplitLineRecord(line);
            Client = FillClientRecord(vcClient);
            vcAllClients.push_back(Client);
        }
        MyFile.close();
    }
    return vcAllClients;
}


//Show Main Menue Screen :
string Tabs(short num)
{
    string Tab = "";
    for (short i = 1; i <= num; i++)
    {
        Tab += "\t";
    }
    return Tab;
}
void ShowMainMenueScreen()
{
    cout << "===========================================\n";
    cout << Tabs(2) << "Main Menue Screen";
    cout << "\n===========================================\n";
    cout << Tabs(1) << "[1] Show Clients List." << "\n";
    cout << Tabs(1) << "[2] Add New Client." << "\n";
    cout << Tabs(1) << "[3] Find Client." << "\n";
    cout << Tabs(1) << "[4] Delete Client." << "\n";
    cout << Tabs(1) << "[5] Update Client Info." << "\n";
    cout << Tabs(1) << "[6] Transactions." << "\n";
    cout << Tabs(1) << "[7] Exit.";
    cout << "\n===========================================\n";
}

//Show Clients List :
string Horizontal(short num)
{
    string Horiz = "";
    for (short i = 1; i <= num; i++)
    {
        Horiz += "__________";
    }
    return Horiz;
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
void ShowClientsList(vector<stClient> vcAllClients, short ClientsNumber)
{
    PrintHeader(ClientsNumber);
    PrintBody(vcAllClients);
}

//Add New Client :
stClient ReadClientdata(vector<stClient> vcAllClients)
{
    stClient Client;
    cout << "Enter account number : ";
    getline(cin >> ws, Client.AccountNumber);
    for (stClient C : vcAllClients)
    {
        if(Client.AccountNumber == C.AccountNumber)
        {
            cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number :";
            getline(cin >> ws, Client.AccountNumber);
        }
    }
    cout << "Enter PinCode : ";
    getline(cin, Client.PinCode);
    cout << "Enter Name : ";
    getline(cin, Client.Name);
    cout << "Enter Phone : ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance : ";
    cin >> Client.AccountBalance;
    Client.MarkDeleted = false;
    return Client;
}
void AddNewClientToFile(string FileName, vector<stClient>& vcAllClients)
{
    char New = 'Y';
    do
    {
        cout << "\n----------------------------------------\n";
        cout << Tabs(1) << "Add New Clients Screen";
        cout << "\n----------------------------------------\n";
        cout << "Adding New Client : \n";
        stClient NewClient = ReadClientdata(vcAllClients);
        string ConvertedClientData = ConvertRecordToLine(NewClient);
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << ConvertedClientData << endl;
        }
        MyFile.close();
        cout << "\nClient Added successfully, do you want to add more clients ? ";
        cin >> New;
    } while (New == 'Y' or New == 'y');
    vcAllClients = LoadDataFromFile(ClientsFileName);
}

//Find Client :
string ReadSearchedAccountNumber()
{
    string AccountNumber;
    cout << "Please enter AccountNumber : ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}
bool IsAccountExist(string AccountNumber, vector<stClient> vcClients, stClient& Client)
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
    cout << "-------------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n";
    cout << "-------------------------------------\n";
}
void FindClientByAccountNumber(vector<stClient> vcClients)
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Find Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

//Delete Client :
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vcClients)
{
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkDeleted = true;
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
            if (C.MarkDeleted == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vcClients;
}
bool DeleteClientByAccountNumber(vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Delete Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to delete this client ? (y/n) : ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
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

//Update Client : 
stClient ReadClientDataForUpdate(string AccountNumber)
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
    Client.MarkDeleted = false;
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
                C = ReadClientDataForUpdate(AccountNumber);
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
bool UpdateClientByAccountNumber(vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Update Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to Update this client ? (y/n) : ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            SaveClientsDataToFile(ClientsFileName, AccountNumber, vcClients);
            //Refresh Clients :
            vcClients = LoadDataFromFile(ClientsFileName);
            cout << "\n\nClient updated successfully\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return false;
    }
}

//deposit function :
void ShowDepositScreen()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Deposit Screen";
    cout << "\n----------------------------------------\n";
}
double DepositAmount()
{
    double deposit;
    cout << "Please enter deposit amount ? ";
    cin >> deposit;
    return deposit;
}
char MakeSureOfDeposit()
{
    char SureOrNot;
    cout << "\nAre you sure you want to perform this transaction ? (y/n) ";
    cin >> SureOrNot;
    return SureOrNot;
}
vector <stClient> SaveClientsDepositToFile(double Depos, string FileName, string AccountNumber, vector<stClient>& vcClients)
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
                C.AccountBalance += Depos;
                cout << "\nDone successfully, new Balance = " << C.AccountBalance << endl;
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
void CalcDeposit(vector<stClient>& vcClients)
{
    ShowDepositScreen();
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    while (!IsAccountExist(AccountNumber, vcClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadSearchedAccountNumber();
    }
    PrintClientCard(Client);
    double Depos = DepositAmount();
    char MakeChoice = MakeSureOfDeposit();
    if (tolower(MakeChoice) == 'y')
    {
        SaveClientsDepositToFile(Depos, ClientsFileName, AccountNumber, vcClients);
        vcClients = LoadDataFromFile(ClientsFileName);
    }
}

//withdraw function :
void ShowWithdrawScreen()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Withdraw Screen";
    cout << "\n----------------------------------------\n";
}
double WithdrawAmount()
{
    double deposit;
    cout << "Please enter withdraw amount ? ";
    cin >> deposit;
    return deposit;
}
vector <stClient> SaveClientsWithDrawToFile(double WithDraws, string FileName, string AccountNumber, vector<stClient>& vcClients)
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
                C.AccountBalance -= WithDraws;
                cout << "\nDone successfully, new Balance = " << C.AccountBalance << endl;
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
void CalcWithdraw(vector<stClient>& vcClients)
{
    ShowWithdrawScreen();
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    while (!IsAccountExist(AccountNumber, vcClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadSearchedAccountNumber();
    }
    PrintClientCard(Client);
    double Withdraws = WithdrawAmount();
    for (stClient& C : vcClients)
    {
        if (Withdraws > C.AccountBalance)
        {
            cout << "\nAmount exceeds the balance, you can withraw up to : " << C.AccountBalance;
            cout << "\nPlease enter another Amount : ";
            double w;
            cin >> w;
            Withdraws = w;
        }
    }
    char MakeChoice = MakeSureOfDeposit();
    if (tolower(MakeChoice) == 'y')
    {
        SaveClientsWithDrawToFile(Withdraws, ClientsFileName, AccountNumber, vcClients);
        vcClients = LoadDataFromFile(ClientsFileName);
    }
}

//Total balances :
double CalcTotalBalances(vector<stClient> vcClients)
{
    double Total = 0;
    for (stClient& C : vcClients)
    {
        Total += C.AccountBalance;
    }
    return Total;
}
void PrintBalanceHeader(short ClientsNumber)
{
    cout << Tabs(5) << "Balance List(" << ClientsNumber << ") Client(s).\n";
    cout << Horizontal(10) << "\n\n";
    cout << setw(20) << left << "| Account Number";
    cout << setw(35) << left << "| Client Name";
    cout << setw(10) << left << "| Balance\n";
    cout << Horizontal(10) << "\n";
}
void PrintBalanceBody(vector<stClient> vcAllClients)
{
    cout << "\n";
    for (stClient& st : vcAllClients)
    {
        cout << "| " << setw(18) << left << st.AccountNumber;
        cout << "| " << setw(33) << left << st.Name;
        cout << "| " << setw(18) << left << st.AccountBalance << "\n";
    }
    cout << Horizontal(10) << "\n";
}
void ShowTotalBalancesList(vector<stClient> vcAllClients, short ClientsNumber, double Total)
{
    PrintBalanceHeader(ClientsNumber);
    PrintBalanceBody(vcAllClients);
    cout << "\n" << Tabs(5) << "Total Balances = " << Total << "\n";
}

//Transactions Menue :
enum  enTransactions { Deposit = 1, Withdraw = 2, TotalBalances = 3, MainMenue = 4 };
void ShowTransActionMenue()
{
    cout << "===========================================\n";
    cout << Tabs(2) << "Transactions Menue Screen";
    cout << "\n===========================================\n";
    cout << Tabs(1) << "[1] Deposit." << "\n";
    cout << Tabs(1) << "[2] Withdraw." << "\n";
    cout << Tabs(1) << "[3] Total Balances." << "\n";
    cout << Tabs(1) << "[4] Main Menue." << "\n";
    cout << "\n===========================================\n";
}
short ReadTransaction()
{
    short Trans;
    cout << "Choose what do you want to do ? [1 - 4] : ";
    cin >> Trans;
    return Trans;
}
short GoBackToTransactionsMenue()
{
    short NewNavigate;
    cout << "\nPress Any Key To Go Back To Transaction Menue ...";
    system("pause>0");
    system("cls");
    ShowTransActionMenue();
    NewNavigate = ReadTransaction();
    return NewNavigate;

}
void TransNavigation(string FileName)
{
    vector<stClient> vcClients = LoadDataFromFile(FileName);
    ShowTransActionMenue();
    short TransactionNumber = ReadTransaction();
    switch ((enTransactions)TransactionNumber)
    {
    case enTransactions::Deposit:
        system("cls");
        CalcDeposit(vcClients);
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::Withdraw:
        system("cls");
        CalcWithdraw(vcClients);
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::TotalBalances:
        system("cls");
        ShowTotalBalancesList(vcClients, GetNumberOfClientsFromFile(FileName), CalcTotalBalances(vcClients));
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::MainMenue:
        system("cls");
        ManagePages(ClientsFileName);
        break;
    }
}


//Exit Program :
void ExitProgram()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Program Ends :-)";
    cout << "\n----------------------------------------\n";
    system("pause>0");
}

//Manage Pages :
short NavigateBetweenPages()
{
    short Navigate;
    cout << "Choose what do you want to do ? [1 - 7] : ";
    cin >> Navigate;
    return Navigate;
}
short ReturnToHomePage()
{
    short NewNavigate;
    cout << "\nPress Any Key To Go Back To Main Menue ...";
    system("pause>0");
    system("cls");
    ShowMainMenueScreen();
    NewNavigate = NavigateBetweenPages();
    return NewNavigate;
}
void ManagePages(string FileName)
{
    vector<stClient> vcClients = LoadDataFromFile(FileName);
    ShowMainMenueScreen();
    short Navigate = NavigateBetweenPages();
    while (Navigate >= 1 and Navigate <= 7)
    {
    switch (Navigate)
    {
    case 1:
        system("cls");
        ShowClientsList(vcClients, GetNumberOfClientsFromFile(FileName));
        Navigate = ReturnToHomePage();
        break;
    case 2:
        system("cls");
        AddNewClientToFile(FileName, vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 3:
        system("cls");
        FindClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 4:
        system("cls");
        DeleteClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 5:
        system("cls");
        UpdateClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 6:
        system("cls");
        TransNavigation(FileName);
        break;
    case 7:
        system("cls");
        ExitProgram();
        break;
    }
    }
}




int main()
{
    ManagePages(ClientsFileName);
}

=======
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

const string ClientsFileName = "ClientsData.txt";

void ManagePages(string FileName);

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkDeleted = false;
};

//Load Record From File :
vector<string> SplitLineRecord(string& LineRecord, string delim = "#//#")
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
            vcClient = SplitLineRecord(line);
            Client = FillClientRecord(vcClient);
            vcAllClients.push_back(Client);
        }
        MyFile.close();
    }
    return vcAllClients;
}


//Show Main Menue Screen :
string Tabs(short num)
{
    string Tab = "";
    for (short i = 1; i <= num; i++)
    {
        Tab += "\t";
    }
    return Tab;
}
void ShowMainMenueScreen()
{
    cout << "===========================================\n";
    cout << Tabs(2) << "Main Menue Screen";
    cout << "\n===========================================\n";
    cout << Tabs(1) << "[1] Show Clients List." << "\n";
    cout << Tabs(1) << "[2] Add New Client." << "\n";
    cout << Tabs(1) << "[3] Find Client." << "\n";
    cout << Tabs(1) << "[4] Delete Client." << "\n";
    cout << Tabs(1) << "[5] Update Client Info." << "\n";
    cout << Tabs(1) << "[6] Transactions." << "\n";
    cout << Tabs(1) << "[7] Exit.";
    cout << "\n===========================================\n";
}

//Show Clients List :
string Horizontal(short num)
{
    string Horiz = "";
    for (short i = 1; i <= num; i++)
    {
        Horiz += "__________";
    }
    return Horiz;
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
void ShowClientsList(vector<stClient> vcAllClients, short ClientsNumber)
{
    PrintHeader(ClientsNumber);
    PrintBody(vcAllClients);
}

//Add New Client :
stClient ReadClientdata(vector<stClient> vcAllClients)
{
    stClient Client;
    cout << "Enter account number : ";
    getline(cin >> ws, Client.AccountNumber);
    for (stClient C : vcAllClients)
    {
        if(Client.AccountNumber == C.AccountNumber)
        {
            cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number :";
            getline(cin >> ws, Client.AccountNumber);
        }
    }
    cout << "Enter PinCode : ";
    getline(cin, Client.PinCode);
    cout << "Enter Name : ";
    getline(cin, Client.Name);
    cout << "Enter Phone : ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance : ";
    cin >> Client.AccountBalance;
    Client.MarkDeleted = false;
    return Client;
}
void AddNewClientToFile(string FileName, vector<stClient>& vcAllClients)
{
    char New = 'Y';
    do
    {
        cout << "\n----------------------------------------\n";
        cout << Tabs(1) << "Add New Clients Screen";
        cout << "\n----------------------------------------\n";
        cout << "Adding New Client : \n";
        stClient NewClient = ReadClientdata(vcAllClients);
        string ConvertedClientData = ConvertRecordToLine(NewClient);
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << ConvertedClientData << endl;
        }
        MyFile.close();
        cout << "\nClient Added successfully, do you want to add more clients ? ";
        cin >> New;
    } while (New == 'Y' or New == 'y');
    vcAllClients = LoadDataFromFile(ClientsFileName);
}

//Find Client :
string ReadSearchedAccountNumber()
{
    string AccountNumber;
    cout << "Please enter AccountNumber : ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}
bool IsAccountExist(string AccountNumber, vector<stClient> vcClients, stClient& Client)
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
    cout << "-------------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n";
    cout << "-------------------------------------\n";
}
void FindClientByAccountNumber(vector<stClient> vcClients)
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Find Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }
}

//Delete Client :
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vcClients)
{
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkDeleted = true;
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
            if (C.MarkDeleted == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vcClients;
}
bool DeleteClientByAccountNumber(vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Delete Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to delete this client ? (y/n) : ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
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

//Update Client : 
stClient ReadClientDataForUpdate(string AccountNumber)
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
    Client.MarkDeleted = false;
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
                C = ReadClientDataForUpdate(AccountNumber);
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
bool UpdateClientByAccountNumber(vector<stClient>& vcClients)
{
    stClient Client;
    char Answer = 'n';
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Update Client Screen";
    cout << "\n----------------------------------------\n";
    string AccountNumber = ReadSearchedAccountNumber();
    if (IsAccountExist(AccountNumber, vcClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to Update this client ? (y/n) : ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            SaveClientsDataToFile(ClientsFileName, AccountNumber, vcClients);
            //Refresh Clients :
            vcClients = LoadDataFromFile(ClientsFileName);
            cout << "\n\nClient updated successfully\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return false;
    }
}

//deposit function :
void ShowDepositScreen()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Deposit Screen";
    cout << "\n----------------------------------------\n";
}
double DepositAmount()
{
    double deposit;
    cout << "Please enter deposit amount ? ";
    cin >> deposit;
    return deposit;
}
char MakeSureOfDeposit()
{
    char SureOrNot;
    cout << "\nAre you sure you want to perform this transaction ? (y/n) ";
    cin >> SureOrNot;
    return SureOrNot;
}
vector <stClient> SaveClientsDepositToFile(double Depos, string FileName, string AccountNumber, vector<stClient>& vcClients)
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
                C.AccountBalance += Depos;
                cout << "\nDone successfully, new Balance = " << C.AccountBalance << endl;
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
void CalcDeposit(vector<stClient>& vcClients)
{
    ShowDepositScreen();
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    while (!IsAccountExist(AccountNumber, vcClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadSearchedAccountNumber();
    }
    PrintClientCard(Client);
    double Depos = DepositAmount();
    char MakeChoice = MakeSureOfDeposit();
    if (tolower(MakeChoice) == 'y')
    {
        SaveClientsDepositToFile(Depos, ClientsFileName, AccountNumber, vcClients);
        vcClients = LoadDataFromFile(ClientsFileName);
    }
}

//withdraw function :
void ShowWithdrawScreen()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Withdraw Screen";
    cout << "\n----------------------------------------\n";
}
double WithdrawAmount()
{
    double deposit;
    cout << "Please enter withdraw amount ? ";
    cin >> deposit;
    return deposit;
}
vector <stClient> SaveClientsWithDrawToFile(double WithDraws, string FileName, string AccountNumber, vector<stClient>& vcClients)
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
                C.AccountBalance -= WithDraws;
                cout << "\nDone successfully, new Balance = " << C.AccountBalance << endl;
            }
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
    return vcClients;
}
void CalcWithdraw(vector<stClient>& vcClients)
{
    ShowWithdrawScreen();
    string AccountNumber = ReadSearchedAccountNumber();
    stClient Client;
    while (!IsAccountExist(AccountNumber, vcClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadSearchedAccountNumber();
    }
    PrintClientCard(Client);
    double Withdraws = WithdrawAmount();
    for (stClient& C : vcClients)
    {
        if (C.AccountNumber == AccountNumber && Withdraws > C.AccountBalance)
        {
            cout << "\nAmount exceeds the balance, you can withraw up to : " << C.AccountBalance;
            cout << "\nPlease enter another Amount : ";
            double w;
            cin >> w;
            Withdraws = w;
        }
    }
    char MakeChoice = MakeSureOfDeposit();
    if (tolower(MakeChoice) == 'y')
    {
        SaveClientsWithDrawToFile(Withdraws, ClientsFileName, AccountNumber, vcClients);
        vcClients = LoadDataFromFile(ClientsFileName);
    }
}

//Total balances :
double CalcTotalBalances(vector<stClient> vcClients)
{
    double Total = 0;
    for (stClient& C : vcClients)
    {
        Total += C.AccountBalance;
    }
    return Total;
}
void PrintBalanceHeader(short ClientsNumber)
{
    cout << Tabs(5) << "Balance List(" << ClientsNumber << ") Client(s).\n";
    cout << Horizontal(10) << "\n\n";
    cout << setw(20) << left << "| Account Number";
    cout << setw(35) << left << "| Client Name";
    cout << setw(10) << left << "| Balance\n";
    cout << Horizontal(10) << "\n";
}
void PrintBalanceBody(vector<stClient> vcAllClients)
{
    cout << "\n";
    for (stClient& st : vcAllClients)
    {
        cout << "| " << setw(18) << left << st.AccountNumber;
        cout << "| " << setw(33) << left << st.Name;
        cout << "| " << setw(18) << left << st.AccountBalance << "\n";
    }
    cout << Horizontal(10) << "\n";
}
void ShowTotalBalancesList(vector<stClient> vcAllClients, short ClientsNumber, double Total)
{
    PrintBalanceHeader(ClientsNumber);
    PrintBalanceBody(vcAllClients);
    cout << "\n" << Tabs(5) << "Total Balances = " << Total << "\n";
}

//Transactions Menue :
enum  enTransactions { Deposit = 1, Withdraw = 2, TotalBalances = 3, MainMenue = 4 };
void ShowTransActionMenue()
{
    cout << "===========================================\n";
    cout << Tabs(2) << "Transactions Menue Screen";
    cout << "\n===========================================\n";
    cout << Tabs(1) << "[1] Deposit." << "\n";
    cout << Tabs(1) << "[2] Withdraw." << "\n";
    cout << Tabs(1) << "[3] Total Balances." << "\n";
    cout << Tabs(1) << "[4] Main Menue." << "\n";
    cout << "\n===========================================\n";
}
short ReadTransaction()
{
    short Trans;
    cout << "Choose what do you want to do ? [1 - 4] : ";
    cin >> Trans;
    return Trans;
}
short GoBackToTransactionsMenue()
{
    short NewNavigate;
    cout << "\nPress Any Key To Go Back To Transaction Menue ...";
    system("pause>0");
    system("cls");
    ShowTransActionMenue();
    NewNavigate = ReadTransaction();
    return NewNavigate;

}
void TransNavigation(string FileName)
{
    vector<stClient> vcClients = LoadDataFromFile(FileName);
    ShowTransActionMenue();
    short TransactionNumber = ReadTransaction();
    switch ((enTransactions)TransactionNumber)
    {
    case enTransactions::Deposit:
        system("cls");
        CalcDeposit(vcClients);
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::Withdraw:
        system("cls");
        CalcWithdraw(vcClients);
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::TotalBalances:
        system("cls");
        ShowTotalBalancesList(vcClients, GetNumberOfClientsFromFile(FileName), CalcTotalBalances(vcClients));
        TransactionNumber = GoBackToTransactionsMenue();
        break;
    case enTransactions::MainMenue:
        system("cls");
        ManagePages(ClientsFileName);
        break;
    }
}


//Exit Program :
void ExitProgram()
{
    cout << "\n----------------------------------------\n";
    cout << Tabs(1) << "Program Ends :-)";
    cout << "\n----------------------------------------\n";
    system("pause>0");
}

//Manage Pages :
short NavigateBetweenPages()
{
    short Navigate;
    cout << "Choose what do you want to do ? [1 - 7] : ";
    cin >> Navigate;
    return Navigate;
}
short ReturnToHomePage()
{
    short NewNavigate;
    cout << "\nPress Any Key To Go Back To Main Menue ...";
    system("pause>0");
    system("cls");
    ShowMainMenueScreen();
    NewNavigate = NavigateBetweenPages();
    return NewNavigate;
}
void ManagePages(string FileName)
{
    vector<stClient> vcClients = LoadDataFromFile(FileName);
    ShowMainMenueScreen();
    short Navigate = NavigateBetweenPages();
    while (Navigate >= 1 and Navigate <= 7)
    {
    switch (Navigate)
    {
    case 1:
        system("cls");
        ShowClientsList(vcClients, GetNumberOfClientsFromFile(FileName));
        Navigate = ReturnToHomePage();
        break;
    case 2:
        system("cls");
        AddNewClientToFile(FileName, vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 3:
        system("cls");
        FindClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 4:
        system("cls");
        DeleteClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 5:
        system("cls");
        UpdateClientByAccountNumber(vcClients);
        Navigate = ReturnToHomePage();
        break;
    case 6:
        system("cls");
        TransNavigation(FileName);
        break;
    case 7:
        system("cls");
        ExitProgram();
        break;
    }
    }
}




int main()
{
    ManagePages(ClientsFileName);
}

>>>>>>> 2e133ccf74d142df351db3ea7df5dbe40297869d
