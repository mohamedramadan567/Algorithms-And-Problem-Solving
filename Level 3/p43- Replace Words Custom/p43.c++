//I can't Solve it

#include <bits/stdc++.h>
using namespace std;

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

string JoinString(vector<string>vString, string delim)
{
    string S = "";
    for(string& s : vString)
    {
        S = S + s + delim;
    }
    return S.substr(0, S.size() - delim.length());
}

string LowerAllString(string S)
{
    for(int i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    return S;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");

    for (string& s : vString)
    {
        if(MatchCase)
        {
            if(s == StringToReplace)
            {
                s = sReplaceTo;
            }
        }
        else
        {
            if(LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sReplaceTo;
            }
        }
    }

    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome to Egypt , Egypt is a nice country";
    string StringToReplace = "egypt";
    string ReplaceTo = "USA";

    cout << "\nOriginal String: \n" << S1 << endl;


    cout << "\n\nReplace with match case: \n";
    cout <<  ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

    cout << "\n\nRelace with dont match case: \n";
    cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;

    
    return 0;
}
