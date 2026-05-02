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

short DayOfWeekOrder(short day, short month, short year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;

}

string DayShortName(short DayOfWeekOrder)
{
    string arrOfDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrOfDayNames[DayOfWeekOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n\nDate            :" << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order       :" << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name        :" << DayShortName(DayOfWeekOrder(Day, Month, Year));


    return 0;
}