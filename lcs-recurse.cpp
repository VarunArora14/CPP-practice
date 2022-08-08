#include<iostream>

using namespace std;

int c=0;
int lcs(string s1, string s2, int i , int j)
{   
    c++;
    if (i==0 || j==0)
    return 0;

    else if (s1[i-1]==s2[j-1])
    return 1 + lcs(s1,s2,i-1,j-1);

    else 
    return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
}
int main()
{
    string s1,s2;
    s2="aggtab";
    int n = s2.length();
    s1="gxtxayb";
    int m=s1.length();
    cout<<"lcs is "<<lcs(s1,s2,n,m);
    cout<<"\n"<<c;
}
