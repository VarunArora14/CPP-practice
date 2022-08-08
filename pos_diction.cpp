#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

int main()
{
	string s;
	cout<<"string "<<endl;
	getline(cin,s);
	// same position
	int i,a,count=0;
	a=s.length();
	for(i=0;i<a;i++)
	{	
		if(isupper(s[i]))
		{
			if((s[i]-65)==i)
			{
				cout<<"the alphabet "<<s[i]<<" at "<<i+1<<endl;
				count++;
			}
		}
		else
		{
			if((s[i]-97)==i)
			{
				cout<<"the alphabet "<<s[i]<<" at "<<i+1<<endl;
				count++;
			}
		}
		
	}
	cout<<"total  "<<count<<endl;
}