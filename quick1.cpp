#include<iostream>

 /*
    Now in the partition array, what we do is, we start from first element of array and marks 
    its index-p and then keep on moving in the array till we reach an element which is less than
    the p and then swap both of them and increment p by 1 , i.e. move towards the next element 
    as p and if another no. found less than p then swap again.
    The loop ran from start to end of array where the last element was the pivot and then we see
    that the smaller elements are on left side and bigger on right side. Inorder to complete the
    swapping, we swap the pth value and the last element where then the left side of array till
    pivot has smaller elements and right side bigger.
    Now we return p and then in the quick function sorting is done again from start to p and
    p+1 to end.
                pivot
                  |
                  v 
    7 2 1 6 8 5 3 4
    p              
    i->loop iterator

    7 2 1 6 8 5 3 4
    p i

    Now as 2 < 4, swap 2 and 7(index p) and increment p by 1

    2 7 1 6 8 5 3 4
       p  i
    
    Again as 1 < 4, swap 1 and 4 and increment p by 1

    2 1 7 6 8 5 3 4
        p i

    6 > 4 so nothing

    2 1 7 6 8 5 3 4
        p   i

    2 1 7 6 8 5 3 4
        p     i
    
    2 1 7 6 8 5 3 4
        p       i

    Now as 3<4 , swap 3 and 7(index of p  and increment by 1)

    2 1 3 6 8 5 7 4
          p       i
    
    As now i has ended till array end, we come out of loop and swap pivot and index p element

    2 1 3 4 8 5 7 6

    Note: Here p is not incremented as swapped outside loop. Now return p as then in the 
    quick function, sorting to be done for start to p and p+1 to end.



    */  

void quick(int[] , int ,int );
int part(int[] ,int , int);
int main()
{
    std::cout<<"enter size ";
    int n;
    std::cin>>n;
    std::cout<<"enter the array";
    int i,a[20];
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }

    //Perform quicksort on this array
    quick(a,0,n);
}

void quick(int a[] , int l , int r)
{
    if(l<r)// or r>=l , reason why greater than equal to is beause greater than will take care
    //of the invalid segements and equal to obviously for the base conditon i.e., only 1 element
    {
        int p=part(a,l,r);
        quick(a,l,p);
        quick(a,p+1,r);
    }
}

int part(int a[] ,int l ,int r)
{
    int i,j, p,pivot;
    p=l; //the starting index to be swapped when element smaller than pivot found
    pivot=a[r-1]; //pivot here is the last lement
    for(i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
            std::swap(a[i],a[p]);
            p++;
        }
    }
   
}