#include<iostream>
#include<stdlib.h>
// Given an array of integers each element representing the number of steps, find max number
//of steps  that can be made forward from that element. Write a function to return the minimum 
//number of jumps to reach the end of the array (starting from the first element). If an 
//element is 0, then cannot move through that element.
int main()
{
    int a[20]={1, 3, 6,1,0,9};
    std::cout<<"enter len";
    int len=6;
    // std::cin>>len;
    int i,val,j,big,sum=0,count=0,k=0;
    int t[10];
    // for(i=0;i<len;i++)
    // {
    //     std::cin>>a[i];
    // }

   
    big=0;
    for(i=0;i<len;i++)
    {   big=a[i];
        val=i;
        if(a[i]==0)
        {
            std::cout<<"cannot move further";
            break;
            exit(0);
        }
        for(j=i+1;j<=i+a[i] && j<len;j++)
        {
            if(big<a[j])
            {
                big=a[j];
                val=j;

            }
        }
        if(val!=i)
        {
            i=val;
            count++;
            sum+=big;
            t[k++]=big;
        }
        
        
    }

    std::cout<<"The min steps are "<<count<<" sum is "<<sum<<" and big is "<<big<<"\n";

    for(i=0;i<k;i++)
    {
        std::cout<<t[i]<<" ";
    }

}
