#include <iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main()
{

    system("cls");
   int t;
   cout<<"hello"<<endl;
   cout<<"Enter the no. of test cases";
   cin>>t;
   int i,a[20],x[20];
   for(i=0;i<t;i++)
   {

       cin>>a[i];
       x[i]=a[i]/12;

   }
int b;
   for(i=0;i<t;i++)
   {
b=a[i]%6;
       cout<<(24*(x[i])+13-a[i]);
        switch(b)
       {
           case 0: cout<<"WS";
           break;
           case 1: cout<<"WS";
           break;
           case 2: cout<<"MS";
           break;
           case 3: cout<<"AS";
           break;
           case 4: cout<<"AS";
           break;
           case 5: cout<<"MS";

   }
   cout<<endl;
   }

   getch();
}


