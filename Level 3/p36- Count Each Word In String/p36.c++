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

short CountWords(string s)
{
    string delim = " "; // delimiter
    int pos = 0;
    string sWord;
    short CountWords = 0;
    // use find() function to get the position of the delimiters
    while((pos = s.find(" ")) != std::string::npos)
    {
        sWord = s.substr(0, pos);
        if(sWord != " ")
        {
            CountWords++;
        }
        //erase() until positon and move to next word.
        s.erase(0, pos + delim.length());
    }
    if(s != "")
    {
        CountWords++;
    }
    return CountWords;
} 

int main()
{
    string s = ReadString();
    cout << "\nThe Number of words in your string is: ";
    cout << CountWords(s);
    return 0;
}