#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


int main()
{   int i;
string str;
char b[50];
getline(cin,str);  // not gets() as it is for char*
int a;
a=str.length(); // strlen() for char* so conversion not possible
cout<<a<<endl;
if(a<50)
{
    for(i=0;i<a;i++)
    {
        b[i]=str[i];
    }
    cout<<endl<<"the characterwise string is "<<endl;
    for(i=0;i<a;i++)
    {
        cout<<b[i]<<" ";
    }
}

}