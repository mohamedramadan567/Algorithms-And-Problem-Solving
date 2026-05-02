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


bool IsIdentityMatrix(int Matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if((i == j) && (Matrix[i][j] != 1))
            return false;
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

    int Matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    
    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if(IsIdentityMatrix(Matrix1, 3, 3))
    cout << "\nYES: Matrix is identity.\n";
    else
    cout << "\nNO: Matrix is NOT identity.\n";
    return 0;
}
