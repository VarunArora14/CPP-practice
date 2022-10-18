// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
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

int solve(vi &nums, int n)
{
  vi dp(n);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; i++)
  {
    dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
  }

  for (int num : dp)
    cout << num << " ";
  cout << "\n";
  return dp[n - 1];
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vi temp(n - 1);
  // ignore the first ele
  for (int i = 0; i < n - 1; i++)
  {
    temp[i] = nums[i + 1];
  }
  int v1 = solve(temp, n - 1);
  temp.pop_back(); // remove last and insert first ele
  temp.insert(temp.begin(), nums[0]);
  int v2 = solve(temp, n - 1);
  cout << max(v1, v2);
  return 0;
}
// since in circular manner, we have to avoid last and first ele collision meaning both cannot be chosen
// For this we can call the same method 2 times, in first case then nums[0] is removed and in second case nums[n-1] is removed
// so that we find for bath cases the max values, and compare them to find the larger one amongst them.