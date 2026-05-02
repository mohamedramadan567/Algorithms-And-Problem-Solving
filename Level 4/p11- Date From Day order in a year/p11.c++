#include <bits/stdc++.h>
using namespace std;

short ReadYear()
{
    short Number;
    cout << "Please enter a year? ";
    cin >> Number;
    return Number;
}

short ReadMonth()
{
    short Number;
    cout << "Please enter a Month? ";
    cin >> Number;
    return Number;
}

short ReadDay()
{
    short Number;
    cout << "Please enter a Day? ";
    cin >> Number;
    return Number;
}

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDaysInAMonth(short year, short month)
{
    if(month < 1 || month > 12)
    return 0;

    // teacher solution
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short sum = 0;
    for(short i = 1; i < Month; i++)
    {
        sum+= NumberOfDaysInAMonth(Year, i);
    }
    return (sum + Day);
}

struct sDate 
{
    short Day, Month, Year;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    Date.Year = Year;
    short MonthDays = 0;
    Date.Month = 1;

    while(true)
    {
        MonthDays = NumberOfDaysInAMonth(Year, Date.Month);
        if(RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short DateOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
    
    cout << "\nNumber of Days from the begining of the year is " << DateOrderInYear << endl << endl;
    
    sDate Date = GetDateFromDayOrderInYear(DateOrderInYear, Year);
    cout << "Date for [" << DateOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    return 0;
}