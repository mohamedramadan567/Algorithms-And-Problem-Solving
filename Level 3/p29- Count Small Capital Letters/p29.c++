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

enum enWhatIsSCount { SmallLetters = 1, CapitalLetters = 2, All = 3 };

short CountLetters(string S, enWhatIsSCount WhatIsCount)
{
    short Count = 0;
    if(WhatIsCount == enWhatIsSCount::All)
    return S.length();
    for (int i = 0; i < S.length(); i++)
    {
        if (WhatIsCount == enWhatIsSCount::SmallLetters && islower((S[i])))
            Count++;
        else if (WhatIsCount == enWhatIsSCount::CapitalLetters && isupper((S[i])))
            Count++;
    }
    return Count;
}

short CountCapital(string S1)
{
    short Capital = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Capital++;
    }
    return Capital;
}

short CountSmall(string S1)
{
    short Small = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Small++;
    }
    return Small;
}

int main()
{
    string S1 = ReadString();
    cout << "\nString length = " << S1.length() << endl;
    cout << "Capital Letters Count = " << CountCapital(S1) << endl;
    cout << "Small Letters Count = " << CountSmall(S1) << endl;

    cout << "\n\nMethod 2:\n";
    cout << "\nString length = " << CountLetters(S1, enWhatIsSCount::All) << endl;
    cout << "Capital Letters Count = " << CountLetters(S1, enWhatIsSCount::CapitalLetters) << endl;
    cout << "Small Letters Count = " << CountLetters(S1, enWhatIsSCount::SmallLetters) << endl;
    return 0;
}
