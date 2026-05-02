//i can't solve it.
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

bool IsMatrixPalindrome(int Matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][0] != Matrix[i][2])
            return false;
        }
    }
    return true;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short rows, short cols)
{
    int Number;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            Number = Matrix1[i][j];
            if(IsNumberInMatrix(Matrix2, Number, rows, cols))
            cout << Number << "\t";
        }
    }
}

int main()
{
    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} } ;
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n\n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);
    return 0;
}