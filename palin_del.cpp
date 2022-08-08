#include<iostream>
#include<string.h>
using namespace std;
int func(string s , int i ,int j);
int main()
{
string s;
cout<<"enter string";
getline(cin,s);
int i,j,flag=0;
for(i=0,j=s.size()-1;j>i;i++,j--)
{ 
  flag+=min(func(s,i+1,j),func(s,i,j-1));
}
if(flag>1)
cout<<"not possible";
else cout<<"it works";
}

int func(string s , int i ,int j)
{
  if(s[i]!=s[j])
  {
    return 1;
  }
  else return 0;
}