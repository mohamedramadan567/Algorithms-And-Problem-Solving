// I cannot able to answer this
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int RandomNumber(int From, int To) 
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); //I donnot no why this not run at Vs code but it run in Vs community
    cout<<RandomNumber(1, 10)<<endl;
    cout<<RandomNumber(1, 10)<<endl;
    cout<<RandomNumber(1, 10)<<endl;
    
    
    return 0;
}
