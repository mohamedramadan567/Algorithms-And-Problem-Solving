//important problem
//I can't anwer into this problem 
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
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
        cout<<Message<<" ";
        cin>>Number;
    }while(Number<=0);
    
    return Number;
}
void FillArrayHardCoded(int arr[100], int& arrLength)
{
    
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
    
}
void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    //its a new element so we need to add the length by 1
    
    arrLength++;
    arr[arrLength-1] = Number;
    
}
int FindNumberPositionInArray(int arr[100], int arrLength, int Number)
{
    /*This function will search for a number in array and return
    its index, or return -1 if it does not exists*/
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]==Number) return i;//return the index
    }
    //if you reached here, this means the number is not found
    return -1;
    
}
bool IsNumberInArray(int arr[100], int arrLength, int Number)
{
    
    return FindNumberPositionInArray(arr,arrLength,Number)!=-1;
}
void CoppyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength,int& arr2Length)
{
    
    for(int i=0;i<arrLength;i++)
    {
        if(!IsNumberInArray(arrDestination, arrLength, arrSource[i]))
        AddArrayElements(arrSource[i], arrDestination, arr2Length);
    }
    
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arrLength = 0, arr2Length = 0;

    FillArrayHardCoded(arr, arrLength);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    CoppyDistinctNumbers(arr, arr2, arrLength, arr2Length);
   
    cout<<"\nArry 2 distinct elsements: \n";
    PrintArray(arr2, arr2Length);

    return 0;
}