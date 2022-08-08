#include<iostream>

int main()
{
    int n,a[20];
    std::cout<<"enter size";
    std::cin>>n;
    std::cout<<"enter arr \n";
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
/*
Previously in iselection sort assuming having a deck of cards, we chose the smallest card and 
then swapped with the first element and so on moved to the next card, found the next smallest 
element and then swap it but in insertion sort, we focus more on how we insert the the new card
in our right hand as we assumed our left hand had unsorted deck and right hand with sorted
cards.
For doing this without using an additional array we have have to consider our array as 2 parts
of which 1 part is 
sorted one  and another part is the unsorted one. Now, to sort them we use 2 loops.
1 is from i=1 t n-1 , inside it there are 2 var j=i-1 and tmp=a[i] and then the inner loop
while(j>=0 && tmp<a[j])
*/
int tmp;
for(i=1;i<n;i++)
{
    j=i-1;  //previous elment stored
    tmp=a[i];   //storing the ith val
    while(tmp<a[j] && j>=0) // until any of the array back to 0 or till tmp>a[j] comes true
    //as we moving backward so if previous elements greater than temp we move the while loop
    //in which a[j]=a[j-1] i.e. shifting forward as we store the j-1 value in jth term
    // then j=j-1 till 0 as the while loop condition and then a[j]=tmp which in base case 
    // would be a[0]=temp if first element greater than tmp
    //note that we start from index 1 comparing with a[0] and so on so on the left side
    //of ith terms the array is already sorted and then the next element has to be sorted
    {
        a[j+1]=a[j];// we have to store jth term in ith(j+1 th term) not in jth(i-1 th term)
        j=j-1;
    }
    a[j+1]=tmp;
    //for 2 terms i=1, j=0, tmp=a[1] , a[1]=a[0] on condition, j=0-1=-1 and since condition
    //j>=0 dissatisfied, a[j+1]=a[-1+1]=a[0]=tmp;

    //initially for condition j>0 for 2 terms was not possible as j=i-1 which was j=0 so
    //loop never ran and so rather than a[j]=a[j-1] and j>0 we used a[j+1]=a[j] and j>=0
    //note that we have to put the temp value in "j+1" term as for last case j>=0, j=j-1 gives
    //j=-1 so a[j+1]=tmp
}

std::cout<<"\n The output array is \n";
for(i=0;i<n;i++)
{
    std::cout<<a[i]<<" ";
}
}
//in while loop we took j>0 as we move, if we have 2 elements in which secnd one is greater
//then the ending condition would be j>0 as already tmp<a[j]. 
//&& condition means any of them false, close the loop
//      truth table for AND Gate

//  Input1   Input2   Output 
//     0        1       0
//     0        0       0 
//     1        1       1
//     1        0       0