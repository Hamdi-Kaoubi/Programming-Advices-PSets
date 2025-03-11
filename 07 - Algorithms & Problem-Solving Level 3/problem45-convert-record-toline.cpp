#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*struct stAccountData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    int AccountBalance;
};*/
/*void FillBankAccountDataIntoFile(string FileName)
{
    stAccountData ClientAccount;
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        cout << "Please enter client data : \n\n";
        cout << "Enter account number : ";
        getline(cin, ClientAccount.AccountNumber);
        MyFile << ClientAccount.AccountNumber << endl;
        cout << "\nEnter PinCode : ";
        getline(cin, ClientAccount.PinCode);
        MyFile << ClientAccount.PinCode << endl;
        cout << "\nEnter Name : ";
        getline(cin, ClientAccount.Name);
        MyFile << ClientAccount.Name << endl;
        cout << "\nEnter Phone number :";
        getline(cin, ClientAccount.Phone);
        MyFile << ClientAccount.Phone << endl;
        cout << "\nEnter accountBalance : ";
        cin >> ClientAccount.AccountBalance;
        MyFile << ClientAccount.AccountBalance << endl;
    }
    MyFile.close();
}*/
/*void LoadAccountDataToVector(string FileName, vector <string>& vcAccountData)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            vcAccountData.push_back(line);
        }
    }
    MyFile.close();
}*/
/*string JoinString(vector<string> vcAccountData, string Separator)
{
    string S1 = "";
    for (string& s : vcAccountData)
    {
        S1 = S1 + s + Separator;
    }
    return S1.substr(0, S1.length() - Separator.length());
}*/

//Mr ABU Hadhoud solution :
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient ReadClientdata()
{
    stClient Client;
    cout << "Enter account number : ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode : ";
    getline(cin, Client.PinCode);
    cout << "Enter Name : ";
    getline(cin, Client.Name);
    cout << "Enter Phone : ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance : ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertDataToOneLine(stClient Client, string separator = "#//#")
{
    string DataLine = "";
    DataLine += Client.AccountNumber + separator;
    DataLine += Client.PinCode + separator;
    DataLine += Client.Name + separator;
    DataLine += Client.Phone + separator;
    DataLine += to_string(Client.AccountBalance);
    return DataLine;
}



int main()
{
    /*string FileName = "accountData.txt";
    string Separator = "#//#";
    vector <string> vcAccountData;
    FillBankAccountDataIntoFile(FileName);
    LoadAccountDataToVector(FileName, vcAccountData);
    cout << "\nClientRecord For Saving is : \n";
    cout << JoinString(vcAccountData, Separator) << endl;*/

    //Mr Abu Hadhoud solution :
    cout << "Please enter Client Data : \n\n";
    stClient Client;
    Client = ReadClientdata();
    cout << "\n\n Client Record for saving is : \n";
    cout << ConvertDataToOneLine(Client) << "\n";

}

