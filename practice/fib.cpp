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

int fib(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;
  if (dp[n] != -1)
    return dp[n]; // memo value returned
  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << fib(n, dp);
  for (int num : dp)
    cout << num << " ";
  return 0;
}
