/*#include<iostream>
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
void ReverseNumber(int Number)
{
    cout<<"Reverse to "<<Number<<" is: ";
    int remainder=0;
    while(Number>0)
    {
        remainder=Number%10;
        cout<<remainder;
        Number/=10;
    }
    
}
int main()
{
    
    
    ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));
    

    return 0;
}


/*********************************************************************************************** */
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
int main()
{
    cout<<"\nReverse is: \n"
    <<ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));
}