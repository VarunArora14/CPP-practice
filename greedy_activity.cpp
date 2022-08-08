#include<iostream>

using namespace std;

//sort activites in order of their finishing time, first activity is printed then check
// for activities starting after f[i] and continue
int i=0;

int activity_recurse(int s[],int f[],int k, int n)
{
    // int s[]={};
    // We need to start from the first activity and see that which one has the first finishing 
    // time and then later on find the early finishing tasks from sorted list
    i=k+1;

    while (i<n && s[i]<f[k])
    {
        i++;
    }

    if(i<n) {
        cout<<f[i];
        return activity_recurse(s,f,i,n);
    }
    else
    {
        return 0;
    }
    
    
    
    // if(k<n) if(f[j]<f[i]) i=j; -> maintaining the position of tasks which end first

    
}

int j=0;
int activity2(int s[] ,int f[]  ,int n)
{   cout<<"\n \n";
    // j=k+1;
    // output the forirst one as it has the smalleat finishing time
    int i=0;
    cout<<f[i];
    for(j=1;j<n;j++)
    {
        if(s[j]>=f[i])
        {
            i=j;
            cout<<" "<<f[i];

        }
    }
}

int activity_dp(int s[] ,int f[] ,int n) //tbc
{
    int i=0,j=0;
    int dp[n+1][n+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            // if(i==0 || j==0) dp[i][j]=0;

            //else if()
        }
    }
}

int main()
{   
    //If the s[] and f[] array are not sorted initially then sort them first and then the same
    // as iterative or recursive solution
    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    cout<<f[i];
    activity_recurse(s,f,0,n);
    activity2(s,f,n);
}