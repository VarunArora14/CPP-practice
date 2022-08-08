#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string s;
    int sum=0,count=0;
    cout<<"enter string";
    getline(cin,s);
    int i,a,j;
    a=s.length();
    for(i=0;i<a-1;i++)
    {   sum=0;
        for(j=i;j<a;j++)
        {
        sum=sum*10;
        sum+=s[j]-'0';
        if(sum%6==0)
        {   cout<<"here sum is "<<sum<<endl;
            count++;
            cout<<"here count is "<<count<<endl;
        }
        }
    }
    cout<<endl<<"the count is "<<count;
    // the above method was brute force
    // DP one try laster
}