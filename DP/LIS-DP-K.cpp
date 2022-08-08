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
//     std::cout<<"enter the k value";
//     int k;
//     std::cin>>k;
//     int count=1,sum=1,val;
//     long prod=1,finalprod=1;
// //prod is like count and finalprod like sum where count changes for each loop and sum max of all
//     int subscount=0;
//     //subsequences count
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
//         if(val<k)
//         {
//             subscount++;
//         }

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
//                 subscount++;
//                 // std::cout<<"a[i] is "<<a[i]<<" a[j] is "<<a[j]<<"count is "<<count<<"\n";
//             }
//         }
//     }
//     std::cout<<"The longest subsequence len is "<<sum;
//     std::cout<<"\n The product of sequence is "<<finalprod;
// }

#include <iostream>

int main()
{
    std::cout << "enter len";
    int len;
    std::cin >> len;
    std::cout << "enter array ";
    int i, j, a[20];
    for (i = 0; i < len; i++)
    {
        std::cin >> a[i];
    }
    int k;
    std::cout << "enter value of k ";
    std::cin >> k;

    int count = 0, newval=1;

    for (i = 0; i < len; i++)
    {
        newval = 1;
        if (a[i] <= k)
        {   
            count++;
            std::cout<<a[i]<<"\n";
        }
        newval = a[i];
    
        for (j = i + 1; j < len; j++)
        {
            
            //newval to be initialised inside the i loop and not j loop
            newval = newval * a[j];
            if (newval <= k)
            {
                count++;
                std::cout<<newval<<"\n";
            }
            // else
            // {
            //     // break;
            //     newval=newval/a[j];
            //     // j++;
            // }
            
        }
    }
    std::cout<<"The total number is "<<count;
}
//problem is that for subsequence of 1234
//{1},{1,2} is showing but not {1,3}