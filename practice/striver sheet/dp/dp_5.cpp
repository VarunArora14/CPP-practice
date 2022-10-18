// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
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

// recursive solution
int rec(vi &nums, int n, int idx)
{
  if (idx == 0)
    return nums[0]; // only 1 element so return that
  if (idx < 0)
    return 0; // at idx=1 this case works

  int pick = nums[idx] + rec(nums, n, idx - 2); // include current element
  int non_pick = 0 + rec(nums, n, idx - 1);

  return max(pick, non_pick);
}

// memoized solution
int memo(vi &nums, vi &dp, int idx)
{
  // same as recursive except we store the results
  if (dp[idx] != -1)
    return dp[idx];

  if (idx == 0)
    return nums[0];

  if (idx < 0)
    return 0; // case idx=1 having func(nums,dp,idx-2)

  int pick = nums[idx] + memo(nums, dp, idx - 2);
  int non_pick = memo(nums, dp, idx - 1);

  dp[idx] = max(pick, non_pick);
  return dp[idx];
}

// dp solution
int dp_sol(vi &nums, int n)
{
  vi dp(n);
  dp[0] = nums[0]; // base case for 1 element

  // we can either include the current house and use dp[i-2] or ignore the current house and take dp[i-1] at each step
  dp[1] = max(nums[0], nums[1]); // so that for 2 elements or case [2,1,4,9] we get correct ans=11
  for (int i = 2; i < n; i++)
  {
    dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
  }

  // for (int num : dp)
  //   cout << num << " ";
  // cout << "\n";

  return dp[n - 1];
}

int main()
{
  int n;
  cin >> n;
  vi nums(n), dp(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << dp_sol(nums, n);
  return 0;
}

// House robber - find the max sum of non adjacent houses without rotation(last and first house same)