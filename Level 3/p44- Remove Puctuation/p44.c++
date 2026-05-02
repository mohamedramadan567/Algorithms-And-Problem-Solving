#include <bits/stdc++.h>
#include <string>
using namespace std;

string RemovePunctuation(string S1)
{
    int pos;
    for(int i = 0; i < S1.length(); i++)
    {
        if(ispunct(S1[i]))
        {
            pos = i;
            S1.erase(pos, 1);
        }
    }
    return S1;

    // another solution
    string S2 = "";
    for(int i = 0; i < S1.length(); i++)
    {
        if(!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

int main()
{
    string S1 = "Welcome to Egypt, Egypt is a nice country; it's amazing.";
    
    cout << "\nOriginal String: \n" << S1 << endl;

    
    cout << "\n\nPunctuation Removed: \n";
    cout << RemovePunctuation(S1) << endl;
    

    
    return 0;
}
