#pragma once
#include <iostream>
using namespace std;

namespace MyLib
{

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
        return((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    }

    short NumberOfDaysInAMonth(short year, short month)
    {
        if (month < 1 || month > 12)
            return 0;

        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
    }

    short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short sum = 0;
        for (short i = 1; i < Month; i++)
        {
            sum += NumberOfDaysInAMonth(Year, i);
        }
        return (sum + Day);
    }

    sDate DecreaseDateByOneDay(sDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
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

    bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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
        if (IsLastDayInMonth(Date.Day, Date.Month, Date.Year))
        {
            Date.Day = 1;
            if (IsLastMonthInYear(Date.Month))
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
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return (EncludedEndDay) ? ++Days : Days;
    }

    bool IsEndOfWeek(sDate Date)
    {
        return DayOfWeekOrder(Date) == 6;
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

    short DaysUntilTheEndOfWeek(sDate Date)
    {
        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfMonth(sDate Date)
    {
        sDate EndOfMonthDate;

        EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;

        return GetDiffrenceInDays(Date, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfYear(sDate Date)
    {
        sDate EndOfMonthDate;

        EndOfMonthDate.Day = 31;
        EndOfMonthDate.Month = 12;
        EndOfMonthDate.Year = Date.Year;

        return GetDiffrenceInDays(Date, EndOfMonthDate, true);
    }

}