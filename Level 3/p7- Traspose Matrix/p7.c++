#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short rows, short cols)
{
    short Counter = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
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

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
        }
        
    }
}

int main()
{
    
    int arr[3][3], arrTransposed[3][3];
    FillMatrixWithOrderedNumbers(arr, 3, 3);
    
    cout << "\nThe following is a 3x3 ordered matrix: \n";
    PrintMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);
    cout << "\nThe following is the transeposed matrix: \n";
    PrintMatrix(arrTransposed, 3, 3);
    
    return 0;
}
