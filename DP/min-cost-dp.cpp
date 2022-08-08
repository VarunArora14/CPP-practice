#include <iostream>
// Given a cost matrix cost[][] and a position(m, n) in cost[][], write a function that returns 
// cost of minimum cost path to reach(m, n) from(0, 0).Each cell of the matrix represents a cost
// to traverse through that cell.Total cost of a path to reach(m, n) is sum of all the costs on
// that path(including both source and destination).You can only traverse down, right and 
// diagonally lower cells from a given cell, i.e., from a given cell(i, j), cells(i + 1, j), 
// (i, j + 1) and (i + 1, j + 1) can be traversed.You may assume that all costs are positive 
// integers.

int min(int , int , int);
int main()
{
    int cost[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    int m, n,i,j;
    std::cout << "enter the positions ";
    std::cin >> m >> n;

    //inorder to find the minimum paths we need to create 2d array storing values of previous 
    //and then see the paths with min value till m,n

    int dp[m+1][n+1];

    dp[0][0]=cost[0][0];

    for(i=1;i<m;i++)
    {dp[i][0] = cost[i][0] + dp[i-1][0];}

    for(j=1;j<n;j++)
    {
        dp[0][j] = cost[0][j]  + dp[0][j-1];
    }


    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]) + cost[i][j];
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

int min(int a  , int b, int c)
{
    if(a<b)
    {
        if(a<c)
        {
            return a;
        }
        else
        {
            return c;
        }
        
    }
    else
    {
        if(b<c)
        {
            return b;
        }
        else
        {
            return c;
        }
        
    }
    
}