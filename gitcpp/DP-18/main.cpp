#include <iostream>
#include<process.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int n;
 cout<<"Enter the size";
 cin>>n;
 cout<<"ENter the array ";
 int i,j,a[20];
 for(i=0;i<n;i++)
 {
     cin>>a[i];
 }

//sorting array - quicksort is better

int temp;
for( i=0;i<n-1;i++)
{

    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}

cout<<"Array"<<endl;
for(i=0;i<n;i++)
{
    cout<<a[i]<<endl;
}


i=0;
j=n-1;
int left,right;
left=a[i];
right=a[j];

cout<<"start - "<<endl<<"left - "<<left<<"right - "<<right;
while(i<j-1)
{

   if(left<right)
   {
       i++;
       left+=a[i];
   }
   else{
    j--;
    right+=a[j];
   }
}

if(left==right)
{

    cout<<"True";
}
else{
        cout<<"left - "<<left<<"right - "<<right<<endl;
    cout<<"false";
}
 }
