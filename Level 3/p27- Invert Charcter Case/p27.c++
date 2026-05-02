#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char ReadChar()
{
    char C;
    cout << "Please enter a Charcter? \n";
    cin >> C;
    return C;
}

char InvertLetterCase(char C1)
{
    return isupper(C1)? tolower(C1): toupper(C1);
}

int main()
{
    char C1 = ReadChar();
    C1 =  InvertLetterCase(C1);
    cout << "\nChar after Inverting Case:\n";
    cout << C1 << endl;
    return 0;
}
