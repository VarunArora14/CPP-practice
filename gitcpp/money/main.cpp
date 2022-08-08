#include <iostream>
#include<math.h>

using namespace std;

int calc(int a[], int t);
;
int main()
{
   cout<<"test cases";
   int t,i;
   cin>>t;
   cout<<endl<<"Enter the money";
   int a[100000];
   for(i=0;i<t;i++)
   {

       cin>>a[i];
   }
calc(a,t);

}

int calc(int a[100000] ,int t)
{
    int sample;
    long double sr;

    int count1;
    for(int i=0;i<t;i++)
    {sr=0;
        count1=0;
        while(a[i]>1)
        {sr=sqrt(a[i]);
        if(sr-floor(sr)==0)
        {
            //integer
            a[i]=sqrt(a[i]);
             count1++;

        }
        else
        {a[i]--;
       count1++;

        }

        }

        sample=count1%2;
         cout<<endl<<sample<<endl;
        }

    }

