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

string UpperAllString(string S1)
{
    for (short i = 0; i < S1.size(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.size(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    S1 = UpperAllString(S1);
    cout << "\nString after Upper:\n";
    cout << S1 << endl;
    S1 = LowerAllString(S1);
    cout << "\nString after Lower:\n";
    cout << S1 << endl;
    return 0;
}
