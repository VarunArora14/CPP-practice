#include<iostream>


using namespace std;
int main()
{
int t,n,q,l[INT_FAST16_MAX],r[INT_FAST16_MAX];
long int b[INT_FAST16_MAX],a[INT_FAST16_MAX];
cin>>t;

while(t--)
{
cout<<"size";
cin>>n;
int i,j;
for(i=0;i<n;i++)
{
    cin>>a[i];

}
cout<<"queries";
cin>>q;
cout<<"lower bound";
for(i=0;i<q;i++)
{
    cin>>l[i];
}
int big;
big=0;
cout<<"upper bound";
for(i=0;i<q;i++)
{
    cin>>r[i];
}
for(i=0;i<q;i++)
{
    if(big<r[i])
    big=r[i];

}
cout<<"big is "<<big<<endl;

for(i=0;i<big;i++)
{
    b[i]=a[i%n];
}
long int m=1000000007;
int sum[q];
for(i=0;i<q;i++)
{sum[i]=0;}
for(i=0;i<q;i++)
{
    for(j=l[i]-1;j<r[i];j++)
    {
        sum[i]+=b[j];
        sum[i]=sum[i]%m;
    }
    cout<<sum[i]<<" ";
}


}


}
