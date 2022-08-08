#include <iostream>

using namespace std;

int fac(int);
int calc(int);
int main()
{
    cout<<"enter the times";
    int n;
    cin>>n;
    int count1=1;
    cout<<"["<<endl;
    while(n--)
    {
        cout<<"     "<<"[";
      calc(count1);
      cout<<"]";
        count1++;
cout<<endl;
    }
     cout<<"]"<<endl;
}

int calc(int count1)
{
    int v=0,x;
    if(count1==1)
    {

        cout<<1;
    }
    else{
    while(v<=count1)
    {
        x=count1-v;
       cout<<fac(count1)/(fac(x)*fac(v))<<",";
        v++;

    }
    }

}
int fac(int a)
{
    int res=1,i;
    for(i=2;i<=a;i++)
    {
        res=res*i;
    }
    return res;
}
