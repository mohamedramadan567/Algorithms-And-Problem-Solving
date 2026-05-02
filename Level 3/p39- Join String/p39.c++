#include <bits/stdc++.h>
using namespace std;

string JoinString(vector<string>vString, string delim)
{
    string S = "";
    for (short i = 0; i < vString.size(); i++)
    {
        if(i == vString.size() - 1)
        {
            S += vString[i];
        }
        else
        {
            S = S + vString[i] + delim;
        }
    }
    return S;
}

//another solution
string JoinString2(vector<string>vString, string delim)
{
    string S = "";
    for(string& s : vString)
    {
        S += s + delim;
    }
    return S.substr(0, S.size() - delim.length());
}

int main()
{
    vector<string>vString {"Mohammed", "Faid", "Ali", "Maher"};
    string S;
    S = JoinString2(vString, " ");
    cout << "\nVector after join: \n";
    cout << S << endl;
    return 0;
}