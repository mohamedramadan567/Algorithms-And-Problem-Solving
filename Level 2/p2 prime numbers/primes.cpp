// my answer
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
enum enPrimeOrNot
{
    Prime = 1,
    NotPrime = 2
};
int ReadPositiveNumber(string Message)
{
    int Number;

    do
    {
        cout << Message << " ";
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
enPrimeOrNot CheckPrime(int Number)
{
    int M = Number / 2;
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::Prime;
}
void PrintPrimesNumber(int Number)
{
    while (Number > 1)
    {
        if (CheckPrime(Number) == enPrimeOrNot::Prime)
            cout << Number << endl;
        Number--;
    }
}
int main()
{
    PrintPrimesNumber(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}

// his answer
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
enum enPrimeOrNot
{
    Prime = 1,
    NotPrime = 2
};
int ReadPositiveNumber(string Message)
{
    int n;

    do
    {
        cout << Message << " ";
        cin >> n;
    } while (n <= 0);

    return n;
}
enPrimeOrNot CheckPrime(int Number)
{
    int M = Number / 2;
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::Prime;
}
void PrintPrimeNumbersFrom1toNumber(int Number)
{
    cout << "\n";
    cout << "Prime Numbers from 1 to " << Number;
    cout << " are: " << endl;
    for (int i = 2; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimeOrNot::Prime)
            cout << i << endl;
    }
}
int main()
{
    PrintPrimeNumbersFrom1toNumber(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}