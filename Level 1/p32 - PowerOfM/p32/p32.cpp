#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int ReadNumber()
{
    int Num;
    cout << "Please enter a number\n";
    cin >> Num;
    return Num;
}
int ReadPower()
{
    int Power;
    cout << "Please enter a power\n";
    cin >> Power;
    return Power;
}
int PowerOfM(int Power, int Num)
{
    int PowerOfM = 1;
    if (Power == 0)
        return 1;
    else 
    {
        for (int i = 1; i <= Power; i++)
        {
            PowerOfM *= Num;
        }
        return PowerOfM;
    }
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Result = " << PowerOfM(ReadPower(), ReadNumber()) << endl;
    return 0;
}