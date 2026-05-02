//I can't Solve it
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

string TrimLeft(string S)
{
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] != ' ')
        {
            return S.substr(i, S.length() - i);
        }
    }
    return "";
}

string TrimRight(string S)
{
    for(int i = S.length() - 1; i >= 0; i--)
    {
        if(S[i] != ' ')
        {
            return S.substr(0, i + 1);
        }
    }
    return "";
}

string Trim(string S)
{
    return TrimLeft(TrimRight(S));
}

int main()
{
    string S = "     Mohammed Ramadan    ";
    cout << "\nString       = " << S << endl << endl;
    cout << "Trim Right   = " << TrimRight(S) << endl;
    cout << "Trim Left    = " << TrimLeft(S) << endl;
    cout << "Trim         = " << Trim(S) << endl;
    return 0;
}