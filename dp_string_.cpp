#include<iostream>
//dp problem where input a string and check how many times it can be partitoned
//for eg string 3212 and value less than 6 - then 3,2,1,2 - fully divided in 1 way
// another eg - 11 and less than k=21 then divide - 1,1 and 11 - so 2 ways
#include<string.h>
using namespace std;
int main()
{
  string s;
  cout<<"enter string";
  getline(cin,s);
  int i,j,count,flag=0;
  cout<<"enter the value to be less than";
  int k;
  cin>>k;
  for(i=0;i<s.size();i++)
  {
    for(j=0;j<s.size();j++)
    {
      
    }
  }
}
