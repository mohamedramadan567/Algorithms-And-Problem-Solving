#pragma warning(disable : 4996)
#include <iostream>
#include"MyLib.h"

using namespace std;

int main()
{
    MyLib::sDate Date = MyLib::GetSystemDate();
    string DayName = MyLib::DayShortName(MyLib::DayOfWeekOrder(Date));
    cout << "Today is " << DayName << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << "\n\nIs it End of Week?";
    if (MyLib::IsEndOfWeek(Date))
    {
        cout << "\nYes, end of week.";
    }
    else
        cout << "\nNo, NOT end of week.";

    cout << "\n\nIs it Weekend?";
    if (MyLib::IsWeekEnd(Date))
    {
        cout << "\nYes, it is a week end.";
    }
    else
        cout << "\nNo, " << DayName << " it is NOT week end.";

    cout << "\n\nIs it Business Day?";
    if (MyLib::IsBusinessDay(Date))
    {
        cout << "\nYes, it is a business day.";
    }
    else
        cout << "\nNo, it is NOT a business day.";

    cout << "\n\nDays until end of week: " << MyLib::DaysUntilTheEndOfWeek(Date) << " Day(s).";
    cout << "\nDays until end of month: " << MyLib::DaysUntilTheEndOfMonth(Date) << " Day(s).";
    cout << "\nDays until end of year: " << MyLib::DaysUntilTheEndOfYear(Date) << " Day(s).";

    return 0;
}