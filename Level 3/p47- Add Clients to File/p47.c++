//revesion this problem
#include <bits/stdc++.h>
using namespace std;
const string ClientsFileName = "Clients.text";
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    double AccountBalance;
};

stClient ReadNewClient()
{
    stClient NewClient;

    cout << "Enter Account Number? ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, NewClient.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, NewClient.PinCode);

    cout << "Enter Name? ";
    getline(cin, NewClient.Name);

    cout << "Enter Phone? ";
    getline(cin, NewClient.PhoneNumber);

    cout << "Enter Account Balance? ";
    cin >> NewClient.AccountBalance;

    return NewClient;

}

string ConvertRecordToLine(stClient NewClient, string Seperator = "#//#")
{
    string ClientRecord = "";

    ClientRecord += NewClient.AccountNumber + Seperator;
    ClientRecord += NewClient.PinCode + Seperator;
    ClientRecord += NewClient.Name + Seperator;
    ClientRecord += NewClient.PhoneNumber + Seperator;
    ClientRecord += to_string(NewClient.AccountBalance);

    return ClientRecord;
}

void AddDataLineToFile(string FileName, string stDataClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if(MyFile.is_open())
    {
        MyFile << stDataClient << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client;
    cout << "Adding New Client: \n\n";
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system( "cls" );
        AddNewClient();
        cout << "\nClient Added Successfuly, Do you want to add more clients? Y/N?";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
    
}
int main()
{
    AddClients();
    return 0;
}
