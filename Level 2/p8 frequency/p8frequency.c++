/*#include <iostream>
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
int ReadDigit(string Message2)
{
    int digit;
    do
    {
        cout<<Message2<<endl;
        cin>>digit;
    } while (digit>=10);
    return digit;
}
int Frequency(int digit,int Number)
{
    int remainder=0,counter=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        if(digit==remainder) 
        counter=counter+1;
    }
    return counter;
}
int main()
{
    cout<<"\nFrequency is: \n"
    <<Frequency(ReadDigit("Please enter a digit?"),ReadPositiveNumber("Please enter a positive number?"));
}*/

/************************************************************************************************************************** */
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

int CountDigitFrequency(short digit,int Number)
{
    int remainder=0,freqcount=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        if(digit==remainder) freqcount++;
    }
    return freqcount;
}
int main()
{
    int Number=ReadPositiveNumber("Please enter a main number?");
    short DigitToCheck=ReadPositiveNumber("Please enter one digit to check?");

    cout<<"\nDigit "<<DigitToCheck<<" Frecuency is "<<CountDigitFrequency(DigitToCheck,Number)<<" Time(s).\n";
    
}