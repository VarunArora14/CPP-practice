#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

// A bitonic sequence is one which starts from leftmost point and then strictly rightwards to 
// rightmost point and then strictly backward to starting point

// Describe O(n^2) algorithm finding the optimal bitonic tour. Assume no 2 points have same  
// x coordinates
// Hint - Scan left to rigth maintaining 2 possibilities of left and right

// thomas cormen page 405
void bitonic()
{
    int arr[][2] = { {5,4}, {0,5}, {1,0}, {8,2}, {2,3}, {7,5}, {6,1}  };
    // array<int,2> arr2[7] = { {0,5}, {1,0}, {2,3}, {5,4}, {6,1}, {7,5}, {8,2} };
    sort(arr,arr+7);
    int i,j;
    for(i=0;i<7;i++)
    {
      for(j=0;j<2;j++)
      {
        cout<<arr[i][j]<<" ";
      }
      cout<<"\n";
    }

    
}

int main()
{
    bitonic();
}