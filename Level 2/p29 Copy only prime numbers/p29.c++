//I cannot solution for this
/*#include <iostream>
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
int CountPrime(int arr[100], int arrLength)
{
    bool Prime = false;
    int CountPrime=0;
    for(int i=0;i<arrLength;i++)
    {
        int Count=0;
        for(int j=1;j<=arr[i];j++)
        {
            if(arr[i]%j == 0) 
            Count++;
        }
        if(Count==2) CountPrime++;
    }
    return CountPrime;
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
        int count = 0;
        for(int j=1;j<=arrSource[i];j++)
        {
            if(arrSource[i]%j == 0) count++;
        }
        if (count == 2) arrDestination[i] = arrSource[i];
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));

    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    ReadArray(arr, arrLength);
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    int arr2Length, arr2[100];
    arr2Length=CountPrime(arr, arrLength);
    CoppyArray(arr, arr2, arrLength);
    PrintArray(arr2, arr2Length);


    

    return 0;
}

/*********************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enPrimeOrNot{Prime = 1, NotPrime = 2};
enPrimeOrNot CheckPrime(int Number)
{
    int M=round(Number/2);
    for(int i=2;i<=M;i++)
    {
        if(Number%i == 0)
        return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::Prime;
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
void CoppyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    
    int Counter=0;
    for(int i=0;i<arrLength;i++)
    {

        if(CheckPrime(arrSource[i]) == enPrimeOrNot::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }
    arr2Length = Counter;
    cout<<endl;
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arrLength, arr[100];
    arrLength= ReadPositiveNumber("Enter number of elements?");
    ReadArray(arr, arrLength);
    int arr2[100], arr2Length = 0;
    CoppyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);
    cout<<"\nArry 2 elements after copy: \n";
    PrintArray(arr2, arr2Length);
    return 0;
}