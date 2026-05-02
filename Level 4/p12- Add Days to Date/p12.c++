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

short ReadDaysToAdd()
{
    short Number;
    cout << "How many days to add? ";
    cin >> Number;
    return Number;
}

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

int NumberOfDaysInAYear(short year)
{
    return (IsLeapYear(year)) ? 366 : 365;
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

sDate GetAddDate(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;

    while(true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);
        if(RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if(Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();
    
    Date = GetAddDate(Days, Date);
    cout << "Date after adding [" << Days << "] days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    return 0;
}