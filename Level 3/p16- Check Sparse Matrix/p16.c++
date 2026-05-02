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
            arr[i][j] = RandomNumber(0, 10);
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

short CountNumberInMatrix(int Matrix[3][3], int Number, short rows, short cols)
{
    short count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][j] == Number)
            count++;
        }
    }
    return count;
}

bool IsSparseMatrix(int Matrix[3][3], short rows, short cols)
{
    short MatrixSize = rows * cols;

    return (CountNumberInMatrix(Matrix, 0, rows, cols) >= (MatrixSize / 2));
}

int main()
{
    int Matrix1[3][3] = {{0, 0, 12}, {0, 0, 1}, {0, 0, 9}};
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if(IsSparseMatrix(Matrix1, 3, 3))
    cout << "\nYes: it is sparse\n";
    else
    cout << "\nNo: it is NOT sparse\n";
    return 0;
}
