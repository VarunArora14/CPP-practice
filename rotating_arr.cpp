// Rotating arrays
#include<iostream.h>

using namespace std;

int main()
{
    cout<<"enter the size";
    int n,j,i;
    cin>>n;
    cout<<"enter the array ";
    int a[50];
    for( i=0;i<n;i++)
    {
        cin>>a[i]; 
   }
   //for rotating make the first element the last and shift the array towards the old position
   // of start
/*
[2 , 3 , 4 , 5] -> [3 , 4 , 5 , 2] => left shift
[2 , 3 , 4 , 5] -> [5 , 2 , 3 , 4] => right shift
*/

//left shift

cout<<"enter the no. of times left shift of array ";
int x , temp;
cin>>x;
for(i=0;i<x;i++)
{
    temp=a[0];
    for(j=0;j<n;j++)
    {
a[j]=a[j+1];
    }
    temp=a[j];
}
cout<<endl<<"the array is";
for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
}
