#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include <string>

using namespace std;

string ReadString()
{
    string Sentence;
    cout << "Please enter your sting? \n";
    getline(cin, Sentence);
    return Sentence;
}

void PrintFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;
    cout << "\nFirst Letters of the string: \n";
    for (int i = 0; i < S1.size(); i++)
    {
        if(S1[i] != ' ' && IsFirstLetter)
        {
            cout << S1[i] << endl;
        }
        IsFirstLetter = (S1[i] == ' '? true : false);
    }
}

int main()
{
    PrintFirstLetterOfEachWord(ReadString());
    return 0;
}
