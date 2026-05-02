#include <bits/stdc++.h>

using namespace std;

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

    cout << "Enter Account Number? " ;
    getline(cin, NewClient.AccountNumber);

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

int main()
{
    cout << "Please enter client Data: \n\n";

    stClient Client;
    Client = ReadNewClient();
    
    cout << ConvertRecordToLine(Client);
    
    return 0;
}
