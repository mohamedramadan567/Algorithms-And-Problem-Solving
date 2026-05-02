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

vector<string>SplitString(string s, string delim)
{
    vector<string>vString;
    int pos = 0;
    string sWord;
    // use find() function to get the position of the delimiters
    while((pos = s.find(delim)) != std::string::npos)
    {
        sWord = s.substr(0, pos);
        if(sWord != " ")
        {
            vString.push_back(sWord);
        }
        //erase() until positon and move to next word.
        s.erase(0, pos + delim.length());
    }
    if(s != "")
    {
        vString.push_back(s);
    }
    return vString;
}

stClient ConvertLineDataToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;

    vector<string>vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

vector<stClient>LoadDataFromFile(string FileName)
{
    fstream MyFile;
    vector<stClient>vClients;
    MyFile.open(FileName, ios::in);
    if(MyFile.is_open())
    {
        string Line;
        stClient Client;
        while(getline(MyFile, Line))
        {
            Client = ConvertLineDataToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    
    return vClients;
}

void PrintClientData(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.PhoneNumber;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintAllClientsData(vector<stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() <<") Client(s).";
    cout << "\n_______________________________________________________";     
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";     
    cout << "_________________________________________\n" << endl;

    for(stClient& Client : vClients)
    {
        PrintClientData(Client);
        cout << endl;
    }
    cout << "_______________________________________________________";     
    cout << "_________________________________________\n" << endl;
}

int main()
{
    vector<stClient>vClients = LoadDataFromFile(ClientsFileName);
    PrintAllClientsData(vClients);
    return 0;
}