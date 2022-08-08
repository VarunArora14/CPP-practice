#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
   char a[10][10];
   int i,j;
   cout<<"size ";
   cin>>j;
   cout<<1<<endl;
   for( i=0;i<j;i++)
   {

       gets(a[i]);
   }
    for( i=0;i<j;i++)
   {

       puts(a[i]);
   }
}
