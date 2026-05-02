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
void SumOfDigits(int Number)
{

    int remainder=0,sum=0;
    while(Number>0)
    {
        remainder=Number%10;
        sum+=remainder;
        Number/=10;
    }
    cout<<"Sum of digits is: "<<sum<<endl;
}
int main()
{
    
    SumOfDigits(ReadPositiveNumber("Please enter a positive number?"));
    

    return 0;
}
/************************************************************************************************* */
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
int SumOfDigits(int Number)
{

    int remainder=0,sum=0;
    while(Number>0)
    {
        remainder=Number%10;
        sum+=remainder;
        Number/=10;
    }
    return sum;
}
int main()
{
    
    cout<<"Sum of digits = "<<SumOfDigits(ReadPositiveNumber("Please enter a positive number?"));
    

    return 0;
}