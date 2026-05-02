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
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
}

short SumOfMatrix(int Matrix[3][3], short rows, short cols)
{
    short Sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}

bool AreEqaulMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short cols)
{
    return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];
    short Sum1, Sum2;
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    if(AreEqaulMatrices(Matrix1, Matrix2, 3, 3))
    cout << "\nYES: both matrices are equal.\n";
    else
    cout << "\nNO: matrices are NOT equal.\n";
    return 0;
}

