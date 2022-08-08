// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
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

int kadane(vi nums)
{
  // use kadane algo to find the subarray sum
  int sum = 0, maxsum = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    maxsum = max(maxsum, sum);
    if (sum < 0)
      sum = 0;
  }
  return maxsum;
  // case [-5] and [-5,-2] as why take max and then sum=0 if sum<0
}

void sol(vi nums)
{
  // to find the maxsum and minsum we use 2 vars storing the maxsum till now and
  int n = nums.size();

  if (n == 1)
  {
    cout << nums[0];
    return;
  }
  int currmax = nums[0], maxsum = nums[0], minsum = nums[0], currmin = nums[0], total = 0;

  for (int &i : nums)
    total += i;

  for (int i = 1; i < n; i++)
  {
    // kadane's algorithm
    currmax = max(currmax + nums[i], nums[i]);
    maxsum = max(maxsum, currmax);

    // finding the smallest subarray sum
    currmin = min(currmin + nums[i], nums[i]);
    minsum = min(minsum, currmin);
  }

  // the final ans is max of both
  int ans = max(maxsum, total - minsum);

  cout << "ans is " << ans;
}

int main()
{
  vi nums = {11, 10, -20, 5, -3, -5, 8, -13, 10};
  sol(nums);
  return 0;
}

/*
Here the trick is to find the subarray sum using kadane and find the min subarray sum using kadane and at the end do
ans = max(maxsum, sum-minsum)
modify Kadane’s algorithm to find a minimum contiguous subarray sum and the maximum contiguous subarray sum, then check for the maximum value between the max_value
and the value left after subtracting min_value from the total sum.

We will calculate the total sum of the given array.
We will declare the variable curr_max, max_so_far, curr_min, min_so_far as the first value of the array.
Now we will use Kadane’s Algorithm to find the maximum subarray sum and minimum subarray sum.
Check for all the values in the array:-
  If min_so_far is equaled to sum, i.e. all values are negative, then we return max_so_far.
  Else, we will calculate the maximum value of max_so_far and (sum – min_so_far) and return it.
*/