#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
string ReadName()
{
    string Name;
    cout << "Enter Your Name : ";
    getline(cin, Name);
    return Name;
}
void PrintName(string Name)
{
    cout << "Name is : " << Name << endl;
}
int main()
{

    PrintName(ReadName());
    return 0;
}