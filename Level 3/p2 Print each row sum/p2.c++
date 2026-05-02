/*#include <iostream>
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

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols, int& SumOfRow1, int& SumOfRow2, int& SumOfRow3)
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
            if(i == 0)
            {
                SumOfRow1 += arr[i][j];
            }
            else if(i == 1)
            {
                SumOfRow2 += arr[i][j];
            }
            else 
            {
                SumOfRow3 += arr[i][j];
            }
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void PrintSumOfEachRow(int SumOfRow1, int SumOfRow2, int SumOfRow3)
{
    cout << "\nThe the following are the sum of each row in the matrix: \n";
    cout << "Row 1 Sum = " << SumOfRow1 << endl;
    cout << "Row 2 Sum = " << SumOfRow2 << endl;
    cout << "Row 3 Sum = " << SumOfRow3 << endl;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[3][3];
    int SumOfRow1 = 0, SumOfRow2 = 0, SumOfRow3 = 0;
    FillMatrixWithRandomNumbers(arr, 3, 3, SumOfRow1, SumOfRow2, SumOfRow3);
    cout << "\nThe following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);

    PrintSumOfEachRow(SumOfRow1, SumOfRow2, SumOfRow3);
    return 0;
}


/*****************************************************************************************************/

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

int RowSum(int arr[3][3], short RowNumber, short cols)
{
    int Sum = 0;
    for (int j = 0; j < cols; j++)
    {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

void PrintEachRowSum(int arr[3][3], short rows, short cols)
{
    cout << "\nThe the following are the sum of each row in the matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, cols) << endl;
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

    PrintEachRowSum(arr, 3, 3);
    
    return 0;
}
