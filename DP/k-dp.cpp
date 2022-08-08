#include<iostream>

using namespace std;

int func()
{
    int val[] = {10,15,40,50};
    int weight[]= { 1,2,3,4} ;
    int n = sizeof(val)/sizeof(val[0]);
    // cout<<"enter weight";
    int W=6;
    // cin>>W;
    int i,j;
    int dp[W+1][n+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }

            else if(weight[i-1]<=j) //else if and not only if
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j] );//note i-1 for all
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
func();
}