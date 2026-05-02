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
void CoppyArrayInEeversedOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    
    
    for(int i = arrLength - 1,j = 0 ;i>=0,j<arrLength;i--,j++)
    {
        arrDestination[j] = arrSource[i];
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CoppyArrayInEeversedOrder(arr, arr2, arrLength);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    cout<<"\nArry 2 elements after copying array 1 reversed order: \n";
    PrintArray(arr2, arrLength);
    return 0;
}


/************************************************************************************************/
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
//Diffrenentn on this
void CoppyArrayInEeversedOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    
    
    for(int i = 0;i<arrLength;i++)
    {
        arrDestination[i] = arrSource[arrLength-1-i];
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CoppyArrayInEeversedOrder(arr, arr2, arrLength);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    
    cout<<"\nArry 2 elements after copying array 1 reversed order: \n";
    PrintArray(arr2, arrLength);
    return 0;
}