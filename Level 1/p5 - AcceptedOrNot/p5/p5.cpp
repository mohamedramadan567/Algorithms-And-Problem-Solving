#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;
struct stInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};
stInfo ReadInfo()
{
    stInfo Info;
    cout << "Enter Your Age ?\n";
    cin >> Info.Age;
    cout << "Are you have a driver license ?\n";
    cin >> Info.HasDrivingLicense;
    cout << "Are you have a Recommendation?\n";
    cin >> Info.HasRecommendation;
    return Info;
}
bool IsAccepted(stInfo Info)
{
    if (Info.HasRecommendation)
        return true;
    else if (Info.Age > 21 && Info.HasDrivingLicense)
    return true;
    
}
void PrintResult(stInfo Info)
{
    if (IsAccepted(Info))
        cout << "\nHired\n";
    else
        cout << "\nRejected\n";
}
int main()
{
    PrintResult(ReadInfo());
    return 0;
}