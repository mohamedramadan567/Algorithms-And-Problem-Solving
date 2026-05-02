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

sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* m = localtime(&t);

    Date.Year = m->tm_year + 1900;
    Date.Month = m->tm_mon + 1;
    Date.Day = m->tm_mday;

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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short sum = 0;
    for(short i = 1; i < Month; i++)
    {
        sum+= NumberOfDaysInAMonth(Year, i);
    }
    return (sum + Day);
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

short DayOfWeekOrder(short day, short month, short year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;

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

bool IsEndOfWeek(string DayName)
{
    if(DayName == "Sat") return true;
    return false;
}

bool IsWeekEnd(string DayName)
{
    if(DayName == "Fri" || DayName == "Sat") return true;
    return false;
}

bool IsBusinessDay(string DayName)
{
    if(DayName == "Fri" || DayName == "Sat") return false;
    return true;
}

short DaysUntilTheEndOfWeek(sDate Date)
{
    short DayOfWeek = DayOfWeekOrder(Date);
    return 6 - DayOfWeek;
}

short DaysUntilTheEndOfMonth(sDate Date)
{
    short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    return DaysInMonth - Date.Day + 1;
}

short DaysUntilTheEndOfYear(sDate Date)
{
    short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    return DaysInMonth - Date.Day + 1;
}

short DaysUntilTheEndOfYear(sDate Date)
{
    return (NumberOfDaysInAYear(Date.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year));
}

int main()
{
    sDate Date = GetSystemDate();
    string DayName = DayShortName(DayOfWeekOrder(Date));
    cout << "Today is " << DayName << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it End of Week?";
    if(IsEndOfWeek(DayName))
    {
        cout << "\nYes, end of week.";
    }
    else
    cout << "\nNo, NOT end of week.";

    cout << "\n\nIs it Weekend?";
    if(IsWeekEnd(DayName))
    {
        cout << "\nYes, it is a week end.";
    }
    else
    cout << "\nNo, it is NOT week end.";

    cout << "\n\nIs it Business Day?";
    if(IsBusinessDay(DayName))
    {
        cout << "\nYes, it is a business day.";
    }
    else
    cout << "\nNo, it is NOT a business day.";
    
    cout << "\n\nDays until end of week: " << DaysUntilTheEndOfWeek(Date) << " Day(s).";
    cout << "\nDays until end of month: " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
    cout << "\nDays until end of year: " << DaysUntilTheEndOfYear(Date) << " Day(s).";

    return 0;
}