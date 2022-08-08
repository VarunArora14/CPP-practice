#include<iostream>
//Another efficient way was to make them in 2 groups which would then return k/2 arrays
// and then k/4 so on.. till single sorted array . The most efficient is using heaps-min heap
#include<algorithm>
using namespace std;
void func(int a[][5] , int);
int main()
{ int a[5][5];
  cout<<"enter size";
  int k;
  cin>>k;
  cout<<"enter 2d array";
  int i,j;
  for(i=0;i<k;i++)
  {
    for(j=0;j<k;j++)
    {
      cin>>a[i][j];
    }
  }
  func(a,k);
    
}

void func(int a[][5] , int s)
{
  int i,j,k=0;
  int b[30];
  for(i=0;i<s;i++)
  {
    for(j=0;j<s;j++)
    {
      b[k++]=a[i][j];

 
    }
  }
 

    //!!!!! should be b[i] and not b[k] !!!!
  
  
  sort(b,b+k);

  for(i=0;i<k;i++)
  {
    cout<<" "<<b[i];
  }


}
