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
    return((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}

int main()
{
    char c = ReadChar();
    if(IsVowel(c)) 
        cout << "YES Letter '" << c << "' is Vowel" <<endl;
    else 
        cout << "NO Letter '" << c << "' is NOT Vowel" <<endl;

    return 0;
}