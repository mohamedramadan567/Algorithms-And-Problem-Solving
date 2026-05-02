#include <iostream>
#include <cmath>

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
int MyCeil(float Number)
{
    int IntPart = (int)Number;
    float FractionsPart = GetFractionsPart(Number);
    if(abs(FractionsPart) >0)
    {
        if(IntPart >= 0)
        return ++IntPart;
        else return IntPart;
    }
    else return Number;
}

int main()
{
    
    float Number;
    Number = ReadNumber("Please enter a float number?");
    
    
    cout<<"\nMy ceil result: " << MyCeil(Number)<<endl;
    
    
    
    cout << "\nC++ ceil result: " << ceil(Number)<<endl;

    
      

    return 0;
}