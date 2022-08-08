#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
int i,j;
int main()
{
    int a[40];
    cout<<"size";
    int s;
    cin>>s;
    for( i=0;i<s;i++)
    {
       cin>>a[i];
    }
    int m[40];
    for(i=0;i<s;i++)
    {
        m[i]=a[i]%10;   //storing values
    }
    // sort m[i] with a[i]
    int temp;
    for(i=0;i<s;i++)
    {
        for(j=i;j<s;j++)
        {
            if(m[i]<m[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }


    for(i=0;i<s;i++)
    {
       cout<<a[i];
    }

    cout<<endl<<endl;

}
