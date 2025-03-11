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

stClient ReadClientdata()
{
    stClient Client;
    cout << "Enter account number : ";
    getline(cin >> ws, Client.AccountNumber);
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

void AddNewClientToFile(string FileName)
{
    char New = 'Y';
    do
    { 
    system("cls");
    cout << "Adding new Client : \n";
    stClient NewClient = ReadClientdata();
    string ConvertedClientData = ConvertDataToOneLine(NewClient);
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
}



int main()
{
    AddNewClientToFile("ClientsData.txt");
}


