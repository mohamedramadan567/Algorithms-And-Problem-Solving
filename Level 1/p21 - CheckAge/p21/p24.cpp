#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int ReadAge()
{
    int Age;
    cout << "Please enter your age ?" << endl;
    cin >> Age;
    return Age;
    
}
bool CheckAge(int Age, int From, int To)
{
    return (Age >= From && Age <= To);

}
void PrintResults(int Age)
{
    if (CheckAge(Age, 18, 45))
        cout << Age << " is Valid Age\n";
    else 
        cout << Age << " is Invalid Age\n";
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PrintResults(ReadAge());

    return 0;
}