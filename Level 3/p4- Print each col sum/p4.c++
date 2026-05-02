#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int ColSum(int arr[3][3], short colNumber, short rows)
{
    int Sum = 0;
    for (int i = 0; i < rows; i++)
    {
        Sum += arr[i][colNumber];
    }
    return Sum;
}

void PrintEachColSum(int arr[3][3], short rows, short cols)
{
    cout << "\nThe the following are the sum of each Col in the matrix: " << endl;
    for (int j = 0; j < cols; j++)
    {
        cout << "Col " << j + 1 << " Sum = " << ColSum(arr, j, rows) << endl;
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);

    PrintEachColSum(arr, 3, 3);
    
    return 0;
}
