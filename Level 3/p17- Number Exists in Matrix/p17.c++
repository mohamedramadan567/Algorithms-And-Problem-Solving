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

bool IsNumberInMatrix(int Matrix[3][3], int Number, short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][j] == Number)
            return true;
        }
    }
    return false;
}

int main()
{
    int Matrix1[3][3]; //= {{0, 0, 12}, {0, 0, 1}, {0, 0, 9}};
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    int Number;
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nPlease enter the number to look for in the matrix? ";
    cin >> Number;
    if(IsNumberInMatrix(Matrix1, Number, 3, 3))
    cout << "\nYes it is there\n";
    else
    cout << "\nNo it is NOT there\n";
    return 0;
}