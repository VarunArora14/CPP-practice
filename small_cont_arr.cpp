#include<iostream>

using namespace std;

int main()
{
    int a[20],s,max1,max2;
    cout<<"size";
    cin>>s;
    cout<<"enter the array"<<endl;
    int i;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
    max1=max2=0;
    for(i=0;i<s;i++)
    {
        max2+=a[i];
        if(max2<0)
        {
            max2=0;
        }
        if(max2>max1)
        max1=max2;
    }

    cout<<endl<<"The maximum is "<<max1;
}