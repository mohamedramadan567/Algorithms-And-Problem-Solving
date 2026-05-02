#include <iostream>
#include <cstdlib> // for RandomNumber fun
#include <time.h> // for run srand into the main
using namespace std;
enum enPrimeOrNot{Prime = 1, NotPrime = 2}; 
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
enPrimeOrNot CheckPrime(int Number)
{
    int M=Number/2;
    for(int i=2;i<=M;i++)
    {
        if(Number%i == 0)
        return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::Prime;
}

bool IsPerfectNumber(int Number)
{
    int sum=0;
    for(int i=1;i<Number;i++)
    {
        if(Number%i==0)
        sum+=i;
    }
    return sum==Number;
}

int CountDigitFrequency(short digit,int Number)
{
    int remainder=0,freqcount=0;
    while(Number>0)
    {
        remainder=Number%10;
        Number/=10;
        if(digit==remainder) freqcount++;
    }
    return freqcount;
}

int RandomNumber(int From, int To) 
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void ReadRandomArray(int arr[100], int& arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        
        arr[i] = RandomNumber(1, 100);

    }
    
}

void ReadArray(int arr[100], int& arrLength)
{
    cout<<"Enter number of elements: ";
    cin>>arrLength;
    cout<<"\nEnter array elements: \n";
    for(int i=0;i<arrLength;i++)
    {
        
        cout<<"Element ["<<i+1<<"] : ";
        cin>>arr[i];

    }
    cout<<endl;
}
void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int MaxElementInArray(int arr[100], int arrLength)
{
    int Max=0;
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]>=Max) Max=arr[i];
    }
    return Max;
}
int MinElementInArray(int arr[100], int arrLength)
{
    int Min=arr[0];
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i]<=Min) Min=arr[i];
    }
    return Min;
}

void Swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
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

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    //its a new element so we need to add the length by 1
    arrLength++;
    arr[arrLength-1] = Number;
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 
    
    return 0;
}