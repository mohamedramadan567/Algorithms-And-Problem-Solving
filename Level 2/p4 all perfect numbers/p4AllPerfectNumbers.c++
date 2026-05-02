//My answer was the same him answer
#include<iostream>
#include<string>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int n;
    
    do
    {
        cout<<Message<<" ";
        cin>>n;
    }while(n<=0);

    return n;
}
bool IsPerfectNumber(int Number)
{
    int sum=0;
    for(int i=1;i<Number;i++)
    {
        if(Number%i==0)
        sum+=i;
    }
    return sum==Number;
}
void PrintAllPerfectNumbers(int Number)
{
    cout<<"All Perfect Numbers from 1 to "<<Number;
    cout<<" Is: "<<endl;
    for(int i=1;i<=Number;i++)
    {
        if(IsPerfectNumber(i))
        cout<<i<<endl;
    }

}
int main()
{
    PrintAllPerfectNumbers(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}