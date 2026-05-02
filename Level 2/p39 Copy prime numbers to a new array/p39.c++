#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
enum enPrimeOrNot{Prime = 1, NotPrime = 2};
enPrimeOrNot CheckPrime(int Number)
{
    int M=round(Number/2);
    if(Number == 1) return enPrimeOrNot::NotPrime;
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
        cout<<Message<<" ";
        cin>>Number;
    }while(Number<=0);
    
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
void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    //its a new element so we need to add the length by 1
    
    arrLength++;
    arr[arrLength-1] = Number;
    
}
void CoppyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength,int& arr2Length)
{
    
    
    for(int i=0;i<arrLength;i++)
    {
        if(CheckPrime(arrSource[i])==enPrimeOrNot::Prime)
        {
            AddArrayElements(arrSource[i], arrDestination, arr2Length);
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength = 0, arr[100],arr2Length = 0;
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CoppyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    cout<<"\nArry 2 prime numbers: \n";
    PrintArray(arr2, arr2Length);

    

    return 0;
}