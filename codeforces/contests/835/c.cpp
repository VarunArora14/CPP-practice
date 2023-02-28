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
  int maxval = INT_MIN, max2 = INT_MIN; // find 2nd largest for comparing with largest

  int n;
  cin >> n;
  vi nums(n);
  fo(i, n) cin >> nums[i];

  vi n2 = nums;

  sort(begin(n2), end(n2));
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == n2[n - 1])
      cout << nums[i] - n2[n - 2] << " "; // print 2nd largest
    else
      cout << nums[i] - n2[n - 1] << " "; // subtract the largest otherwise
  }

  cout << "\n";
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