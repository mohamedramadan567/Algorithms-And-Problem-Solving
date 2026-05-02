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

struct sDate 
{
    short Day, Month, Year;
};

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
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

bool IsLastDayInMonth(short Day, short Month, short Year)
{
    return (Day == NumberOfDaysInAMonth(Year, Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if(IsLastDayInMonth(Date.Day, Date.Month, Date.Year)) 
    {
        Date.Day = 1;
        if(IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        Date.Month++;
    }
    else 
    {
        Date.Day++;
    }

    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    
    Date = IncreaseDateByOneDay(Date);
    cout << "\nDate after adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    return 0;
}