#include<iostream>
#include<algorithm>
//We put 2 strings s1 and s2 where s2=1 is the gien string and s2 is the reverse of that string
// Now we compare them like longest common subsequence and find the common subsequence
// length which would give the palindromic answer.  Now dp[i][j] = 1 + dp[i-1][j-1]
// when s1[i-1]==s2[j-1] as 

using namespace std;
int arr[20][20];
string palin_seq(string s1 , string s2 ,int m ,int n);
void palin(string s1, string s2, int n)
{
    int i,j;
     int dp[n+1][n+1];
    //GO to the ith position and then find the lcs of 0...i and i...n
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            //if(s1[i]==s2[j]) 
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }

            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            
            
        }
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            arr[i][j]=dp[i][j];
        }
    }
    cout<<" the lps is "<<dp[n][n];
    cout<<palin_seq(s1,s2,n,n);
}

string palin_seq(string s1 , string s2 ,int m ,int n)
{   
    
    // return empty string if we have reached the end of
	// either sequence
	if (m == 0 || n == 0)
		return string("");

    //if the characters match then return the character. Since it is a palindrome, it will match
    // 2 times
    if(s1[m-1]==s2[n-1]) 
    return palin_seq(s1,s2,m-1,n-1) + s1[m-1];

    // else when the last character of X and Y are different

	
    // if left cell of current cell has more value than the top
	// cell, then drop current character of string Y and find LCS
	// of substring X[0..m-1], Y[0..n-2]

    else if(arr[m][n-1] > arr[m-1][n])
    return palin_seq(s1,s2,m,n-1);


    // if top cell of current cell has more value than the left
	// cell, then drop current character of string X and find LCS
	// of substring X[0..m-2], Y[0..n-1]
    else 
    return palin_seq(s1,s2,m-1,n);

}


int main()
{
    int i,j;
    string s1 = "character";
    int n=s1.length();
    string s2 = s1;
    reverse(s2.begin(),s2.end());
   palin(s1,s2,n);
   
}