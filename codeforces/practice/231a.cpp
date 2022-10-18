#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
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

int main()
{
  int n;
  cin >> n;
  vvi nums = vvi(n, vi(3));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> nums[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < 3; j++)
    {
      nums[i][0] += nums[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i][0] >= 2)
      ans++;
  }
  cout << ans << "\n";
  return 0;
}