#include <bits/stdc++.h>

using namespace std;

string ReadString()
{
    string S;
    cout << "Please enter your string?\n";
    getline(cin, S);
    return S;
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

string ReverseString(string S1)
{
    vector<string> vString;
    string S2 = "";
    vString = SplitString(S1, " ");

    vector<string>::iterator iter = vString.end();

    while(iter != vString.begin())
    {
        --iter;
        S2+= *iter+ " ";
    }
    return S2.substr(0, S2.length() - 1);
}

int main()
{
    string S1 = ReadString();
    cout << "\n\nString after reversing words: \n";
    cout << ReverseString(S1) << endl;
    
    return 0;
}
