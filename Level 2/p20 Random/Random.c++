// My solution
/*#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enRandom { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };
int ReadChoice()
{
    int n;

    cout << "To random samll letter enter 1\n";
    cout << "To random capital letter enter 2\n";
    cout << "To random special character enter 3\n";
    cout << "To random digit enter 4\n";
    cout << "Enter your choice?\n";
    cin >> n;

    return n;
}
enRandom CheckChoice(int Number)
{
    if (Number == 1) return enRandom::SmallLetter;
    else if (Number == 2) return enRandom::CapitalLetter;
    else if (Number == 3) return enRandom::SpecialCharacter;
    else if (Number == 4) return enRandom::digit;
}
char Random(int Number)
{
    //Function to generate a random number
    char ran;

    if (CheckChoice(Number) == enRandom::SmallLetter)
    {

        ran = char(rand() % (122 - 97 + 1) + 97);
    }
    else if (CheckChoice(Number) == enRandom::CapitalLetter)
    {
        ran = char(rand() % (90 - 65 + 1) + 65);
    }
    else if (CheckChoice(Number) == enRandom::SpecialCharacter)
    {
        ran = char(rand() % (47 - 33 + 1) + 33);
    }
    else if (CheckChoice(Number) == enRandom::digit)
    {
        ran = char(rand() % (57 - 48 + 1) + 48);
    }
    return ran;
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); //I donnot no why this not run at Vs code but it run in Vs community
    int contin;
    do
    {
        cout << Random(ReadChoice())<<endl;
        cout << "If you want repeat enter 5\n";
        cin >> contin;
    } while (contin == 5);



    return 0;
}

/*************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4 };
int RandomNumber(int From, int To) 
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    }
    
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 
    cout<<GetRandomCharacter(enCharType::SmallLetter)<<endl;
    cout<<GetRandomCharacter(enCharType::CapitalLetter)<<endl;
    cout<<GetRandomCharacter(enCharType::SpecialCharacter)<<endl;
    cout<<GetRandomCharacter(enCharType::digit)<<endl;
    
    
    return 0;
}
