#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadString()
{
    string Sentence;
    cout << "Please enter your sting? \n";
    getline(cin, Sentence);
    return Sentence;
}

string LowerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (short i = 0; i < S1.size(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    S1 = LowerFirstLetterOfEachWord(S1);
    cout << "\nString after conversion:\n";
    cout << S1 << endl;
    return 0;
}
