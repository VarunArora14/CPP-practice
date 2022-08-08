#include<iostream>
#include<string.h>
#include<ctype.h>



using namespace std;

int main()
{   int i,s=0;
    string str;
    getline(cin,str);
    for(i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            s+=str[i]-48;
            cout<<"now s is "<<s<<endl;
        }
    }
    cout<<endl<<"the sum is "<<s<<endl;
}