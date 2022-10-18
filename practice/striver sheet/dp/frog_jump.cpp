// DP - 3
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
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

int memoized(int idx, vi &stairs, vi &dp)
{
  if (idx == 0)
    return 0; // base case
  if (dp[idx] != -1)
    return dp[idx]; // smale value occurs

  int jumptwo = INT_MAX;
  int jumpone = memoized(idx - 1, stairs, dp) + std::abs(stairs[idx] - stairs[idx - 1]);
  if (idx > 1)
  {
    // check as not allow passing 1 for cases idx<0
    jumptwo = memoized(idx - 2, stairs, dp) + std::abs(stairs[idx] - stairs[idx - 2]);
  }
  dp[idx] = min(jumpone, jumptwo); // memoizing the answer
  return dp[idx];
}

int tabulation(int idx, vi &stairs)
{
  int n = stairs.size();
  vi dp(n, -1);
  dp[0] = 0; // going from 0th stair to same
  for (int i = 1; i < n; i++)
  {
    int jumptwo = INT_MAX;
    int jumpone = dp[i - 1] + std::abs(stairs[i] - stairs[i - 1]);
    if (i > 1)
    {
      jumptwo = dp[i - 2] + std::abs(stairs[i] - stairs[i - 2]); // takes care of case dp[2]
    }

    dp[i] = min(jumpone, jumptwo);
  }
  return dp[n - 1];
}

int main()
{
  int n;
  cin >> n;
  vi stairs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> stairs[i];
  }
  vi dp(n, -1); // -1 as init case
  cout << memoized(n - 1, stairs, dp);
  cout << "\n"
       << tabulation(n, stairs);
  return 0;
}

// dp[1] = stairs[1] - stairs[0], dp[2] = min(dp[1], stairs[2] - dp[0]) where dp[0]=stairs[0]
// we can change to dp[i] = min(dp[i-2] + stairs[i]-stairs[i-2], dp[i-1] + stairs[i] - stairs[i-1])

// if you think of f(5) tree having subtrees f(4) and f(3) you will see that there are multiple cases and repetitions
// Cases are for i==0, we can return 0 as going from 0 to 0th stair has no time
// if idx==1 means one child f(0) and no f(-1) allowed by checking before values of idx. For f(1) ans is jumpone
// jumpone = func(idx-1) + abs(stairs[idx]-stairs[i-1])