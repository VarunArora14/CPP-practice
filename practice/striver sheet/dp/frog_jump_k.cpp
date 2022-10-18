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

int helper(vi &stairs, int n, int k)
{
  vi dp(n);
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int currmin = INT_MAX;
    for (int j = 1; j <= k && i - j >= 0; j++)
    {
      int curr = dp[i - j] + std::abs(stairs[i] - stairs[i - j]); // current stair minus the i-j where 1<=j<=k
      currmin = min(curr, currmin);
    }
    dp[i] = currmin;
  }
  for (int num : dp)
    cout << num << " ";
  return dp[n - 1];
}

int main()
{
  int n, k;
  cin >> n >> k;
  vi stairs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> stairs[i];
  }
  cout << helper(stairs, n, k);
  return 0;
}