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
void InvertedNumber(int Number)
{
    int m=Number;
    for(int i=1;i<=Number;i++)
    {
        
        int counter=0;
        for(int j=m;j>=1;j--)
        {
            cout<<j+counter;
            counter++;
        }
        cout<<endl;
        m--;
        
    }
}
int main()
{
    
    InvertedNumber(ReadPositiveNumber("Please enter a positive number?"));
    
    
    return 0;
}

/****************************************************************************************** */

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
void PrintInvertedNumberPattern(int Number)
{
    cout<<endl;
    
    for(int i=Number;i>=1;i--)
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
    
    PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number?"));
    
    
    return 0;
}