#include <iostream>
#include<process.h>
#include<conio.h>

using namespace std;

int main()
{
    system("cls");
   int n;
   cout<<"Enter the no. of test cases";
   cin>>n;
   if(n>=40)
   {

       cout<<"overflow"<<endl;
       exit(0);
   }
   int a[40];
   for(int i=0;i<n;i++)
   {

       cin>>a[i];
   }
   int rev=0,b[40];
   for(int i=0;i<n;i++)
   {
    while(a[i]>0)
    {
        rev=(rev*10)+a[i]%10;
        a[i]/=10;

    }
b[i]=rev;
rev=0;
   }
   cout<<endl<<endl<<"The reversed list is - "<<endl;
   for(int j=0;j<n;j++)
   {
       cout<<b[j]<<endl;
   }
   getch();
}
