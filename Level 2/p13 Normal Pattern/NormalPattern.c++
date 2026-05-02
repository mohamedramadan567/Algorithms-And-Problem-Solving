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
void PrintNormalNumberPattern(int Number)
{
    cout<<endl;
    
    for(int i=1;i<=Number;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
int main()
{
    
    PrintNormalNumberPattern(ReadPositiveNumber("Please enter a positive number?"));
    
    
    return 0;
}