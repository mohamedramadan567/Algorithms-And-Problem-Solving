// i cannot able to solve it
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int ReadNumber(string Message)
{
    int Number;
    cout << Message << endl;
    cin >> Number;

    return Number;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {

        arr[i] = RandomNumber(1, 100);
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void AddArrayElements(int Number, int arr[100], int &arrLength)
{
    // its a new element so we need to add the length by 1
    arrLength++;
    arr[arrLength - 1] = Number;
}
void CoppyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &array2Length)
{

    for (int i = 0; i < arrLength; i++)
        AddArrayElements(arrSource[i], arrDestination, array2Length);
}
int main()
{
    srand((unsigned)time(NULL));
    int arrLength = 0, arr[100], arr2Length = 0;
    arrLength = ReadNumber("Enter number of elements?");
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CoppyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);

    cout << "\nArry 1 elements: \n";
    PrintArray(arr, arrLength);

    cout << "\nArry 2 elements after copy: \n";
    PrintArray(arr2, arr2Length);

    return 0;
}