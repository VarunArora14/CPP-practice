//Longest Palindromic Subsequence
#include<iostream>

using namespace std;

int palin(char a[] ,int start , int end)
{

// for(i=0;i<n;i++)
// {
//     for(j=n-1;j>=0;j--)
//     {

//     }
// }
if(start>end) return 0;

if(start == end)
{
    if(a[start]==a[end])
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

if(start+1==end && a[start]==a[end])
{
    return 2;
}

if(a[start]==a[end])
{
return 2 + palin(a,start+1,end-1);
}

else
{
    return max(palin(a,start+1,end),palin(a,start,end-1));
}


}

int main()
{
char a[]="character";
int n=sizeof(a)/sizeof(a[0]);
cout<< palin(a,0,n);
}