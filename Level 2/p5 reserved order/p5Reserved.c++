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
void PrintReversedOrder(int Number)
{
    cout<<"Reversed order to the  "<<Number;
    cout<<" Is: "<<endl;
    int remainder=0;
    while(Number>0)
    {
        remainder=Number%10;
        cout<<remainder<<endl;
        Number/=10;
    }

}
int main()
{
    
    PrintReversedOrder(ReadPositiveNumber("Please enter a positive number?\n"));
    

    return 0;
}