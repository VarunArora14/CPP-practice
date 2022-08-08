#include<iostream>
#include<vector>
void quick(int a[] ,int l , int r)
{
    if(l<r)
    {   int p;
        p=part(a,l,r);
        quick(a,l,p);
        quick(a,p+1,r);
    }
}

int part(int a[] ,int l , int r)
{

}
int main()
{
    int a[20],n;
    std::cout<<"enter the size";
    std::cin>>n;
    std::cout<<"enter array \n";
    int i;
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    quick(a,0,n-1);
}

