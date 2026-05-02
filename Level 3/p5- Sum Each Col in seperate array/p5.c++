#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int ColSum(int arr[3][3], short ColNumber, short rows)
{
    int Sum = 0;
    for (int i = 0; i < rows; i++)
    {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumMatixColsInArry(int arr[3][3], int arrSum[3], int rows, short cols)
{
    for (int j = 0; j < cols; j++)
    {
        arrSum[j] = ColSum(arr, j, rows);
    }
}

void PrintColsSumArray(int arr[3], int cols)
{
    cout << "\nThe the following are the sum of each col in the matrix:\n";
    for (int i = 0; i < cols; i++)
    {
        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[3][3], arrSum[3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);

    SumMatixColsInArry(arr, arrSum, 3, 3);
    PrintColsSumArray(arrSum, 3);
    return 0;
}
