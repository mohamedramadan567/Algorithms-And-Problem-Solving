#include <bits/stdc++.h>

using namespace std;

string ReadString()
{
    string S1;
    cout << "Please enter your string? \n";
    getline(cin, S1);
    return S1;
}

char ReadChar()
{
    char C;
    cout << "Please enter a Charcter? \n";
    cin >> C;
    return C;
}

void PrintWords(string s)
{
    string delim = " ";
    int pos = 0;
    string sWord;
    cout << "\nYour string words are: \n\n";
    while((pos = s.find(" ")) != std::string::npos)
    {
        sWord = s.substr(0, pos);
        if(sWord != " ")
        {
            cout << sWord << endl;
        }
        s.erase(0, pos + delim.length());
    }
    if(s != "")
    {
        cout << s << endl;
    }
    
} 

int main()
{
    PrintWords(ReadString());
    return 0;
}