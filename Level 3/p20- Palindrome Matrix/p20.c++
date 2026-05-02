//i can't solve it.
#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include <cstdio>

using namespace std;

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

bool IsMatrixPalindrome(int Matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            if(Matrix[i][j] != Matrix[i][cols - 1 - j])
            return false;
        }
    }
    return true;
}

int main()
{
    int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

    cout << "\nMatrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if(IsMatrixPalindrome(Matrix1, 3, 3))
    cout << "\nYes: Matrix is palindrome.";
    else
    cout << "\nNo: Matrix is NOT palindrome.";
    return 0;
}