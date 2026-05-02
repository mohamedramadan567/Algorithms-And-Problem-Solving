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

short DayOfWeekOrder(sDate Date)
{
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;
    short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;

}

string DayShortName(short DayOfWeekOrder)
{
    string arrOfDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrOfDayNames[DayOfWeekOrder];
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

bool IsWeekEnd(sDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}


//My Solution
sDate MCalculateVacationReturnDate(sDate Date, short VactionDays)
{
    while (VactionDays)
    {
        if(!IsWeekEnd(Date)) 
        {
            VactionDays--;
            
        }
        Date = IncreaseDateByOneDay(Date);
    }
    // The part i am wrong it.
    while(IsWeekEnd(Date))
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
    
}

//Teacher Solution
sDate CalculateVacationReturnDate(sDate Date, short VactionDays)
{
    short WeekEndCounter = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
    while(IsWeekEnd(Date))
    {
        Date = IncreaseDateByOneDay(Date);
    }

    //here we increase the vacation dates to add all weekends to it.

    for(short i = 1; i <= VactionDays + WeekEndCounter; i++)
    {
        if(IsWeekEnd(Date))
        WeekEndCounter++;

        Date = IncreaseDateByOneDay(Date);
    }

    //in case the return date is week end keep adding one day util you reach business day
    while(IsWeekEnd(Date))
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

short ReadVacationDays()
{
    short Number;
    cout << "\nPlease enter vacation days? ";
    cin >> Number;
    return Number;
}

int main()
{
    cout << "Vecation Starts:\n";
    sDate DateFrom = ReadFullDate();
    
    short VactionDays = ReadVacationDays();

    DateFrom = MCalculateVacationReturnDate(DateFrom, VactionDays);

    string DayName = DayShortName(DayOfWeekOrder(DateFrom));
    
    cout << "\nReturn Date: " << DayName << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;
    
    return 0;
}
