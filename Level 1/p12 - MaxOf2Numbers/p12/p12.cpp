#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void ReadNumbers(int& Num1, int& Num2)
{
    cout << "Please enter your number 1 ?" << endl;
    cin >> Num1;
    cout << "Please enter your number 2 ?" << endl;
    cin >> Num2;
}
int FindMax(int Num1, int Num2)
{
    if (Num1 >= Num2)
        return Num1;
    else
        return Num2;
}
void PrintResults(int Max)
{
    cout << "Max of two numbers is : " << Max << endl;
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Num1, Num2;
    ReadNumbers(Num1, Num2);
    PrintResults(FindMax(Num1, Num2));

    return 0;
}