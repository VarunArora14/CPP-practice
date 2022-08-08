#include<iostream>
#include<conio.h>
#include<process.h>

using namespace std;

int func(int a[] , int size);

int size;
int main()
{
system("cls");
int a[20];
cout<<"Enter the size of the array";
cin>>size;
if(size>=20)
{
cout<<"overflow";
exit(0);
}
cout<<"Enter the array";
for(int i=0;i<size;i++)
{
cin>>a[i];
}

cout<<func(a,size);

getch();
}

int func(int a[] , int size)
{
int i=0,x,sum=0,b[20];
for(i=0;i<size;i++)
{
sum=0;
x=a[i];
while(x!=0)
{
sum+=x%10;
x=x/10;
}
b[i]=sum;
}
				//b stores sum
cout<<endl<<endl;
cout<<"The b array is - "<<endl<<endl;
for(i=0;i<size;i++)
{
cout<<b[i]<<endl;
}
cout<<endl<<endl;

int sum1[20];

for(int n=0;n<size;n++)
{
sum1[n]=0;
}

int big=0,flag=0;
for(int j=0;j<size;j++)
{                                   //faulty array
for(int m=j+1;m<size;m++)
{
if(b[j]==b[m])
{
flag=1;
sum1[j]=a[j]+a[m];
cout<<"hi"<<endl;
}
}
}


cout<<endl<<endl<<"The sum1 array is - "<<endl<<endl;
for(i=0;i<size;i++)
{
cout<<sum1[i]<<endl;
}
cout<<endl<<endl;

if(flag==0)
{
return -1;
}

else
{
int big2=sum1[0];
for(int l=0;l<size;l++)
{
if(big2<sum1[l])
{
big2=sum1[l];
}
}
return big2;
}
}

