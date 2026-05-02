//I can't solve it
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

float ReadNumber(string Message)
{
    float Number;
    cout<<Message<<endl;
    cin>>Number;
    
    return Number;
}
float GetFractionsPart(float Number)
{
    return Number - int(Number);
}
int MyRound(float Number)
{
    int IntPart = (int)Number;
    float FractionsPart = GetFractionsPart(Number);
    if(abs(FractionsPart) >= .5)
    {
        if(Number > 0)
        return ++IntPart;
        else return --IntPart; 
    }
    else
        return IntPart;
}

int main()
{
    
    float Number;
    Number = ReadNumber("Please enter a float number?");
    
    
    cout<<"\nMy round result: " << MyRound(Number)<<endl;
    
    
    
    cout << "\nC++ round result: " << round(Number)<<endl;

    cout<<sqrt(10);
      

    return 0;
}