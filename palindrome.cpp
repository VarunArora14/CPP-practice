#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	string s;
	cout<<"string 1"<<endl;
	getline(cin,s);
	int i,j,a,flag=1;
	a=s.length();
	for(i=0,j=a-1;i<=a/2,j>=a/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
	cout<<"not palindrome";
	else
	{
		cout<<"yes,its a palidrome";
	}
	

}