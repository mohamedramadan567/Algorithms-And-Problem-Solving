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
    bool MarkForDelete = false;
};

string ReadAccountNumber()
{
    string AccountNumber;
    cout << "Please enter Account Number? ";
    cin >> AccountNumber;
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

bool FindClientByAccountNumber(string AccountNumber , stClient& Client, vector<stClient>vClients)
{
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    for(stClient& C : vClients)
    {
        if(C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector<stClient>SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); //overwrite

    string DataLine;

    if(MyFile.is_open())
    {
        for(stClient C : vClients)
        {
            if(C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';
    if(FindClientByAccountNumber(AccountNumber, Client, vClients))
    {
        PrintClientCard(Client);
        cout << "\nAre you sure you want to delete this client? Y/N? ";
        cin >> Answer;
        if(toupper(Answer) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients
            vClients = LoadDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n"; 
        return false;
    }
}

int main()
{
    vector<stClient>vClients = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
    
    return 0;
}