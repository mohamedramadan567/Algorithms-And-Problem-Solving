#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int ReadTotalSales()
{
    int Sales;
    cout << "Please enter total sales ?" << endl;
    cin >> Sales;
    return Sales;
}
float GetCommationPercentage(int Sales)
{
    if (Sales > 1000000)
        return 0.01;
    else if (Sales > 500000)
        return 0.02;
    else if (Sales > 100000)
        return 0.03;
    else if (Sales > 50000)
        return 0.05;
    else
        return 0.00;
}
float CalculateTotalCommation(int Sales)
{
    return (GetCommationPercentage(Sales) * Sales);
}
int main()
{
    //MR1;
    
    int p = ReadTotalSales();
    cout << "Percentage : " << GetCommationPercentage(p) << endl;
    cout << "Total comission : " << CalculateTotalCommation(p) << endl;
    return 0;
}