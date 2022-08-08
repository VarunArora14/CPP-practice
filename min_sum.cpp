#include<iostream>

using namespace std;

int main()
{
    int a[20], i,j;
    cout<<"enter size";
    int s;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }

    int temp;
    for(i=0;i<s;i++)
    {
        for(j=0;j<s-1-i;j++)
        {
            if(a[j]> a[j+1])
            {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;

            }
        }
    }
int s1=0,s2=0,dis=1;
i=0;
    while(i<s)
    {
    if(dis==1)
    { s1=s1*10;
        s1+=a[i];
        dis=dis*-1;
        i++;

    }  
    else
    {
      s2=s2*10;
      s2+=a[i];
      i++;
      dis=dis*-1;
    }
    
   
    }

     cout<<"first num is "<<s1<<" and second number is "<<s2<<endl;
    cout<<endl<<"the sum is "<<s1+s2;

}