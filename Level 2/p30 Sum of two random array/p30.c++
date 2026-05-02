#include <iostream>
#include <cmath>
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
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
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
void SumOf2Arrays(int arrSource[100], int arrDestination[100], int arrSum[100], int arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        arrSum[i] = arrSource[i] + arrDestination[i];        
    }
    
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arrLength, arr[100], arr2[100], arrSum[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);
    SumOf2Arrays(arr, arr2, arrSum, arrLength);
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    cout<<"\nArry 2 elements after copy: \n";
    PrintArray(arr2, arrLength);
    cout<<"\nSum of array1 and array2 elements: \n";
    PrintArray(arrSum, arrLength);
    return 0;
}