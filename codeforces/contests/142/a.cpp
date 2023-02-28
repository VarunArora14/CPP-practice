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
    vi nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    if (n == 1)
    {
      cout << 1 << "\n";
      continue;
    }

    int one_counter = 0;
    for (int num : nums)
    {
      if (num == 1)
        one_counter++;
    }

    one_counter = one_counter - (one_counter % 2); // make even
    int rem = n - one_counter;
    cout << min(n, one_counter / 2 + rem) << "\n";
  }

  return 0;
}

// for each monster check if we can do better by killing them or health dec
// group all 1's together as best way to kill monsters is by reducing by half and for remaining kill
