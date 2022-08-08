#include <iostream>
#include<conio.h>

using namespace std;

int main()
{
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
    }
    getch();
}


