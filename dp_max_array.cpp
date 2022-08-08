#include <iostream>
#include <cmath>
/*
Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
*/
using namespace std;

int func(int a[], int s)
{
    /* int maxs,maxe,p1=0,p2,pos;
   maxs=INT16_MIN;
   maxe=0;
    int i;
    for(i=0;i<s;i++)
    {
        maxe+=a[i];
        if(maxe>maxs)
        {
            maxs=maxe;
            pos=p1;
            p2=i;
        }
        if(maxe<0)
        {
            maxe=0;
            p1=i+1;
        }
        problem with only addition would be that if after few negative elements, a new 
        subarray starts with greater value, only maxe+=a[i] would add negative values too
        for that, we have to put maxse=0 for negative but te=hen that would create problem
        for measuring arrays data with many negative values
    }

    A better approach would be to calculate max of - curr_max=max(a[i],curr_max+a[i])
    maxe=max(maxe,curr_max)
    */
   int maxe=a[0];
   int curr_max=a[0];
   for(int i=1;i<s;i++) //i=1
   {
       curr_max=max(a[i],curr_max+a[i]);// checks for current a[i] and of curr_max+a[i]
       // not curr_max,curr_max+a[i]
       maxe=max(maxe,curr_max);
       cout<<"curr_max="<<curr_max<<" and maxe="<<maxe<<endl;
   }
   return maxe;
}
int main()
{
    cout << "enter the size";
    int s, a[20];
    cin >> s;
    cout << "enter array" << endl;
    int i;
    for (i = 0; i < s; i++)
    {
        cin >> a[i];
    }
   cout<< func(a, s);
}
