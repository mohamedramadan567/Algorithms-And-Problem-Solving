//I cannot able to solve it
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
void Swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
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
void FillArrayFrom1ToN(int arr[100], int& arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        
        arr[i] = i+1;

    }
    
}

void SuffelArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        Swap(arr[RandomNumber(1, arrLength)-1], arr[RandomNumber(1, arrLength)-1]);
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
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayFrom1ToN(arr, arrLength);
    cout<<"\nArry elements before shuffle: \n";
    PrintArray(arr, arrLength);

    SuffelArray(arr, arrLength);
    cout<<"\nArry elements after shuffle: \n";
    PrintArray(arr, arrLength);

    
    return 0;
}