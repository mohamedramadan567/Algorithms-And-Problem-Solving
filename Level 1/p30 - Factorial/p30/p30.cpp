#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int ReadPositiveNumber(string s)
{
    int Num;
    do
    {
        cout << s << endl;
        cin >> Num;
    } while (Num < 0);
    return Num;

}

int Factorial(int Num)
{
    int fact = 1;
    for (int i = 1; i <= Num; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << Factorial(ReadPositiveNumber("Enter Positive Number?"));
    return 0;
}