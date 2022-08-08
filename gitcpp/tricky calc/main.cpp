#include <iostream.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
void main()
{
system("cls");

    int a[10],digit[10][10],m[10],n,digit2[10][10],t;
    int i=0,j=0;
    for(i=0;i<10;i++)
    {

        for(j=0;j<10;j++)
        {
            digit[i][j]=digit2[i][j]=0;
        }
    }

    int count=0,cou;

    cout<<"Enter the no. of test case";
    cin>>t;
    for(i=0;i<t;i++)
    {
      cin>>a[i]>>m[i];
    }
    int size1,b=0;
    for(i=0;i<t;i++)
    {n=cou=a[i];
    while(cou!=0)
    {
    cou=cou/10;
    count++;
    }
    size1=count-1;
    cout<<"size"<<size1<<endl;
 while(n!=0)
    {

	digit[i][size1-b]=n%10;
	n=n/10;
	b++;

    }
    }
	      count=0;
    int size2,c=0,k;
     for(i=0;i<t;i++)
    {k=cou=m[i];
    while(cou!=0)
    {
    cou=cou/10;
    count++;
    }
    size2=count-1;
    cout<<endl<<"size2"<<size2<<endl;
 while(k!=0)
    {

	digit2[i][size2-c]=k%10;
	k=k/10;
	c++;

    }
    }



    cout<<endl<<"The digit array is "<<endl;
    for(i=0;i<t;i++)
    {

        for(j=0;digit[i][j]!=0;j++)
        {
            cout<<digit[i][j];
        }
        cout<<endl;
    }

     cout<<endl<<"The digit2 array is "<<endl;
    for(i=0;i<t;i++)
    {

        for(j=0;digit2[i][j]!=0;j++)
        {
            cout<<digit2[i][j];
        }
        cout<<endl;
    }

int sum[10];
for(i=0;i<10;i++)
{
    sum[i]=0;
}
    int l=0,check=0;

    for(i=0;i<t;i++)
    {           l=0;
	for(j=0;(digit[i][j]||digit2[i][j])!=0;j++)

	{          check=l;
	if(l+digit[i][j]+digit2[i][j]<10)
	{
	    sum[i]+=l+digit[i][j]+digit2[i][j];
	}
	else{

	sum[i]+=((digit[i][j]+digit2[i][j]+l)/10);
	l=(digit[i][j]+digit2[i][j]+l)%10;
	cout<<endl<<"L - "<<l<<endl;

	}
	cout<<endl<<"hi"<<endl;
	sum[i]=sum[i]*10;
	}
	if(check==l)
	{
	sum[i]/=10;
	}
	else
	{
	sum[i]+=l;
	}

    }
cout<<endl<<endl;
    for(i=0;i<t;i++)
    {
	cout<<sum[i]<<endl;
    }
getch();
}


/*
cout<<"Enter the num";
    int n;
    cin>>n;
    int x,i;
    x=n;
    cout<<endl<<x<<endl;
    int a=0,digit[10];
    while(x!=0)
    {

	digit[a]=x%10;
	x=x/10;
	a++;

    }
    cout<<endl<<"The digits are "<<endl;
    for(i=0;i<a;i++)
    {

        cout<<digit[i]<<endl;
    }*/
