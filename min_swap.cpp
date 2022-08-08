#include <iostream>

using namespace std;
int main()
{
    int A[10], B[10];
    int s1;
    cout << "size";
    cin >> s1;
    int i;
    for (i = 0; i < s1; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < s1; i++)
    {
        cin >> B[i];
    }
    int j, temp, count = 0;
    for (i = 1; i < s1; i++) //i=1
    {

        if (A[i] <= A[i - 1] && (B[i] > A[i]))
        {
            temp = B[i];
            B[i] = A[i];
            A[i] = temp;
            count++;
        }

        else if (B[i] <= B[i - 1] && A[i] > B[i])
        {
            temp = B[i];
            B[i] = A[i];
            A[i] = temp;
            count++;
        }
        else
        {
        }
        cout << count << endl;
    }

    for (i = 0; i < s1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    for (i = 0; i < s1; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}
/* here minimum swaps could be 1 for arrays - 0 4 4 5 9 and 0 1 6 8 10
The expected was 1 for - 0 1 4 5 9 and 0 4 6 8 10
whereas we got 2 for - 0 4 6 8 9 and 0 1 4 5 10

The right code would be - 

  int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int not_swap[1000] = {0};
        int swap[1000] = {1};
        for (int i = 1; i < N; ++i) {
            not_swap[i] = swap[i] = N;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                not_swap[i] = not_swap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                not_swap[i] = min(not_swap[i], swap[i - 1]);
                swap[i] = min(swap[i], not_swap[i - 1] + 1);
            }
        }
        return min(swap[N - 1], not_swap[N - 1]);
    }
    */

   /*
   JAVA SOLUTION 

   Approach #1: Dynamic Programming [Accepted]
Intuition

The cost of making both sequences increasing up to the first i columns can be expressed
 in terms of the cost of making both sequences increasing up to the first i-1 columns.
  This is because the only thing that matters to the ith column is whether the previous 
  column was swapped or not. This makes dynamic programming an ideal choice.

Let's remember n1 (natural1), the cost of making the first i-1 columns increasing and
 not swapping the i-1th column; and s1 (swapped1), the cost of making the first i-1 columns
  increasing and swapping the i-1th column.

Now we want candidates n2 (and s2), the costs of making the first i columns increasing
 if we do not swap (or swap, respectively) the ith column.

Algorithm

For convenience, say a1 = A[i-1], b1 = B[i-1] and a2 = A[i], b2 = B[i].

Now, if a1 < a2 and b1 < b2, then it is allowed to have both of these columns natural
 (unswapped), or both of these columns swapped. This possibility leads to n2 = min(n2, n1)
  and s2 = min(s2, s1 + 1).

Another, (not exclusive) possibility is that a1 < b2 and b1 < a2. This means that it is 
allowed to have exactly one of these columns swapped. This possibility leads to 
n2 = min(n2, s1) or s2 = min(s2, n1 + 1).

Note that it is important to use two if statements separately, because both of the above 
possibilities might be possible.

At the end, the optimal solution must leave the last column either natural or swapped, 
so we take the minimum number of swaps between the two possibilities.

class Solution {
    public int minSwap(int[] A, int[] B) {
        // n: natural, s: swapped
        int n1 = 0, s1 = 1;
        for (int i = 1; i < A.length; ++i) {
            int n2 = Integer.MAX_VALUE, s2 = Integer.MAX_VALUE;
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                n2 = Math.min(n2, n1);
                s2 = Math.min(s2, s1 + 1);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                n2 = Math.min(n2, s1);
                s2 = Math.min(s2, n1 + 1);
            }
            n1 = n2;
            s1 = s2;
        }
        return Math.min(n1, s1);
    }
}


Complexity Analysis

Time Complexity: O(N).

Space Complexity: O(1).