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

void PrintMiddleRowOfMatrix(int Matrix[3][3], short rows, short cols)
{
    short MiddleRow = rows / 2;
    for (int j = 0; j < cols; j++)
    {
        printf("%0*d\t", 2, Matrix[MiddleRow][j]);
    }
    cout << endl;
}

void PrintMiddleColOfMatrix(int Matrix[3][3], short rows, short cols)
{
    short MiddleCol = cols / 2;
    for (int i = 0; i < cols; i++)
    {
        printf("%0*d\t", 2, Matrix[i][MiddleCol]);
    }
    cout << endl;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int Matrix[3][3], arrRow[3], arrCol[3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\nMiddle Row of Matrix1 is: \n";
    PrintMiddleRowOfMatrix(Matrix, 3, 3);

    cout << "\nMiddle Col of Matrix1 is: \n";
    PrintMiddleColOfMatrix(Matrix, 3, 3);
    return 0;
}
