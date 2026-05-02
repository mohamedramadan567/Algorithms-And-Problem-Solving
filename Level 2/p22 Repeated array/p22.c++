//I cannot able to answer this
#include <iostream>
#include <cstdlib>
#include <time.h>
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
void ReadArray(int arr[100], int& arrLength)
{
    cout<<"Enter number of elements: ";
    cin>>arrLength;
    cout<<"\nEnter array elements: \n";
    for(int i=0;i<arrLength;i++)
    {
        
        cout<<"Element ["<<i+1<<"] : ";
        cin>>arr[i];

    }
    cout<<endl;
}

void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int counter=0;
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]==Number) counter++;
    }
    return counter;
}
int main()
{
    int arr[100], arrLength, NumberToCheck;
    ReadArray(arr, arrLength);
    NumberToCheck = ReadPositiveNumber("Enter the number to check: ");
    cout<<"Original array: ";
    PrintArray(arr, arrLength);
    cout<<NumberToCheck<<" repeated "<<TimesRepeated(NumberToCheck,arr,arrLength)<<" Time(s)."<<endl;
    return 0;
}