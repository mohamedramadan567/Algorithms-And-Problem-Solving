// مش هيرن مش عارف ليه بس جربه ع الكومينتي هيشتغل عادي
#include<iostream>
#include<string>
using namespace std;
void PrintHeaderTable()
{
    cout << "\n\n\t\t\tMultiplication Table From 1 to 12\n\n";
    cout << "\t";
    for (int i = 1; i <= 12; i++)
    {
        cout << i << "\t";
    }
    cout << "\n--------------------------------------------------------------------------------------------------\n";
}
string ColoumSperator(int i)
{
    if (i < 10)
        return "     |";
    else
        return "    |";
}
void PrintMultiplicationTable()
{
    PrintHeaderTable();
    for (int i = 1; i <= 12; i++)
    {
        cout << " " << i << ColoumSperator(i);
        for (int j = 1; j <= 12; j++)
        {
            cout << i * j << "\t";

        }
        cout << "\n";
    }
}
int main()
{
    PrintMultiplicationTable();

    return 0;
}
