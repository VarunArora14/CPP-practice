#include<iostream>


int main()
{
    int dp[100],i,j;
    dp[0]=1;
    dp[1]=1;
    std::cout<<"Enter the number ";
    int n;
    std::cin>>n;
    for(i=2;i<n;i++)
    {
        dp[i]= 2*dp[i-1] + dp[i-2];
    }

    std::cout<<"\n The newmann series till "<<n<<" numbers is \n";

    for(i=0;i<n;i++)
    {
        std::cout<<dp[i]<<"\n";
    }

}