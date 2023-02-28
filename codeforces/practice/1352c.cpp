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
ll bs(ll n, ll k)
{
  ll start = 1, end = 1e10;
  ll res = start;
  while (start < end)
  {
    ll mid = start + (end - start) / 2;
    if (mid - (mid / n) >= k)
    {
      res = mid; // store potential ans
      end = mid;
    }
    else
      start = mid + 1;
  }

  return res;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    cout << bs(n, k) << "\n";
  }
  return 0;
}

/*
we know for n=2, k=5, the numbers are [1,3,5,7,9] where 9 is the ans as the kth positive integer not divisible by n
Numbers not divisible by n in range [0,a] = a - (a/n) like [0,9] => 9-9/2 = 9-4=5 which works for above condition

so we have to find this number a, such that in range [0,a], a-a/n=k which means a is the kth non divisible number
*/