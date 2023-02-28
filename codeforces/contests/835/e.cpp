#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
int maxval = INT_MIN, minval = INT_MAX;

ll check(vi &nums, int n)
{
  ll res = 0, count0 = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (nums[i] == 0)
      count0++;
    else
      res += count0;
  }
  return res;
}

void solve()
{
  int n;
  cin >> n;
  vi nums(n);
  fo(i, n) cin >> nums[i];

  // count0 more than count1, we have to swap first 0 as 1
  // if count1 more than count0, swap the last 1 as 0
  // if count0==count1, check the current ans and then max of 0 and 1 swaps. It is better to calculate for all 3 cases and print the max
  // rather than if else as hardly makes diff in TC

  ll ans = 0;
  ans = check(nums, n);

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
    {
      nums[i] = 1;
      ans = max(ans, check(nums, n));
      nums[i] = 0;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (nums[i] == 1)
    {
      nums[i] = 0;
      ans = max(ans, check(nums, n));
      nums[i] = 1;
      break;
    }
  }

  cout << ans << "\n";
}

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}