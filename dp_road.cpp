// #include<iostream>

// using namespace std;

// int knap()
// {
//     int rev[] ={5, 6, 3,  7};
//     int x[] = {6, 9, 12, 14};
//     int t=2;
//     int m = 15;
//     int i,j;
//     int n = sizeof(x)/sizeof(x[0]);
//     int temp=0;
//     cout<<"n is "<<n<<"\n";
//     int dp[n+1][m+1];

//     for( i=0;i<=n;i++)
//     {
//         for( j=0;j<=m;j++)//j++ not i++
//         {
//             if(i==0||j==0)
//             {
//                 dp[i][j]=0;
//             }

//         else if(x[i-1]<=j && (x[i-1]-temp)>t)// should not use rev[i-1]<=j
//         {   
// //             if(x[i-1]==12)
// //             {
// //   cout<<"hi "<<x[i-1]-temp<<" j is "<<j<<"rev[i-1] = "<<rev[i-1]<<"j-x[i-1] "<<j-x[i-1]<<" \n";
// //             }
//             temp=x[i-1];
//             dp[i][j] = max(dp[i-1][j], rev[i-1] + dp[i][j-1]);
//         }

//         else
//         {
//             // dp[i][j] = dp[i-1][j];
//             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
        
        
//         }
//     }
//         for( i=0;i<=n;i++)
//         {
//             for( j=0;j<=m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<"\n";
        
//         } 


// return dp[n][m];
// }

// int main()
// {
//     cout<<knap();
// }

// // knapsack way is not working because j-x[i] = 0 for x[i] = 12 and then dp[i][0] = 0
// // so rhther than addding 5, 0 is added



#include<iostream>
using namespace std;

int billboard(int x[], int revenue[], int n, int t)
{
	int *bill = new int[x[n-1]+1];
	int *cost = new int[x[n-1]+1];
	for(int i=0;i<=x[n-1];i++)
	{
		cost[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cost[x[i]]=revenue[i];
	}
	bill[0]=cost[0];
	for(int i=1;i<=x[n-1];i++)
	{
		int temp = cost[i];
		if(i-t-1>=0)
			temp+=bill[i-t-1];
		bill[i]=max(bill[i-1],temp);
	}
	return bill[x[n-1]];
}
int max(int a, int b)
{
	return a>b?a:b;
}
int main()
{

	int x[]       = {6, 7, 12, 13, 14};
    int revenue[] = {5, 6, 5,  3,  1};

    cout<<billboard(x,revenue,5, 5);
    return 0;
}