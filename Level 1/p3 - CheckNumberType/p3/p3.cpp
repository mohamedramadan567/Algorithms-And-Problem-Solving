#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
enum enNumberType { Even = 1, Odd = 2 };
int ReadNumber()
{
    int num;
    cout << "Please Enter Number ? " << endl;
    cin >> num;
    return num;
}
enNumberType CheckNumberType(int num)
{
    int result=num%2;
    if (result == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}
void PrintNumberType(enNumberType CheckNumberType)
{
    if (CheckNumberType == enNumberType::Even)
        cout << "\nNumber is Even " << endl;
    else
        cout << "\nNumber is Odd " << endl;
}
int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}