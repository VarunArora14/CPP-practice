#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include "unordered_map"
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void solve()
{
  int len;
  cin >> len;
  vi nums(len);
  for (int i = 0; i < len; i++)
  {
    cin >> nums[i];
  }

  int val = 1;
  for (int i = 1; i < len; i++)
  {
    if (nums[i] >= i + 1)
    {
      val += i + 1;
    }
    else
    {
      cout << "val before " << val << "\n";
      val += nums[i];
      cout << "val after " << val << "\n";
    }
    // cout << val << " " << nums[i] << "\n";
  }
  // cout << val << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}