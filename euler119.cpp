#include<iostream>
#include<math.h>

using namespace std;

int sum1(int i)
{
int r;

r=i;
int s=0;
while(r>0)
{
    s=s+(r%10);
    r=r/10;
}
if(i==614656)
{
    cout<<"the sum is "<<s<<endl;
}
return s;
}

int main()
{

    int sum=0,j;
    long long i,num;
    int digit_sum=0;
for(i=2;i<10000000000000;i++)
{
digit_sum=sum1(i);

for(j=2;j<5;j++)
{
    num=pow(digit_sum,j);
   
    }
    if(i==num)
    {
        cout<<"num is "<<i<<" and digit_sum is "<<digit_sum<<" with power "<<j<<endl;
        
    }
}
}

    
