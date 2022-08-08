// largest 3 elements wit time - O(n) and space O(1)

#include<iostream>

using namespace std;

int main(){
    int s,a[10];
    cin>>s;
    int i;    

    for( i=0;i<s;i++)
    {
        cin>>a[i];
    }
    int big1,big2,big3,temp;
    big1=big2=big3=0;

    for(i=0;i<s;i++)
    {
        if(a[i]>big1)
        {
            if(big2<big1)
            {   temp=big2;
                big2=big1;
                big3=temp;
            }
            big1=a[i];
        }
        else if(a[i]>big2)
        {
            if(big3<big2)
            {
                big3=big2;
            }
            big2=a[i];
        }
        else
        {
            if(big3<a[i])
            {
                big3=a[i];
            }
        }

        cout<<"big1-"<<big1<<"  big2 - "<<big2<<"  big3 - "<<big3<<endl;
    }
    cout<<"the largest ones are "<<big1<<" "<<big2<<" and "<<big3;
}
