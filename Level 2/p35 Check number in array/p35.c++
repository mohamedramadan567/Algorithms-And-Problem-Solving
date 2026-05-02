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
int FindNumberPositionInArray(int arr[100], int arrLength, int Number)
{
    /*This function will search for a number in array and return
    its index, or return -1 if it does not exists*/
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]==Number) return i;// and return the index
    }
    //if you reached here, this means the number is not found
    return -1;
    
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    
    int Number = ReadPositiveNumber("Please enter a number to search?");
    cout<<"Number you are looking for is: "<<Number<<endl;
    int NumberPosition = FindNumberPositionInArray(arr, arrLength, Number);
    if(NumberPosition == -1)
    {
        cout<<"The number is not found :-("<<endl;
    }
    else
    {
        cout<<"Yes, The number is found :-)"<<endl;
    }
    return 0;
}


/************************************************************************************************************************/

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
int FindNumberPositionInArray(int arr[100], int arrLength, int Number)
{
    /*This function will search for a number in array and return
    its index, or return -1 if it does not exists*/
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]==Number) return i;// and return the index
    }
    //if you reached here, this means the number is not found
    return -1;
    
}
bool IsNumberInArray(int arr[100], int arrLength, int Number)
{
    
    return FindNumberPositionInArray(arr,arrLength,Number)!=-1;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    
    int Number = ReadPositiveNumber("Please enter a number to search?");
    cout<<"Number you are looking for is: "<<Number<<endl;

    if(IsNumberInArray(arr, arrLength, Number))
    {
        cout<<"The number is found :-("<<endl;
    }
    else
    {
        cout<<"Yes, The number is not found :-)"<<endl;
    }
    return 0;
}