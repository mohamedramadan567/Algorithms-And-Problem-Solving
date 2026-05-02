// I cannot able to answer this
#include <iostream>
#include <string>
using namespace std;
string ReadText()
{
    string text;
    cout<<"Please enter Text?"<<endl;
    getline(cin, text);
    
    return text;
}
string EncryptionText(string text, short EncryptionKey)
{
    for(int i=0; i<text.length(); i++)
    {
        text[i] = char((int)text[i]+EncryptionKey);
    }
    return text;
}
string DencryptionText(string text, short EncryptionKey)
{
    for(int i=0; i<text.length(); i++)
    {
        text[i] = char((int)text[i]-EncryptionKey);
    }
    return text;
}
int main()
{
    
    const short EncryptionKey = 2;
    string Text = ReadText();
    string TextAfterEncryption = EncryptionText(Text, EncryptionKey);
    string TextAfterDencryption = DencryptionText(TextAfterEncryption, EncryptionKey);

    cout <<"\nText before Encryption: "<<Text<<endl;
    cout<<"Text after Encryption: "<<TextAfterEncryption<<endl;
    cout<<"Text after Decryption: "<<TextAfterDencryption<<endl;
    
    return 0;
}
