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

sDate DecreaseDateByOneDay(sDate Date)
{
    if(Date.Day == 1)
    {
        if(Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else 
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
        }
    }
    else 
    Date.Day--;

    return Date;

}

sDate DecreaseDateByXDays(sDate Date, short Days)
{
    for(short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    Date = DecreaseDateByXDays(Date, 7);
    return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, short Weeks)
{
    for(short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if(Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else 
    {
        Date.Month--;
    }


    //last check day in date should not exceed max days in the current month
    // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    // be 28/2/2022

    int NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate DecreaseDateByXMonths(sDate Date, short Months)
{
    for(short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYears(sDate Date, short Years)
{
    for(short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, short Years)
{
    Date.Year -= Years;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year-= 10;
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, short Decades)
{
    for(short i = 1; i <= Decades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, short Decades)
{
    Date.Year -= Decades * 10;
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year-= 100;
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year-= 1000;
    return Date;
}



int main()
{
    sDate Date = ReadFullDate();
    

    cout << "\nDate after: \n";

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01-Substracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Substracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Substracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Substracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Substracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Substracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Substracting one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08-Substracting 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Substracting 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Substracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "\n11-Substracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "\n12-Substracting 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13-Substracting one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n13-Substracting one Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}