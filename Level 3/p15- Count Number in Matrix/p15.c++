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


void ReadNumber(short& GivenNumber)
{
    cout << "\nEnter the number to count in matrix: ";
    cin >> GivenNumber;
}


int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{9, 1, 12}, {0, 9, 1}, {0, 9, 9}};
    short Number;
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    ReadNumber(Number);

    cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;
    return 0;
}
