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


bool IsScalarMatrix(int Matrix[3][3], short rows, short cols)
{
    short FirstDiagElement = Matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            //check for diagonals element
            if((i == j) && (Matrix[i][j] != FirstDiagElement))
            return false;

            //check for rest elements
            else if((i != j) && (Matrix[i][j] != 0))
            return false;
        }
    }
    return true;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if(IsScalarMatrix(Matrix1, 3, 3))
    cout << "\nYES: Matrix is Scalar.\n";
    else
    cout << "\nNO: Matrix is NOT Scalar.\n";
    return 0;
}
