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
int ReadNumber(string Message)
{
    int Number;
    cout<<Message<<endl;
    cin>>Number;
    
    return Number;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        
        arr[i] = RandomNumber(-100, 100);

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

int CountPositiveNumbersInArray(int arr[100], int arrLength)
{
    int Count = 0;
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]>0) Count++;
    }
    return Count;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength = 0, arr[100], OddNumbers = 0;
    arrLength= ReadNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);

    
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    
    
    cout<<"\nPositive numbers count is: ";
    cout<<CountPositiveNumbersInArray(arr, arrLength)<<endl;
    

    

    return 0;
}