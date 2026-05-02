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

char InvertLetterCase(char C1)
{
    return isupper(C1)? tolower(C1): toupper(C1);
}

string InvertAllStringLettersCase(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    S1 = InvertAllStringLettersCase(S1);
    cout << "\nChar after Inverting Case:\n";
    cout << S1 << endl;
    return 0;
}
