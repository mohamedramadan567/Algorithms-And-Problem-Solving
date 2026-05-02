// i can't solve it and i don't convince for this solution
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
float MySQRT(float Number)
{
    return pow(Number, .5);
}

int main()
{
    
    float Number;
    Number = ReadNumber("Please enter a number?");
    
    
    cout<<"\nMy sqrt result: " << MySQRT(Number)<<endl;
    
    
    
    cout << "\nC++ sqrt result: " << sqrt(Number)<<endl;

    cout<<sqrt(11.234);
      

    return 0;
}