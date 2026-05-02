#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
//#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
enum enPassFail { Pass = 1, Fail = 2 };
float ReadMark()
{
    float Mark;
    cout << "Enter Mark? " << endl;
    cin >> Mark;

    return Mark;
}
enPassFail CheckMark(float Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
void Result(float Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\nYou Passed\n";
    else
        cout << "\nYou Failed\n";

}
int main()
{
    //MR1
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Result(ReadMark());

    return 0;
}