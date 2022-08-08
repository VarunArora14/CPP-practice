// /*
// Given weights and values of n items, put these items in a knapsack of capacity W to get 
// the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1]
// and wt[0..n-1] which represent values and weights associated with n items respectively.
// Also given an integer W which represents knapsack capacity, find out the maximum value subset 
// of val[] such that sum of the weights of this subset is smaller than or equal to W.
// You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
// */
// #include<iostream>
// #include<algorithm>
// #include<stdlib.h>

// int main()
// {
//     int value[] = {10,15,40};
//     int weight[]= { 1,2,3} ;
//     std::cout<<"enter the max weight";
//     int w;
//     std::cin>>w;
//     int i,j;
//     int len = sizeof(value)/sizeof(value[0]);

    
//     int knapsack[len+1][w+1];
//     for(i=0;i<=len;i++)
//     {
//         for(j=0;j<=w;j++)
//         {
//             if(i==0 || j==0)
//             {
//                 knapsack[i][j] = 0;
//             }

//             else if (weight[i-1]<=j)
//             {
//    knapsack[i][j] = std::max(value[i-1] + knapsack[i-1][j-weight[i-1]] , knapsack[i-1][j]);
//             }
//             else
//             {
//                 /* code */
//                 knapsack[i][j] = knapsack[i-1][j];
//             }
            
//         }

//         for(i=0;i<=len;i++)
//         {
//             for(j=0;j<=w;j++)
//             {
//                 std::cout<<knapsack[i][j]<<" ";
//             }
//             std::cout<<"\n";
//         }
//     }

// }


// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include<stdio.h>
#include<iostream> 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
int i, w; 
int K[n+1][W+1]; 

// Build table K[][] in bottom up manner 
for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]] , K[i-1][w]); 
		else
				K[i][w] = K[i-1][w]; 
	} 
} 

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            std::cout<<K[i][w]<<" ";
        }
        std::cout<<"\n";
    }

} 

int main() 
{ 
	int val[] ={10,15,40,50} ; 
	int wt[] = {1, 2, 3, 4}; 
	int W = 6; 
	int n = sizeof(val)/sizeof(val[0]); 
	knapSack(W, wt, val, n); 
	return 0; 
} 

//{10, 15, 40,50}
//{1, 2, 3,4}