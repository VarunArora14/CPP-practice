// //Given an array find the subarray with maximum sum

// #include<iostream>

// int main()
// {
//     int a[]=  {1, -2, 1, 1, -2, 1};
//     int i,j;
//     int count=1,finalcount=1;
//     int maxval=0,minval=0;
//     for(i=1;i<6;i++)
//     {   
//         minval=a[i];
//         count=1;
        
//         if(minval>maxval)
//         {
//             maxval=minval;
//             finalcount=count;
//         }
//         // else
//         // {
//         //     count=finalcount;
//         // }
        
        
//         for(j=i+1;j<6;j++)
//         {
//             if(minval + a[j]<=0)
//             {
//                 // minval=maxval;
//                 break;  
//             }
//             else
//             {
//                 minval+=a[j];
//                 count++;
//             }
           

//             if(minval>maxval)
//         {
//             maxval=minval;
//             finalcount=count;
//         }
//         // else
//         // {
//         //     count=finalcount;
//         // }
        
            
//         }
//     }

//     if(maxval>minval)
//     {
//         count=finalcount;
//     }
     
//     std::cout<<"the maxval is "<<maxval<<" and length is "<<finalcount;
// }

// The  above is 2D approach but we can do better and so we having one loop using sliding
//window maintaining the max_so_far and max_end_here

#include<iostream>

int main()
{
    int a[]=  {1, -2, 1, 1, -2, 1};
    int i,j;
    int max_sofar=0,max_end=0,start=0,end=0,s=0;

    for(int i=0;i<6;i++)
    {
        max_end=max_end+a[i];
        if(max_end<0)
        {
            max_end=0;
            s=i+1;
        }

        if(max_sofar<max_end)
        {   
            max_sofar=max_end;
            start=s;
            end=i;
        }

    }
    std::cout<<"the max subarray is "<<max_sofar<<" and length of the subarray is "<<(end-start)+1;

}