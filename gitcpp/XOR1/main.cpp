#include <iostream>
#include<process.h>

using namespace std;

int main()
{
   int q=1,w=2,k;
   k=q^w;
   cout<<k;
   cout<<"enter the size";
   int n;
   cin>>n;
   while(n%2!=0)
   {

       cout<<"the size must be even only";
       exit(0);
   }
   cout<<"enter array";
   int i,a[40];
   for(i=0;i<n;i++)
   {

       cin>>a[i];
   }
   int res=0;
   for(i=0;i<n;i++)
   {

       res^=a[i];   //xor all the elements - we get xor of distinct numbers
   }
   //now we neeed the rightmost bit of the above xor to get the 2 nmubers because that 1 means one number had a 0 and another had 1 while the xor worked so we looks at the rightmost bit of the xor

   int setbit;
   setbit=res&(~(res-1));     //rightmost bit of the xor
   // now we search for htose 2 numbers
   int m1=0,m2=0;
   /*
   now we divide the elements in 2 sets of having the last bit and not having it . Evetually , as the no. of elements are 2n
   , we would see that xor of the samne number shaving the same rightmost setbit would vanish and at last we will have the
   the numbers , here m1 and m2 which have been the xor of the condition*/
   for(i=0;i<n;i++)
{
    if(setbit&a[i])//bool as 0 or 1
    m1=m1^a[i];
    else
        m2=m2^a[i];

}


cout<<"repeating numbers are "<<m1<<" and "<<m2;
}
