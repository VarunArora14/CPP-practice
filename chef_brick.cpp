#include<iostream>

using namespace std;


int main()
{
int t,i,j,a[10][10],s[10];
cin>>t ;        // test cases
for(i=0;i<t;i++)
{
cin>>s[i];
for(j=0;j<3;j++)
{
    cin>>a[i][j];
}
}
int sum[10],count[10];

for(i=0;i<t;i++)
{sum[i]=count[i]=0;
}

for(i=0;i<t;i++)
{
    for(j=0;j<3;j++)
    {
sum[i]+=a[i][j];
    }
}
for(i=0;i<t;i++)
{
    while(sum[i]>=0)
    {
        sum[i]-=s[i];
        count[i]++;
    }
}
for(i=0;i<t;i++)
{
    cout<<count[i]<<endl;
}
}