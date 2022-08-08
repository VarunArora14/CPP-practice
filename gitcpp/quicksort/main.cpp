//QUICKSORT

#include <iostream>

using namespace std;
int part(int a[] , int , int);
void quick(int a[] , int , int);
int main()
{   int s,a[20];
    cout<<"size";
    cin>>s;
    for(int i=0;i<s;i++)
    {

        cin>>a[i];
    }int l,h;
    l=0;
    h=s-1;
        quick(a,l,h);

        for(int m=0;m<s;m++)
        {
            cout<<a[m]<<" ";
        }
}

void quick(int a[] , int l , int h)
{
    int pi;
    if(l<h)
    {
        pi=part(a,l,h);
        quick(a,l,pi-1);
        quick(a,pi+1,h);
    }
}

int part(int a[] , int l,  int h)
{
    int i,j,temp;
    i=l-1;  //-1
    int pivot;
    pivot=a[h];
    for(j=l;j<=h-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[h];
    a[h]=temp;

    return i+1;
}
