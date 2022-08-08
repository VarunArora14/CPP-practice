#include <iostream>
#include<iomanip>
// In this problem we have yo find a recursive backtracking solution
// We start by knowing that the current x and y coordinates are 0,0 and create the potential
// moves X[] and Y[] arrays for knight. We create move numbers too.
// Then we call the recurse() function taking the values and checking the safe moves
// We check for all potential moves and if yes then keep recursively checking for the next moves
// for filling the n*n array. If found all then print it, else keep moving with solution
// If current way does not lead then backtrack through recursion to change the approach
using namespace std;

#define n 8

void print(int sol[n][n]);
int issafe(int x, int y, int sol[n][n])
{
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1) ;
    // {
    //     /* code */
    //     return 1;
    // }
}
// here x and y corresponds to x and y coordinate, moveno corresponds to current move numbers
// and X[] and Y[] array corresponds to the potential knight moves
int recurse(int sol[n][n], int x, int y, int moveno, int X[], int Y[])
{
    int next_x, next_y;
    int k;
    if (moveno == n * n)
        return 1;
    // for n=1 case and final case of completion

    for (k = 0; k < 8; k++)
    {
        next_x = x + X[k];
        next_y = y + Y[k];
        // Keep on finding the safe path for all x and y and then look for next paths
        // If not found the next path then sol[][]=-1;
        if (issafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = moveno;

            // To backtrack we have to find the next value of sol[][] and if it is possible then
            // recurse() function invoked for next values else backtrack by sol[next_x][next_y]=-1

            if (recurse(sol, next_x, next_y, moveno + 1, X, Y)==1)
            {
                return 1;
            }
            else
            {   //backtrack
                sol[next_x][next_y]=-1;
            }
        }
    }
    return 0;
}

/* This function solves the Knight Tour problem using 
Backtracking. This function mainly uses recurse() 
to solve the problem. It returns false if no complete 
tour is possible, otherwise return true and prints the 
tour. 
Please note that there may be more than one solutions, 
this function prints one of the feasible solutions. */

void solve()
{
    int sol[n][n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sol[i][j] = -1;
        }
    }
    // int x[8] = {1, -1, 2, 2, -2, -2, 1, -1}; //x coordinate for knight movement
    // int y[8] = {2, 2, 1, -1, 1, -1, -2, -2}; //y coordinate for knight movement

    // Time error removed by new x[] and y[] array. Replacing with old does not lead to solution

     int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

    int moveno = 1;
    // Knight initially at first block
    sol[0][0]=0;

    if(recurse(sol, 0, 0, 1, x, y)==0)
    cout<<"solution not possible";

    else print(sol);
}

void print(int sol[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             cout << " " << setw(2) << sol[i][j] << " "; 
        }
        cout<<"\n";
    }
}

int main()
{
    solve();
}