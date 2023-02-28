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
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
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
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;
int solve(int n, int m)
{
  if (n >= m)
    return n - m; // if n bigger, just return difference as ans
  else if (m % 2 == 0)
  {
    // for even m, do 1 step of divide and call same function, reverse of multiplying as we try to reach n as we have defined base case above
    return 1 + solve(n, m / 2);
  }
  else
  {
    // otherwise we had to add 1 to m(reverse of n=n-1)
    return 1 + solve(n, m + 1); // makes m even now
    // we can do return 2 + solve(n, (m+1)/2) instead as well to reduce "else if" fn call later on
  }
}
int main()
{
  int n, m;
  cin >> n >> m;

  cout << solve(n, m);
  return 0;
}

// we had to do either n=n*2 or n=n-1 to get to m, which we reverse to m=m/2 and m=m+1 operations instead