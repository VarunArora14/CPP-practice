#include<iostream>
#include<algorithm>
using namespace std;
int func(int a[], int s);
int main()
{
    int a[20],s;
    cout<<"size";
    cin>>s;
    cout<<"arr"<<endl;
    for (auto i = 0; i < s; i++)
    {
      cin>>a[i];
    }
    
    cout<<func(a,s);
}
int func(int a[] , int s)
{
sort(a,a+s);
int k;
cout<<"enter k";
cin>>k;
return a[k-1];

}

