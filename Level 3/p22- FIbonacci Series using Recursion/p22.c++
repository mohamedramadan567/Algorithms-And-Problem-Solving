#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include <cstdio>

using namespace std;

void PrintFibonacciUsingRecursion(int Number, int prev1, int prev2)
{
    int FibNumber = 0;
    if (Number > 0)
    {
        FibNumber = prev2 + prev1;
        prev2 = prev1;
        prev1 = FibNumber;
        cout << FibNumber << "\t";
        PrintFibonacciUsingRecursion(Number - 1, prev1, prev2);
    }
}

int main()
{
    PrintFibonacciUsingRecursion(10, 0, 1);
    return 0;
}