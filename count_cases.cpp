#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

int main()
{
string s;
cout<<"string "<<endl;
getline(cin,s);
char ch;
int a,c1,c2,c3,c4;
c1=c2=c3=c4=0;
a=s.length();
int i;
for(i=0;i<a;i++)
{
	if(isdigit(s[i]))
	c4++;
	else if(islower(s[i]))
	c2++;
	else if(isupper(s[i]))
	c1++;
	else
	{
		c3++;
	}
	
}
cout<<endl<<"Upper digit "<<c1<<endl;
cout<<"Lower digit "<<c2<<endl;
cout<<"Special Character "<<c3<<endl;
cout<<"Numbers "<<c4;

}