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
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vi hi(n);
    for (int i = 0; i < n; i++)
      cin >> hi[i];

    sort(hi.begin(), hi.end());

    if (n == 2)
    {
      cout << hi[0] << " " << hi[1] << "\n";
      continue;
    }

    // find the min diff
    int pos = -1, minval = INT_MAX;
    for (int i = 1; i < n; i++)
    {
      // print2(minval, abs(hi[i] - hi[i - 1]));
      if (minval > abs(hi[i] - hi[i - 1]))
      {
        pos = i;
        minval = abs(hi[i] - hi[i - 1]);
      }
    }
    // print1(pos);
    // pos+1 as we want to start with 2nd 2
    for (int i = pos; i < n; i++)
      cout << hi[i] << " ";
    for (int i = 0; i < pos; i++)
      cout << hi[i] << " ";

    cout << "\n";
  }

  return 0;
}

// as we heights to only inc(difficulty inc with it), we want to sort and find the min diff, store the pos
// then show elements from pos to n, and then 0 to pos