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
    int Number1 = ReadPositiveNumber("Please enter a positive number?");
    if(ReverseNumber(Number1)==Number1) 
    cout<<"Yes, it is a Palindrome\n";
    else
    cout<<"No, it is not a Palindrome\n";
}

/******************************************************************************************** */
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
bool IsPalindrome(int Number)
{
    return Number==ReverseNumber(Number);
}
int main()
{
    
    if(IsPalindrome(ReadPositiveNumber("Please enter a positive number?"))) 
    cout<<"Yes, it is a Palindrome.\n";
    else
    cout<<"No, it is not a Palindrome.\n";
}