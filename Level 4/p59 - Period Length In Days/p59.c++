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

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

enum enCompareDates { Before = -1, Equal = 0, After = 1 };

bool IsDat1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDat1EqualDate2(Date1, Date2));
}

short CompareDates(sDate Date1, sDate Date2)
{
    if(IsDat1EqualDate2(Date1, Date2))
    return enCompareDates::Equal;

    if(IsDate1BeforeDate2(Date1, Date2))
    {
        return enCompareDates::Before;
    }

    // This is Solwer
    /* if (IsDate1AfterDate2(Date1,Date2))
    return enDateCompare::After;*/

    return enCompareDates::After;
}

bool IsPeriodsOverLap(stPeriod Period1, stPeriod Period2)
{
    if  (
        CompareDates(Period1.EndDate, Period2.StartDate) == enCompareDates::Before
        ||
        CompareDates(Period1.StartDate, Period2.EndDate) == enCompareDates::After
        )
        return false;
    else 
        return true;
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

    // teacher solution
    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
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

int GetDiffrenceInDays(sDate Date1, sDate Date2, bool EncludedEndDay = false)
{
    int Days = 0;
    while(IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return (EncludedEndDay) ? ++Days : Days;
}

int PeriodLengthInDays(stPeriod Period, bool EncludedEndDay = false)
{
    return GetDiffrenceInDays(Period.StartDate, Period.StartDate, EncludedEndDay);
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "Enter Start Date:\n\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

int main()
{
    stPeriod Period1;
    cout << "Enter Period 1:\n";
    Period1 = ReadPeriod();
 
    //My Solution
    cout << "\nPeriod Length is: " << GetDiffrenceInDays(Period1.StartDate, Period1.EndDate);
    cout << "\nPeriod Length (Including End Day) is: " << GetDiffrenceInDays(Period1.StartDate, Period1.EndDate, true);

    //Teacher Solution
    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
    cout << "\nPeriod Length (Including End Day) is: " << PeriodLengthInDays(Period1, true);



    return 0;
}
