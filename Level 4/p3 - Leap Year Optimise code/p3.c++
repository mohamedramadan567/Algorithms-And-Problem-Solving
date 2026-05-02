#include <bits/stdc++.h>
using namespace std;

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

short ReadNumber()
{
    short Number;
    cout << "Enter a Year: ";
    cin >> Number;
    return Number;
}


int main()
{
    short Year = ReadNumber();
    if(IsLeapYear(Year)) 
    cout << "\nYes, Year [" << Year << "] is a leap year" << endl;
    else 
    cout << "\nNO, Year [" << Year << "] is NOT a leap year" << endl;

    return 0;
}