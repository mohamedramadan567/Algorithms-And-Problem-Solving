/*#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int ReadNumber(string Message)
{
    int Number;
    
    cout<<Message<<endl;
    cin>>Number;
    
    return Number;
}
void PrintArray(int arr[100], int arrLength)
{
    for(int i=0;i<arrLength;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void ArraySemiDynamic(int arr[100], int& arrLength)
{
    int Choice;
    int i=0;
    do
    {

        int Number = ReadNumber("Please enter a number?");
        arr[i]=Number;
        cout<<"Do you want to add more number? [0]: No, [1]: Yes? ";
        cin>>Choice;
        if(Choice == 1) i++;
        
    } while (Choice==1);
    arrLength=i+1;
    cout<<"Array length: "<<arrLength<<endl;
    
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    ArraySemiDynamic(arr, arrLength);
    cout<<"Array elements: ";
    PrintArray(arr, arrLength);
    return 0;
}



/***********************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int ReadNumber(string Message)
{
    int Number;
    
    cout<<Message<<endl;
    cin>>Number;
    
    return Number;
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
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool Choice;
    int i=0;
    do
    {

        int Number = ReadNumber("Please enter a number?");
        AddArrayElements(Number, arr, arrLength);
        cout<<"Do you want to add more number? [0]: No, [1]: Yes? ";
        cin>>Choice;
        if(Choice) i++;
        
    } while (Choice);
    
    
}
int main()
{
    int arr[100], arrLength=0;
    InputUserNumbersInArray(arr, arrLength);

    cout<<"\nArray length: "<<arrLength<<endl;
    cout<<"Array elements: ";
    PrintArray(arr, arrLength);
    return 0;
}