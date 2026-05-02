#include <bits/stdc++.h>
using namespace std;

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

int NumberOfDaysInAMonth(short year, short month)
{
    if(month < 1 || month > 12)
    return 0;

    if(month == 2)
    {
        return IsLeapYear(year)? 29 : 28;
    }

    short arr31Days[] = { 1, 3, 5, 7, 8, 10, 12 };
    for(short i = 0; i < 7; i++)
    {
        if(arr31Days[i] == month)
        return 31;
    }

    return 30;
}

int NumberOfHoursInAMonth(short year, short month)
{
    return NumberOfDaysInAMonth(year, month) * 24;
}

int NumberOfMinutesInAMonth(short year, short month)
{
    return NumberOfHoursInAMonth(year, month) * 60;
}

int NumberOfSecondsInAMonth(short year, short month)
{
    return NumberOfMinutesInAMonth(year, month) * 60;
}

short ReadYear()
{
    short Number;
    cout << "Please enter a year to check? ";
    cin >> Number;
    return Number;
}

short ReadMonth()
{
    short Number;
    cout << "Please enter a Month to check? ";
    cin >> Number;
    return Number;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "Number of Days      in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month) << endl;
    cout << "Number of Hours     in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year, Month) << endl;
    cout << "Number of Minutes   in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month) << endl;
    cout << "Number of Seconds   in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month) << endl;
    


    return 0;
}