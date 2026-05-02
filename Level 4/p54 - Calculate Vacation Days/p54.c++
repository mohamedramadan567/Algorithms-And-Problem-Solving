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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

bool IsWeekEnd(sDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(sDate Date)
{
    //Weekends are Sun,Mon,Tue,Wed and Thur
    /* short DayIndex = DayOfWeekOrder(Date);
        return (DayIndex >= 5 && DayIndex <= 4);
    */

    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(Date);
}

//My Solution.
short TheActualOfVacationDays(sDate DateFrom, sDate DateTo)
{
    short TotalDays = GetDiffrenceInDays(DateFrom, DateTo);
    short DaysOfWeekEnd = 0;
    while(IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if(IsWeekEnd(DateFrom)) DaysOfWeekEnd++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
        
    }
    return TotalDays - DaysOfWeekEnd;
}

//Teacher Solution.
short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
    short DaysCount = 0;
    while(IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if(IsBusinessDay(DateFrom)) DaysCount++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}

int main()
{
    cout << "Vecation Starts:\n";
    sDate DateFrom = ReadFullDate();
    cout << "\nVecation Ends:\n";
    sDate DateTo = ReadFullDate();

    string DayName = DayShortName(DayOfWeekOrder(DateFrom));
    cout << "\nVacation From: " << DayName << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

    DayName = DayShortName(DayOfWeekOrder(DateTo));
    cout << "\nVacation To: " << DayName << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

    cout << "\n\nActual Vacation Days is: " << TheActualOfVacationDays(DateFrom, DateTo) << endl;

    cout << "\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo) << endl;
    
    return 0;
}
