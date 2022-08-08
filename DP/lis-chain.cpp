#include<iostream>
// GIven n pairs of numbers, find the longest sequences of numbers such that for (a,b) , (c,d)
// {(a,b),(c,d)} is a sequence when b<c for all terms
int main()
{
    int arr[5][2] = { {5,24},{39,60},{15,28},{27,40},{50,90}};
    int len  = 4;
    int i,j;
    int count=1,sum=1;
    // int l[len][len];
    for(i=0;i<=len;i++){
        if(sum<count)
        {
            sum=count;
        }
        count=1;
        for(j=0;j<=i;j++)
        {
            if(arr[j][1]<=arr[j+1][0])
            {
                count++;
            }
        }
    }

    if(sum<count)
        {
            sum=count;
        }

        std::cout<<"longest is "<<sum;
}