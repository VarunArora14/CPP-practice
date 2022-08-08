#include <iostream>

using namespace std;

int main()
{   int n;

    cin>>n;
    int i,j;
    int x=n;
    int m=0;
    for(i=0;i<2*n-1;i++)
    {
cout<<"[";
        for(j=0;j<2*n-1;j++)
        {
            if(i==m||j==m||i==2*(n-1)||j==2*(n-1))
            {
                cout<<x<<" ";
            }
            else if(i==m+1||j==m+1||i==2*n-3||j==2*n-3)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-1<<" ";
                }
            }

            else if(i==m+2||j==m+2||i==2*n-4||j==2*n-4)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-2<<" ";
                }
            }

             else if(i==m+3||j==m+3||i==2*n-5||j==2*n-5)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-3<<" ";
                }
            }

            else if(i==m+4||j==m+4||i==2*n-6||j==2*n-6)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-4<<" ";
                }
            }

            else if(i==m+5||j==m+5||i==2*n-7||j==2*n-7)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-5<<" ";
                }
            }
             else if(i==m+6||j==m+6||i==2*n-8||j==2*n-8)
            {
                if(i==n-1&&j==n-1)
                {
                    cout<<1<<" ";
                }
                else{
                cout<<x-6<<" ";
                }
            }


else{cout<<1<<" ";}
        }

        cout<<"]";
    }
}
