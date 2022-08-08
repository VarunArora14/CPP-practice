#include<iostream>
#include<stdlib.h>

int main()
{
   
    
     int n=6;
    int a[]={2,7,4,1,5,3};
    int i;
    
    
    int j,t,c=0,f=0;
    for(i=0;i<n;i++)
    {   f=0;
        for(j=0;j<n-i;j++)
        //do not initialise j from i to n-1 as of previous selection sort but from 0 to n-i
        {
            if(a[j]>a[j+1])
            {
              //  std::swap(a[j],a[j+1]);
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
              f=1;

            }
        }
        if(f==0) break;
        std::cout<<c++<<"\n";
    }

    for(i=0;i<n;i++)
    {
        std::cout<<a[i];
    }
}