#include<iostream>

using namespace std;

int main()
{
    int x;
    cout<<"enter num";
    cin>>x;
    int m=x&(x-1);
    int a=x^m;
    cout<<endl<<"removed last bit gives "<<m;
    cout<<endl<<"rightmost bit is binary "<<a;
    int c=0;
    cout<<endl<<"no. of bits in "<<x;
    int A=x,N=x;
    while(x)
    {
        x=x>>1;
        c++;
    }
    cout<<" are "<<c;

cout<<endl<<"largest power of 2 less than n ";
//changing all right side bits to 1.
        N = N| (N>>1);
        N = N| (N>>2);
        N = N| (N>>4);
        N = N| (N>>8);
        cout<<"now "<<N<<endl;
        N=(N+1)>>1;
        cout<<"then "<<N;



    //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by
      cout<<endl<<"Second method for most significnant bit"<<endl;
      int c1=-1;
      while(A)
      {
          A=A>>1;
          c1++;
      }
      A=1<<c1;
      cout<<A;
}