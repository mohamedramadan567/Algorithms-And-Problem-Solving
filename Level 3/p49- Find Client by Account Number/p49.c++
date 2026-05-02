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

string ReadClientAccountNumber()
{
    string AccountNumber;
    cout << "Please Enter Account Number? ";
    getline(cin, AccountNumber);
    return AccountNumber;
}

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

bool FindClientByAccountNumber(string AccountNumber , stClient& Client)
{
    vector<stClient>vClients = LoadDataFromFile(ClientsFileName);
    for(stClient& C : vClients)
    {
        if(C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe Following are the Client details:\n\n";
    cout << "Account Number  : " << Client.AccountNumber << "\n";
    cout << "Pin Code        : " << Client.PinCode << "\n";
    cout << "Name            : " << Client.Name << "\n";
    cout << "Phone           : " << Client.PhoneNumber << "\n";
    cout << "Account Balance : " << Client.AccountBalance << "\n";
}

int main()
{
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if(FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n"; 
    }
    return 0;
}
