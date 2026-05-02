#include <bits/stdc++.h>
using namespace std;

enum enFormat{ DayFirst = 1, YearFirst = 2, MonthFirst = 3, DayFirstFormat2 = 4, MonthFirstFormat2 = 5, anotherFormat = 6 };

struct sDate 
{
    short Day, Month, Year;
};

string ReadDate()
{
    string Date;
    cout << "Please enter date dd/MM/yyyy? ";
    getline(cin >> ws, Date);
    return Date;
}

vector<string>SplitString(string s, string delim)
{
    vector<string>vString;
    int pos = 0;
    string sWord;
    // use find() function to get the position of the delimiters
    while((pos = s.find(delim)) != std::string::npos)
    {
        sWord = s.substr(0, pos);
        if(sWord != " ")
        {
            vString.push_back(sWord);
        }
        //erase() until positon and move to next word.
        s.erase(0, pos + delim.length());
    }
    if(s != "")
    {
        vString.push_back(s);
    }
    return vString;
}

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

sDate StringToDateStructure(string DateString)
{
    sDate Date;
    vector<string>vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string DateToString(sDate Date, string Delim)
{
    return (to_string(Date.Day) + Delim + to_string(Date.Month) + Delim + to_string(Date.Year));
}

//My Solution
string FormatDate(sDate Date, enFormat Formating)
{
    switch (Formating)
    {
    case enFormat::DayFirst:
        return DateToString(Date, "/");
        break;
    case enFormat::YearFirst:
        return (to_string(Date.Year) + "/" + to_string(Date.Month) + "/" + to_string(Date.Day));
        break;
    case enFormat::MonthFirst:
        return (to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year));
        break;
    case enFormat::DayFirstFormat2:
        return DateToString(Date, "-");
        break;
    case enFormat::MonthFirstFormat2:
        return (to_string(Date.Month) + "-" + to_string(Date.Day) + "-" + to_string(Date.Year));
        break;
    case enFormat::anotherFormat:
        return ("Day:" + to_string(Date.Day) + ", Month:" + to_string(Date.Month) + ", Year:" + to_string(Date.Year));
        break;
    
    }
}

//Teacher Solution
string AFormatDate(sDate Date, string FormatDate = "dd/mm/yyyy")
{
    string FormattedDate = "";
    FormattedDate = ReplaceWordInString(FormatDate, "dd", to_string(Date.Day));
    FormattedDate = ReplaceWordInString(FormattedDate, "mm", to_string(Date.Month));
    FormattedDate = ReplaceWordInString(FormattedDate, "yyyy", to_string(Date.Year));

    return FormattedDate;
}

int main()
{
    string DateString = ReadDate();
    enFormat Formatting;
    sDate DateStructure = StringToDateStructure(DateString);
    
    //My Solution
    cout << FormatDate(DateStructure, enFormat::DayFirst) << endl << endl;
    cout << FormatDate(DateStructure, enFormat::YearFirst) << endl << endl;
    cout << FormatDate(DateStructure, enFormat::MonthFirst) << endl << endl;
    cout << FormatDate(DateStructure, enFormat::DayFirstFormat2) << endl << endl;
    cout << FormatDate(DateStructure, enFormat::MonthFirstFormat2) << endl << endl;
    cout << FormatDate(DateStructure, enFormat::anotherFormat) << endl << endl;

    cout << endl;

    //Teacher Solution
    cout << "\n" << AFormatDate(DateStructure) << "\n";
    cout << "\n" << AFormatDate(DateStructure, "yyyy/mm/dd") << "\n";
    cout << "\n" << AFormatDate(DateStructure, "mm/dd/yyyy") << "\n";
    cout << "\n" << AFormatDate(DateStructure, "dd-mm-yyyy") << "\n";
    cout << "\n" << AFormatDate(DateStructure, "mm-dd-yyyy") << "\n";
    cout << "\n" << AFormatDate(DateStructure, "Day:dd, Month:mm, Year:yyyy") << "\n";

    return 0;
}