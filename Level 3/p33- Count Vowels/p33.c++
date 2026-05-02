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

bool IsVowel(char c)
{
    c = tolower(c);
    return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}

short CountVowels(string s)
{
    short CountVowel = 0;
    for (short i = 0; i < s.size(); i++)
    {
        if (IsVowel(s[i]))
            CountVowel++;
    }
    return CountVowel;
}

int main()
{
    string s = ReadString();
    cout << "Number of vowels is: " << CountVowels(s) << endl;
    return 0;
}