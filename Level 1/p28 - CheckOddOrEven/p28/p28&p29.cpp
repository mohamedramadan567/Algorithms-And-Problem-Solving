#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
enum enEvenOrOdd { Odd = 1, Even = 2 };
int ReadNumber()
{
    int Num;
    cout << "Please enter Number ?" << endl;
    cin >> Num;
    return Num;

}
enEvenOrOdd CheckOddOrEven(int Num)
{
    if (Num % 2 != 0)
        return enEvenOrOdd::Odd;
    else
        return enEvenOrOdd::Even;
}
void PrintNumbers(int Num)
{
    int sum = 0;
    cout << "\nSum of Even numbers from 1 to " << Num << " is : " << endl;
    for (int i = 1; i <= Num; i++)
    {
        if (CheckOddOrEven(i) == enEvenOrOdd::Even)
            sum += i;
    }
    cout << sum << endl;
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PrintNumbers(ReadNumber());

    return 0;
}