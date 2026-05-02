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

sDate IncreaseDateByXDay(sDate Date, short Days)
{
    for(short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    Date = IncreaseDateByXDay(Date, 7);
    return Date;
}

sDate IncreaseDateByXWeek(sDate Date, short Weeks)
{
    for(short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    if(Date.Month == 12)
    {
        Date.Month == 1;
        Date.Year ++;
    }
    else 
    {
        Date.Month++;
    }

    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    // be 28/2/2022
    
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, short Months)
{
    for(short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}

sDate IncreaseDateByXYears(sDate Date, short Years)
{
    for(short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXYearsFaster(sDate Date, short Years)
{
    Date.Year += Years;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}

sDate IncreaseDateByXDecades(sDate Date, short Decades)
{
    for(short i = 1; i <= Decades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXDecadesFaster(sDate Date, short Decades)
{
    Date.Year += Decades * 10;
    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}

void PrintIncreasingDate(sDate Date)
{
    cout << "\nDate After:\n";
    Date = IncreaseDateByOneDay(Date);
    printf("\n%02d-Adding one day is: %d/%d/%d", 1, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDay(Date, 10);
    printf("\n%02d-Adding 10 days is: %d/%d/%d", 2, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneWeek(Date);
    printf("\n%02d-Adding one week is: %d/%d/%d", 3, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXWeek(Date, 10);
    printf("\n%02d-Adding 10 weeks is: %d/%d/%d", 4, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneMonth(Date);
    printf("\n%02d-Adding one month is: %d/%d/%d", 5, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXMonths(Date, 5);
    printf("\n%02d-Adding 5 months is: %d/%d/%d", 6, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneYear(Date);
    printf("\n%02d-Adding one year is: %d/%d/%d", 7, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYears(Date, 10);
    printf("\n%02d-Adding 10 years is: %d/%d/%d", 8, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYearsFaster(Date, 10);
    printf("\n%02d-Adding 10 years (faster) is: %d/%d/%d", 9, Date.Day, Date.Month, Date.Year);
    
    Date = IncreaseDateByOneDecade(Date);
    printf("\n%02d-Adding one Decade is: %d/%d/%d", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecades(Date, 10);
    printf("\n%02d-Adding 10 Decades is: %d/%d/%d", 11, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    printf("\n%02d-Adding 10 Decades (faster) is: %d/%d/%d", 12, Date.Day, Date.Month, Date.Year);
    
    Date = IncreaseDateByOneCentury(Date);
    printf("\n%02d-Adding one Century is: %d/%d/%d", 13, Date.Day, Date.Month, Date.Year);
    
    Date = IncreaseDateByOneMillennium(Date);
    printf("\n%02d-Adding one Millennium is: %d/%d/%d", 14, Date.Day, Date.Month, Date.Year);

}

int main()
{
    sDate Date = ReadFullDate();
    
    PrintIncreasingDate(Date);

    return 0;
}