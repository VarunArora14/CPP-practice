#include <iostream>
// FUNCTION TEMPLATES
using namespace std;

template<typename T>
 bubble(T a[] , int n)
 {
     T temp;
     for(int i=0;i<n;i++)
     {

         for(int j=0;j<n-i-1;j++)
         {
            if(a[j]>a[j+1])
            {

                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

         }
     }
 }
 int main()
 {

     cout<<"size";
     int s;
     cin>>s;
     int a[50];
     cout<<endl<<"array"<<endl;
     for(int i=0;i<s;i++)
     {

         cin>>a[i];
     }
     bubble(a,s);
      for(int i=0;i<s;i++)
     {

         cout<<a[i]<<" ";
     }
     return 0;
     }
