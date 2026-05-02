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

void ReadRondomMatrix(int arr[100][100])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
            
        }
    }
}

void PrintRandomMatrix(int arr[100][100])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 
    int arr[100][100];
    ReadRondomMatrix(arr);
    cout << "The following is a 3*3 random matrix: \n";
    PrintRandomMatrix(arr);
    return 0;
}

/******************************************************************************************************/
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
            cout <<left << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix: \n";
    PrintMatrix(arr, 3, 3);
    return 0;
}