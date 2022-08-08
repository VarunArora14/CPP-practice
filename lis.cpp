#include<iostream>

using namespace std;

void lis()
{
    int arr[] = {2,4,9,3,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int lis[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)//j<i
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;   
            }
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<lis[i]<<" ";
    }

}

int main()
{
lis();
}