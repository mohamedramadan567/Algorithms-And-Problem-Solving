#include <bits/stdc++.h>
using namespace std;

string JoinString(string arrString[], int length, string delim)
{
    string S = "";
    for (int i = 0; i < length; i++)
    {
        S = S + arrString[i] + delim;
    }
    return S.substr(0, S.size() - delim.length());
}

string JoinString(vector<string>vString, string delim)
{
    string S = "";
    for(string& s : vString)
    {
        S = S + s + delim;
    }
    return S.substr(0, S.size() - delim.length());
}

int main()
{
    vector<string>vString {"Mohammed", "Faid", "Ali", "Maher"};

    string arrString[] = {"Mohammed", "Faid", "Ali", "Maher"};
    
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ") << endl;

    cout << "\n\nArray after join: \n";
    cout << JoinString(arrString, 4, " ") << endl;
    return 0;
}