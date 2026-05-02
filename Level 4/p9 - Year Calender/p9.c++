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

bool IsLeapYear(short year)
{
    return((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDaysInAMonth(short year, short month)
{
    if(month < 1 || month > 12)
    return 0;

    // teacher solution
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short DayOfWeekOrder(short day, short month, short year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;

}

string MonthShortName(short DayOfMonthOrder)
{
    string arrOfMonthNames[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return arrOfMonthNames[DayOfMonthOrder - 1];
}

void PrintCalenderMonth(short Month, short Year)
{
    short NumberOfDays;
    short Current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Year, Month);

    printf("\n________________%s________________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;
    for( i = 0; i < Current; i++)
        printf("     ");

    for(int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if(++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n___________________________________\n");
}

void PrintYearCalendar(short Year)
{
    printf("\n___________________________________\n\n");
    printf("\t Calendar - %d", Year);
    printf("\n___________________________________\n");

    for(int i = 1; i <= 12; i++)
    {
        PrintCalenderMonth(i, Year);
    }
}

int main()
{
    short Year = ReadYear();

    PrintYearCalendar(Year);


    return 0;
}