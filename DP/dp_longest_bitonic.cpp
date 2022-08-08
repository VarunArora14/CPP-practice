#include<iostream>

using namespace std;

void func(int [] , int start , int end);
int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 
			13, 3, 11, 7, 15};
    int len = sizeof(arr)/sizeof(arr[0]);
    func(arr,0,len);
}

void func(int a[] ,int start ,int end)
{
    int lis[end],lds[end];
    int i,j;
    for(i=0;i<end;i++)
    {
        lis[i]=1;
        lds[i]=1;
    }
    int flag=0;
    // lis[0] =1;
    for(i=1;i<end;i++)
    {
        // lis[i]=1;
        for(j=0;j<end;j++)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
            {   
                // if(flag==1) break;
                lis[i]=lis[j]+1;
            }
            else if(a[i]>a[j] && i<j)//not lis[i]<lis[j+1]
            {   
                if(lds[i]<lds[j]+1)
                {
                     lds[i] = lds[j] + 1;
                }
               
                // flag=1;
            }
            
        }
    }

    int big=0;
    for(i=0;i<end;i++)
    {
        cout<<lis[i]+lds[i]<<" ";
    }

    // cout<<"lis of the subsequence is "<<big;
}