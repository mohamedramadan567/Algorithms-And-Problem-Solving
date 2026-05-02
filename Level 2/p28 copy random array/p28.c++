//I cannot solution for this
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
void CoppyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    
    
    for(int i=0;i<arrLength;i++)
    {
        arrDestination[i] = arrSource[i];
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    ReadArray(arr, arrLength);
    int arr2[100];
    CoppyArray(arr, arr2, arrLength);
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    cout<<"\nArry 2 elements after copy: \n";
    PrintArray(arr2, arrLength);
    return 0;
}