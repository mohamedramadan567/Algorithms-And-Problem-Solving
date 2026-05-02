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

void PrintClientRecord(stClient Client)
{
    cout << "\nThe following is the extracted client records:\n\n";
    cout << "Account Number : " << Client.AccountNumber << "\n";
    cout << "Pin Code       : " << Client.PinCode << "\n";
    cout << "Name           : " << Client.Name << "\n";
    cout << "Phone          : " << Client.PhoneNumber << "\n";
    cout << "Account Balance: " << Client.AccountBalance << "\n";
}

int main()
{
    string Line = "A150#//#1234#//#Mohammed Ramadan#//#079999#//#5270.000000";
    cout << "Line Record is: \n" << Line << endl;
    stClient Client = ConvertLineDataToRecord(Line);
    PrintClientRecord(Client);

    return 0;
}
