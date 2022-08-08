//Coin-DP problem

// Given that there are N coins of different values, find minimum no. of coins required to reach
// a given sum. Input the coin array and the sum value to be matched  

#include<iostream>

int main()
{
    int len,a[20];
    std::cout<<"enter len";
    std::cin>>len;
    std::cout<<"enter array";
    int i,j;
    for(i=0;i<len;i++)
    {
        std::cin>>a[i];
    }


    std::cout<<"enter sum max value";
    int sum;
    std::cin>>sum;

    int min[20];
    for(i=0;i<20;i++)
    {
        min[i]= INT32_MAX;
    }

    min[0]=0;

    for (  i = 1; i <= sum; i++)
    {
        for ( j = 0; j < len; j++)
        {
            if(a[j]<=i && (min[i-a[j]] + 1 < min[i]))
            //a[j]<=i and not a[j]<i
            {
                min[i] = min[i-a[j]] + 1;
            }
        }
        
    }

  for ( i = 0; i <=sum; i++)
  {
      std::cout<<min[i]<<" ";
  }
  
    
}