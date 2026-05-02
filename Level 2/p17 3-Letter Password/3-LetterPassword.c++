/*#include <iostream>
#include <string>
using namespace std;
string ReadPassword(string Message)
{
    string password;
    cout<<Message<<endl;
    cin>>password;
    
    return password;
}
void GuessPassword(string Password)
{
    cout<<endl;
    int NumberOfTrial=1;
    string word="";
    for(int i=65;i<=90;i++)
    {
        for(int j=65;j<=90;j++)
        {
            for(int k=65;k<=90;k++)
            {
                word=char(i);
                word+=char(j);
                word+=char(k);
                
                if(Password!=word)
                {
                    cout<<"Trial["<<NumberOfTrial<<"]: "<<word<<endl;
                }
                else if(Password==word)
                {
                    cout<<"Trial["<<NumberOfTrial<<"]: "<<word<<endl<<endl;
                    cout<<"Password is "<<word<<endl;
                    cout<<"Found after "<<NumberOfTrial<<" Trial(s)."<<endl;
                    exit(0);
                }
                NumberOfTrial++;
            }
            
        }
        
    }
}
int main()
{
    
    
    GuessPassword(ReadPassword("Please enter a 3-letter password all Caps?"));
    
    return 0;
}


/********************************************************************************************* */
#include <iostream>
#include <string>
using namespace std;
string ReadPassword()
{
    string password;
    cout<<"Please enter a 3-letter password all Caps?"<<endl;
    cin>>password;
    
    return password;
}
bool GuessPassword(string Password)
{
    cout<<endl;
    int NumberOfTrial=1;
    string word="";
    for(int i=65;i<=90;i++)
    {
        for(int j=65;j<=90;j++)
        {
            for(int k=65;k<=90;k++)
            {
                word=char(i);
                word+=char(j);
                word+=char(k);
                cout<<"Trial["<<NumberOfTrial<<"]: "<<word<<endl;
                
                if(Password==word)
                {
                    
                    cout<<"Password is "<<word<<endl;
                    cout<<"Found after "<<NumberOfTrial<<" Trial(s)."<<endl;
                    return true;
                }
                NumberOfTrial++;
            }
            
        }
        
    }
    return false;
}
int main()
{
    
    
    GuessPassword(ReadPassword());
    
    return 0;
}
