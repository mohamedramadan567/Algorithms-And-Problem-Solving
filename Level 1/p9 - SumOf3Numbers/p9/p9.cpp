#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
//#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void ReadNumbers(int& Num1,int& Num2,int& Num3)
{
    cout << "Please enter your number 1 ?" << endl;
    cin >> Num1;
    cout << "Please enter your number 2 ?" << endl;
    cin >> Num2;
    cout << "Please enter your number 3 ?" << endl;
    cin >> Num3;
}
int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}
void PrintResults(int total)
{
    cout << "\nThe total of 3 numbers is : " << total << endl;
}
int main()
{
    //MR1
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Num1, Num2, Num3;
    ReadNumbers(Num1, Num2, Num3);
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));

    return 0;
}