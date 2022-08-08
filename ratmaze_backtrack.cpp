// INCOMPLETE

// Here we create the rat maze backtracking problem given that there is a maze in which the rat
// can go to few placs only
// Problem link - https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
#include<iostream>

using namespace std;
// NOTE - Rat can only move in 2 directions - forward and down so (i+1,j)->down , (i,j+1)->right
int issafe(int i, int j , int maze[4][4])
{
    if (i>=0 && i<4 && j>=0 && j<4 && maze[i][j]==1 )
    {
         return 1;
        // else if(maze[i][j]==2) 
        // print ans
        // Or just put it in recurse as initial check as for 1*1 where start=end=2
    } 

    
}

// TO check for safe paths we create issafe() and check for each value of movement
// Now it can either move down->(x,y+1) , move right->(x+1,y) or move left->(x-1,y)

int recurse(int maze[4][4], int x , int y , int pathi[] ,int pathj[], int ans[][4])
{
    int i,j;
    int next_x,next_y;

    // if(maze[x][y]==2) Print as destination met 

    for(i=0;i<3;i++)
    {
        next_x = x + pathi[i];
        next_y = y + pathj[i];
        if(issafe(next_x,next_y,maze))
        {   

            // ans[next_x][next_y]=1;
            if(recurse(maze,next_x,next_y,pathi,pathj,ans)==1)
            {
                 return 1;
            }
            else
            {
                // backtrack
                ans[next_x][next_y]=0;
            }
            
        }
    }
    return 0;
}

int solve()
{
    int maze[4][4] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,2}};
    // In this the 0 represents dead end
  // start
    // |
    // v
    // 1   0   0   0
    // 1   1   0   1
    // 0   1   0   0
    // 1   1   1   2 ->end

    // We start at maze[0][0]

    //From (1,1) we have 3 options -> left(1,0) ,right(1,2), bottom(2,1)

    int ans[4][4];
    int i,j;
    // int pathx[3] = {1,-1,0};
    // int pathy[3] = {0, 0,1};

    // below is correct
    int pathi[]={0,0,1};
    int pathj[]={-1,1,0};

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            ans[i][j]=0;
        }
    }
    // cout<<maze[2][0]<<" "<<maze[2][1];
// if(recurse(maze,0,0,ans)==0) NOT FOUND
// else print ans
}
int main()
{
    solve();
}