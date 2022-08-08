#include<iostream>

using namespace std;

int main()
{
    int a[20];
    cout<<"enter size";
    int s;
    cin>>s;
    int i,j; 
    for(i=0;i<s;i++)
{
    cin>>a[i];
}
/* sort elements such as bigger numbers with factors other than 1 are sorted
     and then the prime numbers are put
     */
    int b[10] , c[10] , m=0,n=0,flag=0;
    for(i=0;i<s;i++)
    {
        flag=0;
        for(j=2;j<=(a[i]/2);j++) // comparison if any factors
        {
            if(a[i]%j==0)
            {
                // has factors other than 1
               b[m++]=a[i];
               flag=1;
               break;
            }
        }
        if(flag==0)
        {
            c[n++]=a[i];
        }
    }
int temp;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m-1-i;j++)
        {
if(b[j]< b[j+1])
{
    temp=b[j];
    b[j]=b[j+1];
    b[j+1]=temp;

}
        }
    }
cout<<endl<<"the array b is "<<endl;
    for(i=0;i<m;i++)
    {
        cout<<b[i]<<endl;
    }

    cout<<endl<<"the array c is "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<c[i]<<endl;
    }

    for(i=0;i<m;i++)
    {
        a[i]=b[i];
    }
    j=0;
    while(j<n)
    {
        a[i+j]=c[j];
        j++;
    }

cout<<endl<<endl<<"The final array is "<<endl;
    for(i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}