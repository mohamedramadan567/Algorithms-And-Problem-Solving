#include <bits/stdc++.h>

using namespace std;

string ReadString()
{
    string S;
    cout << "Please enter your string?\n";
    getline(cin, S);
    return S;
}

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

int main()
{
    string S1 = "Welcome to Egypt, Egypt is a nice country";
    string StringToReplace = "Egypt";
    string ReplaceTo = "USA";

    cout << "\nOriginal String: \n" << S1 << endl;

    cout << "\n\nString After Replace: \n" << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo) << endl;
    
    return 0;
}
