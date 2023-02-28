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
  int n, a, b;
  cin >> n >> a >> b;

  set<char> s = {'E', 'Q', 'U', 'I', 'N', 'O', 'X'};
  vector<string> vec(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  ll sarthak = 0, anuradha = 0;
  for (auto str : vec)
  {
    if (s.count(str[0]))
    {
      sarthak = (sarthak + a) % mod;
    }
    else
      anuradha = (anuradha + b) % mod;
  }

  if (sarthak == anuradha)
    cout << "DRAW\n";
  else if (sarthak > anuradha)
    cout << "SARTHAK\n";
  else
    cout << "ANURADHA\n";
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