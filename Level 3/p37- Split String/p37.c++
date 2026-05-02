//i can't solve it
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

int main()
{
    //string s = ReadString();
    vector<string>vString = SplitString(ReadString(), " ");
    cout << "\nTokens = " << vString.size() << endl;
    for(string& s : vString)
    {
        cout << s << endl;
    }
    
    return 0;
}