#include <bits/stdc++.h>
using namespace std;

struct sDate 
{
    short Day, Month, Year;
};

string ReadDate()
{
    string Date;
    cout << "Please enter date dd/MM/yyyy? ";
    cin >> Date;
    return Date;
}

//My Solution
vector<int>SplitDate(string Date1, string Delim)
{
    vector<int>Date;
    int pos = 0;
    string Number;
    while((pos = Date1.find(Delim)) != std::string::npos)
    {
        Number = Date1.substr(0, pos);
        if(Number != " ")
        {
            Date.push_back(stoi(Number));
        }
        Date1.erase(0, pos + Delim.length());
    }
    if(Date1 != "")
    {
        Date.push_back(stoi(Date1));
    }
    return Date;
}

sDate StringToDate(string DateString)
{
    sDate Date;
    vector<int>Split = SplitDate(DateString, "/");
    Date.Day = Split[0];
    Date.Month = Split[1];
    Date.Year = Split[2];
    return Date;
}

string DateToString(sDate Date, string Delim)
{
    string StringDate = "";
    StringDate += to_string(Date.Day) + Delim;
    StringDate += to_string(Date.Month) + Delim;
    StringDate += to_string(Date.Year);
    return StringDate;
}

//Teacher Solution
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

sDate StringToDateStructure(string DateString)
{
    sDate Date;
    vector<string>vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string DateToString(sDate Date)
{
    return (to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year));
}

int main()
{
    string DateString = ReadDate();
    sDate DateStructure = StringToDateStructure(DateString);
    cout << "Day: " << DateStructure.Day << endl;
    cout << "Month: " << DateStructure.Month << endl;
    cout << "Year: " << DateStructure.Year << endl;

    cout << "\nYou Entered: " << DateToString(DateStructure);

    return 0;
}