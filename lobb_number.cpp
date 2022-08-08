#include<iostream>

using namespace std;

int comb(int , int);
void lobb(int , int);
void input()
{
  cout<<"enter 2 numbers n and m ";
  int n,m;
  cin>>n>>m;
  if(n>0 && m>0 && n>=m)
  {
      lobb(n,m);
  }  

  else
  {
      input();
  }
  
}

void lobb(int n , int m)
{
    int lobb = (2*m+1)*comb(2*n,m+n)/(m+n+1);
    cout<<"lobb number is "<<lobb;
}

int comb(int a , int b)
{
    long v1=1,v2=1;
    while(a>0)
    {
        v1=v1*a;
        a--;
    }

    while (b>0)
    {
        v2=v2*b;
        b--;
    }
    return v1/v2;
}

int main()
{
    input();
}