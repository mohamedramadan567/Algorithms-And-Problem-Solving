#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string Sentence;
    cout << "Please enter your sting? \n";
    getline(cin, Sentence);
    return Sentence;
}

string UpperFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;
    for (short i = 0; i < S1.size(); i++)
    {
        if(S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = toupper(S1[i]);
            
        }
        IsFirstLetter = (S1[i] == ' '? true : false);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();

    S1 = UpperFirstLetterOfEachWord(S1);

    cout << "\nString after conversion: \n";
    cout << S1 << endl;
    

    
    return 0;
}