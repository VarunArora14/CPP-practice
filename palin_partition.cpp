#include<iostream>

using namespace std;

bool ispalindrome(string s ,int start ,int end)
{
    int i,j;
    bool flag =true;
    //aba
    for(i=start,j=end;i<=j;i++,j--)
    // {   cout<<s[i]<<" "<<s[j]<<"\n";
      {  if(s[i]!=s[j])
        {
        flag=false;}

    }
    return flag;
}

int partition(string s , int start ,int len)
{
    int i,j;
    int count=0;
    // stores minimum number cuts needed to partition X[i..j]
    int min = INT16_MAX;
    //If only one character or same character reach AND if a palindrome, return 0 as no need 
    // to partition the string as we need to partition to find palindromes
    if(i==j || ispalindrome(s,start,len))
    {
        return 0;
    }

    for(i=start;i<=len-1;i++)//reason for i to len-1 is that for partition(i+1,len), 
    //this would go wrong and give wrong results 
    {   
        // recur to get minimum cuts required in X[i..k] and X[k+1..j]
        count= 1 + partition(s,start,i)  + partition(s,i+1,len);
                //partition(s,start,i) and not partition(s,0,i)
        
        if(count<min)
        {
            min = count;
        }
    }
    return min;
}

int partition2(string s , int start ,int len)
{
    int i,j;
    int dp[len+1][len+1];
    for(i=start;i<len;i++)
    {
        for(j=len;j>=i;j--)
        {
            // if(i==j || ispalindrome(s,i,j)) dp[i][j]=0;

        }
    }
}
int main()
{
    string s= "ababbaababa";
    // string s="abam";
    int len = s.length();
    cout<<len<<"\n";
    cout<<partition(s,0,len-1);
    // if(ispalindrome(s,0,len-1))
    // {
    //     cout<<"hello";
    // }

}

