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

int main()
{
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      m[a[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
      for (int j = i + 1; j <= 2 * n; j++)
      {
        if (1LL * i * j > 2 * n)
          break;
        int pro = i * j;
        auto ind1 = m.find(i);
        auto ind2 = m.find(j);
        if (ind1 == m.end() || ind2 == m.end())
          continue;

        if ((*ind1).ss + (*ind2).ss == pro)
          ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}