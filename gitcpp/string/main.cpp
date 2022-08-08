#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    int i;
    char s[10][20];
    cout<<"enter max no. of strings";
    int size;
    cin>>size;
    for(i=0;i<=size;i++)
    {
       gets(s[i]);
    }
    cout<<endl<<"the strings are "<<endl;
     for(i=1;i<=size;i++)
    {
        cout<<(s[i])<<endl;
    }
    char a[20];
    strcpy(a,s[1]);
    cout<<"a is "<<a<<endl;
    int flag=0;
    for(i=2;i<=size;i++)
    {
if(strstr(s[i],a))
{
    flag=1;
    cout<<"sizeof a is "<<strlen(a)<<" sizeof s[i] is "<<strlen(s[i])<<endl;
    if(strlen(a) <  strlen(s[i]))
    {

    strcpy(a,s[i]);
    }
    cout<<endl<<"now a is "<<a<<endl;
}
    }
    if(flag==0)
    {
        cout<<"string not found";
    }
    else
    {
        cout<<"max string is found "<<endl<<a;
    }

}
