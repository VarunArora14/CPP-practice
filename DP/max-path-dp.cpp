#include<iostream>
//GIven a matrix on M*M size, with each cell of specific cost, where you can move only right or
//down. Starting from (0,0) , find the maximum average over all existing paths.
int main()
{
    int a[3][4]= {{1,2,3,4},{1,1,1,1},{9,9,9,9}};

    int cost[4][4] ={0};
    int i,j;
    cost[0][0] = a[0][0];
for(i=1;i<3;i++)
{
    cost[i][0] = cost[i-1][0]  + a[i][0]; 
}

    for(j=1;j<4;j++)
    {
        cost[0][j] = cost[0][j-1]  + a[0][j];
    }

    for(i=1;i<3;i++)
    {
        for(j=1;j<4;j++)
    {
        cost[i][j] = std::max(cost[i-1][j],cost[i][j-1]) + a[i][j];
    }
    }

    

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            std::cout<<cost[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}