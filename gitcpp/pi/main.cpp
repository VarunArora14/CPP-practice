#include <iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;

int main()
{

 char str[50];
 string a[20] ;
 int n,b;
 cout<<"Enter pi ";
 gets(str);
 if(!isdigit(str))
 {

     cout<<"incorrect input ";
     exit(1);
 }
 cout<<endl<<"Enter the number of values you want to search in the pi string(<20)";
 cin>>b;

 cout<<"Enter the strings to be searched for";
 int i,j;
 for(i=0;i<b;i++)
 {

     gets(a[i]);
 }
 int flag=1;
 for(i=0;i<b;i++)
 {
     if(strstr(str,a[i])==0)
        {flag=0;}
     else
     {
         flag=1;
     break;

 }

 }
    if(flag==0)
    {


    }
    else{

        cout<<"all the strings not in the given string";
    }

}
