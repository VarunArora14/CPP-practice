#include<iostream>
#include<string.h>
#include<process.h>
#include<algorithm>		// contains sort() function and stringstream fns

using namespace std;

int main()
{
	string s1,s2;
	cout<<"string 1 "<<endl;
	getline(cin,s1);
	cout<<"string 2 "<<endl;
	getline(cin,s2);
	int i,j;
	string temp;
	if(s1.length()!=s2.length())
	{cout<<"unequal , so not anagram ";
	exit(0);}
	sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
  
	int flag=1;
	for(i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
		{
			flag=0;
			cout<<"not anagram";
			break;
		}
	}
	if(flag==1)
	{
		cout<<"anagram";
	}
}