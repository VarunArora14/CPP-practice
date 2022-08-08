#include<iostream>
#include<string.h>
#include<process.h>
#include<algorithm>	// reverse()

using namespace std;

int main()
{
	string s1,s2,str;
	cout<<"string 1"<<endl;
	getline(cin,s1);
	cout<<"string 2 "<<endl;
	getline(cin,s2);
	int i,j,pos=0,a,b,n,carry=0;
a=s1.length();
b=s2.length();
if(a<b) 
{
	cout<<"2nd must be smaller";
	exit(0);
}

reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
for(i=0;i<b;i++)
{
	if((s1[i]-'0')+(s2[i]-'0')+carry==2)
	{
		carry=1;
		str.push_back('0');

	}
	else if((s1[i]-'0')+(s2[i]-'0')+carry==3)
	{
		str.push_back('1');
		carry=1;
	}
	else
	{
		str.push_back(carry+(s1[i]-'0')+(s2[i]-'0')+'0');
		carry=0;	//*
	}
}
	
	for(i=b;i<a;i++)
	{	
		if(s1[i]-'0'+carry == 2)
		{
			carry=1;
			str.push_back('0');
		}
		else
		{
		
		str.push_back(s1[i]+carry);
		}
		carry=0;

	}
 reverse(str.begin(), str.end());
 cout<<endl<<"string with addition is "<<str;
	


}