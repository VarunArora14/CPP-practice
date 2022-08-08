#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{

int t;
 int r,l,k;
 cout<<"cases";
cin>>t;
while(t--)
{
  int s,a[20],b[20];
  cout<<"size";
  cin>>s;
  cout<<"a"<<endl;
  for(int i=0;i<s;i++)
  {

      cin>>a[i];
  }
  cout<<"b"<<endl;
   for(int i=0;i<s;i++)
  {

      cin>>b[i];
  }
  int count1=0,pos;
  for(int i=0;i<s;i++)
  {
      if(a[i]!=b[i])
      {
          pos=i+1;
          count1+=1;
      }

      r=pos;
      l=r-count1;

      // for array use r-1

  }

  int k=abs(a[l]-b[l]);

  int flag=0;
  for(int j=l;j<r;j++)
  {
      if(k!=abs(a[j]-b[j]))
      {
          cout<<"NO";
          flag=1;
          exit(0);

      }
  }if(flag==0)cout<<"Yes";
}
}

