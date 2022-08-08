#include<iostream>
#include<string.h>
#include<math.h>
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/
//introduction-to-dynamic-programming-1/practice-problems/algorithm/panda-and-numbers/


auto pandatic(double m)// checks whether in form A pow A
{
  int i;
  bool b=false;
  for(i=1;i<=sqrt(m);i++)
  {
    if(pow(i,i)==m)
    b=true;
  }
  return b;
}
int calc(int n , int r);
using namespace std;
int main()
{
  cout<<"enter no. ";
  int  n,k;
  int r;
  cin>>n;
   r=n;
  if(n==1)
  cout<<"yes";
  
else
{
  while(r>0)
  {
    calc(n,r%10);
    r=r/10;
  }
}
}

int calc(int n , int r)
{ 
  double p;
  p=pow(r,2);
 double m;
 m=n-p;// num- r^2
 cout<<"m = "<<m;
 if((n-p)==1)
 cout<<"yes";
 if(pandatic(m))
 cout<<"yes";
 else cout<<"no";
}


