#include<iostream>
/*
Given an array of lengths and corresponding values for which the cut rod can be sold, find a way
to maximize the value earned by selling the pieces cut

length    rate

1           1
2           5
3           8
4           9
5           10
6           17
7           17
8           20
9           24
10          30
 
*/
// int max_val(int );
//  int val[]={1,5,8,9,10,17,17,20,24,30};

// int main()
// {   
//     int l;
//     std::cout<<"enter the len";
//     std::cin>>l;
//     std::cout<<"The max val is ";
//     max_val(l);
    
// }
/*
One method is to make all the combinations and see the max value one but it will take many 
steps as recusive
*/
// int max_val(int l)
// {
// //    input l
//     //  int val[]={1,5,8,9,10,17,17,20,24,30};
//     if(l==0)
//     return 0;
//     auto q= INT16_MIN;
//     for(auto i=0;i<l;i++)
//     {
//     q=std::max(q,val[i]+max_val(l-i-1));
//     std::cout<<"  "<<q;
//     }
//     std::cout<<" "<<q;
  
// }

int max_val(int[] , int);
int main() {
    int val[]={1,5,8,9,10,17,17,20,24,30};
    int len;
    std::cin>>len;
    std::cout<<"\n"<<max_val(val,len);
}

int max_val(int val[], int len)
{   if(len==0)
    return 0;
    int q=-100;
    for(int i=0;i<len;i++)
    {
        q=std::max(q,val[i]+max_val(val,len-i-1));
    }
    return q;
}