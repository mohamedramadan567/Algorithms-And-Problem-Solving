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

int main()
{
    sDate Date1 = ReadFullDate();
    cout << endl << endl;
    sDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2);
    return 0;
}
