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

void solve()
{
  int n;
  cin >> n;
  vi nums;

  // push only different elements to check change of slope as same elements arent helpful for comparison
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    if (i == 0 || x != nums.back())
      nums.push_back(x);
  }

  int valleys = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if ((i == 0 || nums[i] < nums[i - 1]) && (i == nums.size() - 1 || nums[i] < nums[i + 1]))
      valleys++;
  }

  if (valleys == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
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

// for a point to be valley, it must have left side and right side bigger or must be at the boundary
// so if point is at (idx=0 OR nums[i]<nums[i-1]) AND (idx==n-1 || nums[i]<nums[i+1]) valley++