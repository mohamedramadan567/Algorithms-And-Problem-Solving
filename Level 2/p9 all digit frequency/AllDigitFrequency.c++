//i am not able to answer
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
void PrintAllDigitsFrequency(int Number)
{
    cout<<endl;
    
    for(int i=0;i<10;i++)
    {
        short DigitFrequency=0;
        DigitFrequency=CountDigitFrequency(i,Number);
        if(DigitFrequency>0)
        {
            cout<<"\nDigit "<<i<<" Frecuency is "<<DigitFrequency<<" Time(s).\n";
        }

    }
}
int main()
{
    int Number=ReadPositiveNumber("Please enter a main number?");
    
    PrintAllDigitsFrequency( Number);
    
}