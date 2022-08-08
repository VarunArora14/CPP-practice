#include<iostream>
#include<stdlib.h>

using namespace std;

int narcissistic( int value )
{
  //Code away
  int count=0,r;
  r=value;
  while(r>0)
  {
  r=r/10;
  count++;
  }
  cout<<"count "<<count<<endl;
  // digits=count
  r=value;
  int d,i,l=1;
  int sum=0;
  while(r>0)
  {
      l=1;
  d=r%10;
  for(i=0;i<count;i++)
  {
l=l*d;
  }
d=l;
  cout<<"d is "<<d<<endl;
  cout<<"sum before "<<sum<<endl;
  sum=sum+d;       // ^ this is xor operator not exponential
  cout<<"sum is after "<<sum<<endl;
  r=r/10;
  }
 
  
  
if(sum==value)
{
return value;
}

else
{
return value;
}
  
}

int main()
{
     
    int x;
    cin>>x;
    cout<<narcissistic(x);
}