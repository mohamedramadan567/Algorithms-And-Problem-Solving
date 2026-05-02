//My Answer
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
enum enPerfectOrNot{Perfect = 1, NotPerfect = 2};
int ReadPositiveNumber(string Message)
{
    int n;
    
    do
    {
        cout<<Message<<" ";
        cin>>n;
    }while(n<=0);

    return n;
}
enPerfectOrNot CheckPerfect(int Number)
{
    int sum=0;
    for(int i=1;i<=Number/2;i++)
    {
        if(Number%i == 0)
        sum+=i;
    }
    if(sum==Number) return enPerfectOrNot::Perfect;
    else return enPerfectOrNot::NotPerfect;
}
void PrintTypeNumber(int Number)
{
    if(CheckPerfect(Number)==enPerfectOrNot::NotPerfect)
    cout<<Number<<" is not perfect number"<<endl;
    else 
    cout<<Number<<" is perfect number"<<endl;

}
int main()
{
    PrintTypeNumber(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
/***************************************************************************************************************** */


//him answer

#include<iostream>
#include<string>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int n;
    
    do
    {
        cout<<Message<<" ";
        cin>>n;
    }while(n<=0);

    return n;
}
bool IsPerfectNumber(int Number)
{
    int sum=0;
    for(int i=1;i<Number;i++)
    {
        if(Number%i==0)
        sum+=i;
    }
    return sum==Number;
}
void PrintResults(int Number)
{
    cout<<endl;
    if(IsPerfectNumber(Number))
    cout<<Number<<" is perfect number."<<endl;
    else 
    cout<<Number<<" is NOT perfect number."<<endl;

}
int main()
{
    PrintResults(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}