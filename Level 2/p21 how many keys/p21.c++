/*#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout<<Message<<endl;
        cin>>Number;
    } while (Number<0);
    return Number;
}
int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
string GenerateKey()
{
    string key="";
    for(int i=1;i<=16;i++)
    {

        key+=char(RandomNumber(65, 90));

        if((i)%4==0)
        {
            key+='-';
        }
    }
    key.pop_back();
    return key;
}
void NumberOfKeys(int NumKeys)
{
    for(int i=1;i<=NumKeys;i++)
    {
        cout<<"Key["<<i<<"]"<<": "<<GenerateKey()<<endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));

    NumberOfKeys(ReadPositiveNumber("Please Enter the number of keys?"));


    return 0;
}

/*******************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    digit = 4
};
int RandomNumber(int From, int To)
{
    // Function to generate a random number
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
int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

string GenerateWord(enCharType CharType, short length)
{
    string word = "";
    for (int i = 1; i <= length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}

string GenerateKey()
{
    string key = "";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4);
    return key;
}
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key[" << i << "] : " << GenerateKey() << endl;
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please Enter number of keys?"));

    return 0;
}