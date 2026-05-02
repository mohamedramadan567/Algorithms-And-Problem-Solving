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


//My solution but founded test cases failed
bool mIsPeriodsOverLap(stPeriod Period1, stPeriod Period2)
{
    if(IsDate1AfterDate2(Period2.StartDate, Period1.StartDate) && IsDate1AfterDate2(Period1.EndDate, Period2.StartDate))
    return true;
    if(IsDate1AfterDate2(Period1.StartDate, Period2.StartDate) && IsDate1AfterDate2(Period2.EndDate, Period1.StartDate))
    return true;
    if(IsDat1EqualDate2(Period1.StartDate, Period2.StartDate) && IsDat1EqualDate2(Period1.EndDate, Period2.EndDate))
    return true;

    return false;
}


// teacher solution
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
    stPeriod Period1, Period2;
    cout << "Enter Period 1:\n";
    Period1 = ReadPeriod();

    cout << "\nEnter Period 2:\n";
    Period2 = ReadPeriod();
    
    if(IsPeriodsOverLap(Period1, Period2))
    cout << "\nYes, Periods OverLap\n";
    else
    cout << "\nNo, Periods do not OverLap";


    return 0;
}
