#include<iostream>
#include<string>

using namespace std;

void lcs()
{
string s1,s2;
int k=0;
string final;
s1="aggtab";
s2="gxtxayb";
int m=s1.length();
int n=s2.length();
int i,j;
int dp[m+1][n+1];
for(i=0;i<=m;i++)
{
    for(j=0;j<=n;j++)
    {   
        if(i==0||j==0)
        {
            dp[i][j]=0;
        }
// OR - declare dp[i][0] and dp[0][j]=0 and then inside the j loop put 
//dp[i][j] = max(dp[i-1][j],dp[i][j-1]) and then next line
// if(s1[i-1]==s2[j-1]){ dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]); }


// 10010101 and 010110110 where lcs=6 and sequence - 100110
// The below code gives answer 5 which is incorrect because of s1[i]==s2[j]
        else if(s1[i-1]==s2[j-1])//s1[i-1] == s2[j-1] and NOT s1[i]==s2[j]
        {
            dp[i][j] = 1 + dp[i-1][j-1];
            final.push_back(s2[j-1]);
        }
        else
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
}

for(i=0;i<=m;i++)
{
    for (j  = 0;  j<= n; j++)
    {
        cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
    
}

cout<<"\n \n The longest common subsequence is "<<final;


}


int main()
{
    lcs();
}

/*
In order to have time complexity of O(m+n) we need to change the lcs function as we know that
we need only 2 rows of array to compute the dp array
the function is lcs(dp,s1,s2,i,j)

Here we have array dp[][] which stores the values of the lcs, s1 and s2 strings and i,j their lemgths

Without using b table lcs where b table shwed the arrows of where the s1[i-1]==s2[j-1]
lcs(dp,s1,s2,i,j)
{
    if(s1[i]==s2[j])
    {
        //this will show backward longest subsequence as initially i=m and j=n
        // better if cout<<s1[i]; after lcs() function as it will be in stack and then display

        lcs(dp,s1,s2,i-1,j-1);
        cout<<s1[i];
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        lcs(dp,s1,s2i-1,j);
    }
    else
    {
        lcs(dp,s1,s2,i,j-1);
    }
}

*/