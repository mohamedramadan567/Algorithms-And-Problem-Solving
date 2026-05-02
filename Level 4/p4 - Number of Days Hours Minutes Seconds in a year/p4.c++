#include <bits/stdc++.h>
using namespace std;

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

int NumberOfDaysInAYear(short year)
{
    return (IsLeapYear(year)) ? 366 : 365;
}

int NumberOfHoursInAYear(short year)
{
    return NumberOfDaysInAYear(year) * 24;
}

int NumberOfMinutesInAYear(short year)
{
    return NumberOfHoursInAYear(year) * 60;
}

int NumberOfSecondsInAYear(short year)
{
    return NumberOfMinutesInAYear(year) * 60;
}

short ReadYear()
{
    short Number;
    cout << "Please enter a year to check? ";
    cin >> Number;
    return Number;
}


int main()
{
    short Year = ReadYear();

    cout << "Number of Days      in year [" << Year << "] is " << NumberOfDaysInAYear(Year) << endl;
    cout << "Number of Hours     in year [" << Year << "] is " << NumberOfHoursInAYear(Year) << endl;
    cout << "Number of Minutes   in year [" << Year << "] is " << NumberOfMinutesInAYear(Year) << endl;
    cout << "Number of Seconds   in year [" << Year << "] is " << NumberOfSecondsInAYear(Year) << endl;
    


    return 0;
}