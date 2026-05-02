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

short NumberOfDaysInAYear(short year)
{
    return (IsLeapYear(year)) ? 366 : 365;
}

short NumberOfDaysInAMonth(short year, short month)
{
    if(month < 1 || month > 12)
    return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

bool IsLastDayInMonth(sDate Date1)
{
    return (Date1.Day == NumberOfDaysInAMonth(Date1.Year, Date1.Month));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

//My Solution: The best
bool IsValideDate(sDate Date1)
{
    return ((Date1.Day >= 1 && Date1.Day <= NumberOfDaysInAMonth(Date1.Year, Date1.Month)) && Date1.Month >= 1 && Date1.Month <= 12);
}

//Teacher Solution
bool AIsValideDate(sDate Date1)
{
    if(Date1.Day > 31 || Date1.Day < 1)
    return false;
    if(Date1.Month > 12 || Date1.Month < 1)
    return false;

    if(Date1.Month == 2)
    {
        if(IsLeapYear(Date1.Year))
        {
            if(Date1.Day > 29)
            return false;
        }
        else
        {
            if(Date1.Day > 28)
            return false;
        }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date1.Year, Date1.Month);
    if(DaysInMonth < Date1.Day)
    return false;

    return true;

}

int main()
{
    sDate Date1 = ReadFullDate();
    
    if(IsValideDate(Date1))
    cout << "Yes, Date is a valide date.\n";
    else
    cout << "No, Date is a NOT valide date.\n";

    return 0;
}
