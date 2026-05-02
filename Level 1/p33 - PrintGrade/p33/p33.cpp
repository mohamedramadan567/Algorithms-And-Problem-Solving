#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#define ll long long
#define MR1 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
enum enGrades { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6 };
int ReadGrade()
{
    int Grade;
    do
    {
        cout << "Please enter your grade\n";
        cin >> Grade;
    } while (Grade > 100 || Grade < 0);
    return Grade;
}
enGrades Grades(int Grade)
{
    if (Grade <= 100 && Grade >= 90)
        return enGrades::A;
    else if (Grade < 90 && Grade >= 80)
        return enGrades::B;
    else if (Grade < 80 && Grade >= 70)
        return enGrades::C;
    else if (Grade < 70 && Grade >= 60)
        return enGrades::D;
    else if (Grade < 60 && Grade >= 50)
        return enGrades::E;
    else if (Grade < 50 && Grade >= 0)
        return enGrades::F;
}
void PrintGrade(int Grade)
{
    if (Grades(Grade) == enGrades::A) cout << "A";
    else if (Grades(Grade) == enGrades::B) cout << "B";
    else if (Grades(Grade) == enGrades::C) cout << "C";
    else if (Grades(Grade) == enGrades::D) cout << "D";
    else if (Grades(Grade) == enGrades::E) cout << "E";
    else if (Grades(Grade) == enGrades::F) cout << "F";
}
int main()
{
    //MR1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PrintGrade(ReadGrade());
    return 0;
}