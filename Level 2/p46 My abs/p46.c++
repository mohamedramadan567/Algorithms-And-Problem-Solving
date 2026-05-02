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

float MyABS(float Number)
{
    if(Number<0) return -Number;
    else return Number;
}

int main()
{
    srand((unsigned)time(NULL));
    float Number;
    Number = ReadNumber("Please enter a number?");
    
    
    cout<<"\nMy abs result: " << MyABS(Number)<<endl;
    
    
    
    cout << "\nC++ abs result: " << abs(Number)<<endl;
      

    return 0;
}