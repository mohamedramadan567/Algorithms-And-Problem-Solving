#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };
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
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    }
}
string GenerateWord(enCharType CharType, short length)
{
    string word="";
    for(int i=1; i<=length; i++)
    {
        word+=GetRandomCharacter(CharType);
    }
    return word;
}
string GenerateKey()
{
    string key="";
    key+=GenerateWord(enCharType::CapitalLetter, 4)+"-";
    key+=GenerateWord(enCharType::CapitalLetter, 4)+"-";
    key+=GenerateWord(enCharType::CapitalLetter, 4)+"-";
    key+=GenerateWord(enCharType::CapitalLetter, 4);
    return key;
}
void FillArrayWithRandomKeys(string arr[100], int& arrLength)
{
    
    for(int i=0;i<arrLength;i++)
    {
        
        arr[i] = GenerateKey();

    }
    
}
void PrintArray(string arr[100], int arrLength)
{
    cout<<"\nArray elements: \n\n";
    for(int i=0;i<arrLength;i++)
    {
        cout<<"Array["<<i<<"] : "<<arr[i]<<endl;
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength;
    string arr[100];
    arrLength= ReadPositiveNumber("How many keys do you want to generate?");
    FillArrayWithRandomKeys(arr, arrLength);

    
    PrintArray(arr, arrLength);
    
    return 0;
}