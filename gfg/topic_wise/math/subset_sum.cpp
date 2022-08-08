// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

int main()
{

  return 0;
}

/*
One idea is to find all subsets and store them in a set and since it is sorted, we ca traverse and check that subset does not exist
total subsets would be 2^n time

Using a simple loop, we can solve this problem in O(N log N) time. Let the input array be arr[0..n-1]. We first sort the array in non-decreasing order. Let the
 smallest element that cannot be represented by elements at indexes from 0 to (i-1) be ‘res’.  We initialize ‘res’ as 1 (smallest possible answer) and traverse the
 given array from i=0.  There are the following two possibilities when we consider element at index i:

We decide that ‘res’ is the final result: If arr[i] is greater than ‘res’, then we found the gap which is ‘res’ because the elements after arr[i] are also going to
be greater than ‘res’.
The value of ‘res’ is incremented after considering arr[i]: If arr[i] is not greater than ‘res’, the value of ‘res’ is incremented by arr[i] so ‘res’ = ‘res’+arr[i]
 (why? If elements from 0 to (i-1) can
represent 1 to ‘res-1’, then elements from 0 to i can represent from 1 to ‘res + arr[i] – 1’ by adding arr[i] to all subsets that represent 1 to ‘res-1’ which we
have already determined to be represented)
Following is the implementation of the above idea.
*/