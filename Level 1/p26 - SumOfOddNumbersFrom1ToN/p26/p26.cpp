#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int ReadNumber()
{
    int Num;
    cout << "Please enter Number ?" << endl;
    cin >> Num;
    return Num;

}
//bool CheckAge(int Age, int From, int To)
//{
//    return (Age >= From && Age <= To);
//
//}
void PrintNumbers(int Num)
{
    int counter = Num + 1;
    cout << "\nSum of odd numbers from 1 to " << Num << " is : " << endl;
    do
    {
        counter--;
        cout << counter << " ";
    }while (counter > 1);
    cout << endl;
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PrintNumbers(ReadNumber());

    return 0;
}