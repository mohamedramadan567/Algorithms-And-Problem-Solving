#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include <cstdio>

using namespace std;

void PrintFibonacciSeriesUsingLoop(short Number)
{

	int Prev1 = 1;
	int Prev2 = 0;

	for (int i = 0; i < Number; i++) 
    {
		int FiboNumber = Prev1 + Prev2;
		cout << FiboNumber << '\t';
		Prev1 = Prev2;
		Prev2 = FiboNumber;
	}
}

int main()
{
    PrintFibonacciSeriesUsingLoop(5);
    return 0;
}
