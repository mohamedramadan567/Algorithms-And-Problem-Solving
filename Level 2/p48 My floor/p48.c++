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
int MyFloor(float Number)
{
    int IntPart = (int)Number;
    
    if(IntPart >= 0)
    return IntPart;
    else return --IntPart;

}

int main()
{
    
    float Number;
    Number = ReadNumber("Please enter a float number?");
    
    
    cout<<"\nMy floor result: " << MyFloor(Number)<<endl;
    
    
    
    cout << "\nC++ floor result: " << floor(Number)<<endl;

    
      

    return 0;
}