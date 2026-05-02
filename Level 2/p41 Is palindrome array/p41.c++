#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

void FillArrayHardCoded(int arr[100], int& arrLength)
{
    
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
    
    
}
void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void CoppyInvertedArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        arrDestination[arrLength-i-1] = arrSource[i];
    }
    
}
bool IsPalindromeArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    bool Palindrome=false;
    for(int i=0;i<arrLength;i++)
    {
        if(arrDestination[i]==arrSource[i]) Palindrome = true;
        else Palindrome = false;
    }
    return Palindrome;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arrLength = 0;

    FillArrayHardCoded(arr, arrLength);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    CoppyInvertedArray(arr, arr2, arrLength);

    if(IsPalindromeArray(arr, arr2, arrLength))
    cout<<"\nYes is array is palindrome \n";
    else 
    cout<<"\nNo is array is NOT palindrome \n";

    return 0;
}


/******************************************************************************************************/

#include <iostream>

using namespace std;

void FillArrayHardCoded(int arr[100], int& arrLength)
{
    
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
    
    
}
void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void CoppyInvertedArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        arrDestination[arrLength-i-1] = arrSource[i];
    }
    
}
bool IsPalindromeArray(int arr[100], int arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]!=arr[arrLength-i-1]) 
        return false;
    }
    return true;
}
int main()
{
    
    int arr[100], arrLength = 0;

    FillArrayHardCoded(arr, arrLength);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    if(IsPalindromeArray(arr, arrLength))
    cout<<"\nYes is array is palindrome \n";
    else 
    cout<<"\nNo is array is NOT palindrome \n";

    return 0;
}