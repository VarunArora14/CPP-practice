// https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/
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

int solve(vvi &nums, int n, int m)
{
  vvi dp(n, vi(m));
  // smaller problem at the end so bottom up
  // also, travel each row first then each column for optimized ans
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      // last row base case, smallest subproblem
      if (i == n - 1)
      {
        dp[i][j] = nums[i][j];
      }
      else if (j == 0)
      {
        // first column, we can go (i+1,j+1), (i+1,j) but not (i+1,j-1) as j would become -ve
        dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + nums[i][j];
      }
      else if (j == m - 1)
      {
        // similar logic for last row as well, exclude (i+1,j+1)
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1]) + nums[i][j];
      }
      else
      {
        dp[i][j] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i + 1][j - 1])) + nums[i][j];
      }
    }
  }
  int maxval = 0;
  for (int j = 0; j < m; j++)
  {
    maxval = max(maxval, dp[0][j]);
  }
  return maxval;
}

int rec_helper(vvi &nums, int i, int j)
{
  // base cases
  if (i == 0)
  {
    return nums[0][j];
  }
  if (j < 0 || j >= nums[0].size())
    return -1e9; // for overflow or underflow, return hugenegative value

  int up = nums[i][j] + rec_helper(nums, i - 1, j);
  int topleft = nums[i][j] + rec_helper(nums, i - 1, j - 1);
  int topright = nums[i][j] + rec_helper(nums, i - 1, j + 1);

  return max(up, max(topright, topleft));
}

int memo_func(vvi &nums, int i, int j, vvi &dp)
{
  if (j < 0 || j >= nums[0].size())
    return -1e9;
  if (i == 0)
    return nums[0][j];

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = nums[i][j] + rec_helper(nums, i - 1, j);
  int topleft = nums[i][j] + rec_helper(nums, i - 1, j - 1);
  int topright = nums[i][j] + rec_helper(nums, i - 1, j + 1);

  return dp[i][j] = max(up, max(topright, topleft));
}

int memo(vvi &nums)
{
  int n = nums.size();
  int m = nums[0].size();

  vvi dp(n, vi(m, -1));

  int maxval = INT_MIN;
  for (int j = 0; j < m; j++)
  {
    int ans = memo_func(nums, n - 1, j, dp); // call for each column
    maxval = max(maxval, ans);
  }
  return maxval;
}

int tabulation(vvi &nums)
{
  int n = nums.size();
  int m = nums[0].size();

  vvi dp(n, vi(m, 0));

  // base case for first row
  for (int j = 0; j < m; j++)
  {
    dp[0][j] = nums[0][j];
  }

  // this approach goes from i=0 to i=n-1 whereas the solve() was from i=n-1 to 0
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = dp[i - 1][j] + nums[i][j];

      int topleft = nums[i][j]; // store curr num, check if
      if (j > 0)
        topleft += dp[i - 1][j - 1];
      else
        topleft += -1e9; // huge negative number so considered very small

      int topright = nums[i][j];
      if (j < m - 1)
        topright += dp[i - 1][j + 1];
      else
        topright += -1e9;

      int curr_ans = max(up, max(topright, topleft));

      dp[i][j] = curr_ans;
    }
  }

  int ans = 0;
  for (int j = 0; j < m; j++)
  {
    ans = max(ans, dp[n - 1][j]);
  }
  return ans;
}

// since we need only prev row, we can use instead 1d dp and store the current row in prev and use that for next row
int space_optimized(vvi &nums)
{
  int n = nums.size();
  int m = nums[0].size();

  vi curr(m), prev(m);

  // base case
  for (int j = 0; j < m; j++)
  {
    prev[j] = nums[0][j];
  }
  // here prev is dp[i-1]
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = prev[j] + nums[i][j]; // current ele + prev row ele

      int topleft = nums[i][j];
      if (j > 0)
        topleft += prev[j - 1]; // same as dp(i-1,j-1)
      else
        topleft += -1e9;

      int topright = nums[i][j];
      if (j < m - 1)
        topright += prev[j + 1]; // same as dp(i-1,j+1)
      else
        topright += -1e9;

      int currmax = max(up, max(topright, topleft));
      curr[j] = currmax; // store the max value found here
    }
    prev = curr; // for next row considered, update the prev
  }

  int ans = 0;
  for (int num : curr) // here we can put prev too
    ans = max(ans, num);
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vvi nums(n, vi(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> nums[i][j];
    }
  }
  cout << space_optimized(nums);
  return 0;
}

/*
recursive func made on observation that we go from i=n upwards as up(i-1), left-diagonal(i-1,j-1) and right-diagonal(i-1,j+1)
if j<0 OR j>=m then return -INT_MAX as not possible, Also for base case i=0 return nums[0][j]
*/