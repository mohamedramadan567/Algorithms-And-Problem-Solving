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
void SearchForNumberInArray(int arr[100], int arrLength, int& NumberToSearch)
{
    bool found = false;
    int index=0;
    cout<<"\nNumber you are looking for is: "<<NumberToSearch<<endl;
    for(int i=0;i<arrLength;i++)
    {
        if(arr[i] == NumberToSearch)
        {
            found = true;
            index = i;
            
        }
    }
    if(found==true)
    {
        cout<<"The number found at position: "<<index<<endl;
        cout<<"The number found its order: "<<index+1<<endl;
    }
    else 
        cout<<"The number is not found :-("<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength, arr[100], NumberToSearch;
    arrLength= ReadPositiveNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    
    cout<<"\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    NumberToSearch = ReadPositiveNumber("Please enter a number to search?");
    
    
    SearchForNumberInArray(arr, arrLength, NumberToSearch);
    return 0;
}

/**********************************************************************************************************/

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
    
    int NumberPosition = FindNumberPositionInArray(arr, arrLength, Number);
    if(NumberPosition == -1)
    {
        cout<<"The number is not found :-("<<endl;
    }
    else
    {
        cout<<"The number found at position: "<<NumberPosition<<endl;
        cout<<"The number found its order: "<<NumberPosition+1<<endl;
    }
    return 0;
}