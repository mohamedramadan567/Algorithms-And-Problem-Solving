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


int Count(int Matrix[3][3], short rows, short cols, short GivenNumber)
{
    int count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if(Matrix[i][j] == GivenNumber)
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
    short GivenNumber;
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    ReadNumber(GivenNumber);

    cout << "\nNumber " << GivenNumber << " count in matrix is " << Count(Matrix1, 3, 3, GivenNumber) << endl;
    return 0;
}
