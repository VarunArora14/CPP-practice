// //Longest increasing subsequence



// #include<iostream>

// // using namespace std;

// int main()
// {
//     int a[20],len;
//     std::cout<<"enter len";
//     std::cin>>len;
//     std::cout<<"enter array ";
//     int i,j;
//     for(i=0;i<len;i++)
//     {
//         std::cin>>a[i];
//     }
//     int count=1,sum=1,val;
//     long prod=1,finalprod=1;
// //least value of subsequence is 1
//     for(i=0;i<len;i++)
//     {   if(sum<count){  sum=count; }
//         if(finalprod<prod){ finalprod = prod;}
//         //prod value changes for each i value so we need to 
//         count=1;
//         prod=1;
//         //start j loop from i+1 and not 0
//         //make val=a[i] and is val<a[j] , val=a[j] for continous long subsequence
//         val=a[i];
//         prod=a[i];
//         for(j=i+1;j<len;j++)
//         {   
//             //making val= a[j] makes no sense inside loop as case - 3 10 7 40 80
//         //what happened earlier was that all comparisons made with 3 made all of them larger than
//             //3 and so longest subsequence became 3 10 7 40 80 but in reality it is 3 10 40 80
//             //so for next comparison, we must compare with the new larger value
//             if(val<a[j])
//             {   val=a[j];
//             prod=prod*a[j];
//                 count++;
//                 // std::cout<<"a[i] is "<<a[i]<<" a[j] is "<<a[j]<<"count is "<<count<<"\n";
//             }
//         }
//     }
//     std::cout<<"The longest subsequence len is "<<sum;
//     std::cout<<"\n The product of sequence is "<<finalprod;
// }

// The above code finds the longest increasing subsequence by just finding the large number 
//next to it and then adding the number to the count
// Not working for input [2,24,4,7]

#include<iostream>

using namespace std;

int func(int [] ,int );
int main()
{
    int a[] = {3, 10, 2, 11};
    int len = sizeof(a)/sizeof(a[0]);
    func(a,len);
}

int func(int a[] ,int len)
{
    int lis[len];
    lis[0]=1;
    int i,j;
    for(i=1;i<len;i++)
    {
        lis[i]=1;

    for(j=0;j<i;j++)
    {
        if(a[i]>a[j] && lis[i]<lis[j]+1)
        {
            lis[i]=lis[j]+1;
        }
    }
    }

    for(i=0;i<len;i++)
    {
        cout<<lis[i]<<" ";
    }
}