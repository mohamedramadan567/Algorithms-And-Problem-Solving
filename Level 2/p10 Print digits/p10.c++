#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout<<Message<<endl;
        cin>>Number;
    } while (Number<0);
    return Number;
}
int ReverseNumber(int Number)
{
    int remainder=0,Number2=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        Number2=Number2*10+remainder;
    }
    return Number2;
}
void RidhtToLift(int Number)
{
    int Number2=ReverseNumber(Number);
    int remainder=0;
    while(Number2>0)
    {
        remainder=Number2%10;
        Number2/=10;
        cout<<remainder<<endl;
    }
}
int main()
{
    RidhtToLift(ReadPositiveNumber("Please enter a positive number?"));
}

/**********************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout<<Message<<endl;
        cin>>Number;
    } while (Number<0);
    return Number;
}
int ReverseNumber(int Number)
{
    int remainder=0,Number2=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        Number2=Number2*10+remainder;
    }
    return Number2;
}
void PrintDigits(int Number)
{
    
    int remainder=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        cout<<remainder<<endl;
    }
}
int main()
{
    PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number?")));
}