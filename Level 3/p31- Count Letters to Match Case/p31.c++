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

char InvertLetterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

short CountLetter(string S, char Letter, bool MatchCase = true)
{
    short Count = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if(MatchCase)
        {

            if (S[i] == Letter)
                Count++;
        }
        else
        {
            if (tolower(S[i]) == tolower(Letter))
                Count++;
        }

    }
    return Count;
}

int main()
{
    string S1 = ReadString();
    char C1 = ReadChar();
    cout << "\nLetter '" << C1 << "' Count = " << CountLetter(S1, C1) << endl;
    cout << "Letter '" << C1 << "' Or '" << InvertLetterCase(C1) << "' Count = " << CountLetter(S1, C1, false) << endl;
    return 0;
}