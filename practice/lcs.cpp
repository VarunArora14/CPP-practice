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

int rec(string s1, string s2, int i1, int i2)
{
  if (i1 == s1.length() || i2 == s2.length())
    return 0;

  if (s1[i1] == s2[i2])
    return rec(s1, s2, i1 + 1, i2 + 1) + 1;

  // if not same chars at i1 and i2
  int v1 = rec(s1, s2, i1 + 1, i2); // make i1 to next char
  int v2 = rec(s1, s2, i1, i2 + 1); // make i2 to next char
  return max(v1, v2);
}

int memo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
  if (i == s1.length() || j == s2.length())
    return 0;
  // 2 variables i1 and i2, dp[i][j] stores the longest common subsequence between substring s1[0...i] and substring s2[0...j]
  if (dp[i][j] != -1)
    return dp[i][j];

  if (s1[i] == s2[j])
  {
    return dp[i][j] = memo(s1, s2, i, j, dp) + 1;
  }

  int v1 = rec(s1, s2, i + 1, j); // make i to next char
  int v2 = rec(s1, s2, i, j + 1); // make j to next char
  return dp[i][j] = max(v1, v2);
}

int top_down(string s1, string s2, int i, int j)
{
  if (i == 0 || j == 0)
  {
    return 0;
  }

  if (s1[i - 1] == s2[j - 1])
    return top_down(s1, s2, i - 1, j - 1) + 1; // +1 for match

  int v1 = top_down(s1, s2, i - 1, j); // go to next i, right to left for s1
  int v2 = top_down(s1, s2, i, j - 1); // same as above, but for string s2
  return max(v1, v2);
}

int solve(string s1, string s2)
{
  vector<vector<int>> dp;
  int n = s1.length();
  int m = s2.length();
  dp.resize(n + 1, vector<int>(m + 1));

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] == 0;
      }
      // dp[i][j] stores the lcs between string s1[0...i] and s2[0...j]
      else if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1; // prev result plus current
      }
      else
      {
        // max of subsequence till i-1 and j-1
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  int m = s2.length();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  cout << solve(s1, s2);
  return 0;
}