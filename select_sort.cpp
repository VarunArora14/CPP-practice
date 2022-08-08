/*
This is one of the easiest sorting technique.
Consider a set of cards numbered - 9,6,3,4

Assume that the left hand has the unsorted cards. Now sorting ij ascending order we have the 
minimum card chosen from list and then put in the right hand. Then from the remaining choose 
the minimum card and put in right hand and so on till no card left onthe left hand.

This is not an inplace sorting algorithm as in place algorithm takes constant amount of extra 
memory and here we need extra memory for allocation for new array.
In order to remove that,  we will implement it in the in place way.

If array [2,7,4,1,5,3] we find the smallest term(1) and then swap with the first position
as it will occupy it. Now we find the smalles element from 1 to n and then swap it with second
position. It will look like - [1,2,4,7,5,3] and continue till end of array 
*/

#include<iostream>

int main()
{
    std::cout<<"enter size";
    int n,a[20],i,j;
    std::cin>>n;
    std::cout<<"enter the array";
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    int c=0;
    int imin;
    for(i=0;i<n-1;i++) //we need n-2 times loop as j from i+1 and first element compared to itself
    {   std::cout<<c++<<"\n";
        imin=i;
        for(j=i+1;j<n;j++)
        {   
            if(a[imin]>a[j])
            imin=j; //index of min element
      //  break; break statement here moved it out from the loop and only one execution of i
        }
        std::swap(a[imin],a[i]); //swap smallest and the ith element
        
        /* std::cout<<"\n Now the new array is \n";
    for(i=0;i<n;i++)
    {
        std::cout<<a[i]<<" ";
    }
    The above when put shows wrong output when using i as i=0 everytime
    USE DIFFERENT VARIABLES FOR DIFFERENT PURPOSES
    */
    
    }
    std::cout<<"\n Now the new array is \n";
    for(i=0;i<n;i++)
    {
        std::cout<<a[i]<<" ";
    }
   
}
//we have to move the smallest element to the first position so run the for loop for j till 
//smallest found for a[imin]>a[j] and then swap them where imin was initially i