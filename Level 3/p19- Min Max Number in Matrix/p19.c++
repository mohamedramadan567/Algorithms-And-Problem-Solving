#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(0, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int MaxNumberInMatrix(int Matrix[3][3], int rows, int cols)
{
    int Max = Matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][j] >= Max)
            Max = Matrix[i][j];
        }
    }
    return Max;
}

int MinNumberInMatrix(int Matrix[3][3], int rows, int cols)
{
    int Min = Matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][j] <= Min)
            Min = Matrix[i][j];
        }
    }
    return Min;
}

int main()
{
    int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
    cout << "Max Number is: " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;
    return 0;
}