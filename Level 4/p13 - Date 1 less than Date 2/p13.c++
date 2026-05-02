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

//My Solution
bool isDate1TheLeast(sDate Date1, sDate Date2)
{
    if(Date1.Year <= Date2.Year) return true;
    else return false;
    if(Date1.Month <= Date2.Month) return true;
    else return false;
    if(Date1.Day <= Date2.Day) return true;
    else return false;
}

// Abu-Hadhoud Solution

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    sDate Date1 = ReadFullDate();
    cout << endl << endl;
    sDate Date2 = ReadFullDate();

    if(IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is less than Date2." << endl;
    else 
        cout << "\nNo, Date1 is NOT less than Date2." << endl;
    return 0;
}