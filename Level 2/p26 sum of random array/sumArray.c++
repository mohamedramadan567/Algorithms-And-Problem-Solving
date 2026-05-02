#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int RandomNumber(int From, int To) 
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
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
    
    for(int i=0;i<arrLength;i++)
    {
        
        arr[i] = RandomNumber(1, 100);

    }
    
}

void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int SumOfNumber(int arr[100], int arrLength)
{
    int sum = 0;
    for(int i=0;i<arrLength;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    ReadArray(arr, arrLength);
    cout<<"Array Elements: ";
    PrintArray(arr, arrLength);
    cout<<"Sum of all numbers is: "<<SumOfNumber(arr, arrLength)<<endl;
    return 0;
}