#include<iostream>
#include<process.h>

using namespace std;

int main()
{
    cout<<"enter size of array";
    int s;
    cin>>s;
    if(s%2!=0)
    {
        cout<<"only even powers required";
        exit(0);
    }
    cout<<"enter array "<<endl;
    int i,q,a[20];
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }

cout<<"enter the queries";
cin>>q;
int qu[10] , index[10];

for(i=0;i<q;i++)
{
    cin>>index[i]>>qu[i];
}

for(i=0;i<q;i++)
{
    a[index[i]]=q[i];
    
}
}