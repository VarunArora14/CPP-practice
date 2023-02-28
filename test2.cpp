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
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

void solve1(int n)
{

  int i, j;
  for (i = n - 1; i > 0; i--)
  {
    // cout << " ";

    // outer gap loop
    for (j = n - 1; j > i; j--)
    {
      cout << " ";
    }

    // 65 is ASCII of 'A'
    cout << n - i;

    // inner gap loop
    for (j = 1; j < (i * 2); j++)
      cout << " ";

    if (i >= 1)
      cout << n - i;
    cout << "\n";
  }
}

void solve2(int n)
{
  int i, j, k = 0;
  for (i = n; i > 0; i--)
  {

    // outer gap loop
    for (j = n; j > k + 1; j--)
    {
      cout << " ";
    }

    // 65 is ASCII of 'A'
    cout << i;

    // inner gap loop
    for (j = 1; j < (k * 2); j++)
      cout << " ";

    if (i < n)
      cout << i;
    cout << "\n";
    k++;
  }
}

int main()
{
  int n;
  cin >> n;
  solve1(n);
  solve2(n);
  return 0;
}