#include <iostream>
#include<conio.h>
#include<process.h>

using namespace std;

int main()
{
  int n,a[10];
  char ch='y';
  cout<<"enter size(<10)<"<<endl;
  cin>>n;
  cout<<"Enter array";
  int i=0;
  for(i=0;i<n;i++)
  {
      cin>>a[i];

  }
  cout<<"enter size of the window";
  int b;
  cin>>b;
  int min1,count1=0;
  do
  {
      if(count1+3>n)
      {

          cout<<"overflow ";
          exit(0);
      }
      min1=a[count1];
   for(i=count1;i<b;i++)
   {
    if(min1>a[i])
    {
    min1=a[i];
   }
   }
   cout<<min1<<endl;
   cout<<"do you want to continue ? ";
   cin>>ch;
   if(ch=='y')
   {   count1++;
   min1=a[count1];
       b++;
   }

   }while(ch=='y');
   getch();
    return 0;
}
