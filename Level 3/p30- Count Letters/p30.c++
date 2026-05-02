#include <iostream>
#include <cctype>
#include <string>

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

short CountLetter(string S, char C)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == C)
            Count++;
    }
    return Count;
}

int main()
{
    string S1 = ReadString();
    char C1 = ReadChar();

    cout << "\nLetter '" << C1 << "' Count = " << CountLetter(S1, C1) << endl;
    return 0;
}