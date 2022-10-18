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

void solve()
{
  int len;
  cin >> len;
  vi a(len), b(len);
  int one = 0;
  for (int i = 0; i < len; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < len; i++)
  {
    cin >> b[i];
  }
  if (a == b)
  {
    cout << 0 << "\n";
    return;
  }
  int a_one = 0, b_one = 0;
  for (int i = 0; i < len; i++)
  {
    a_one += a[i];
    b_one += b[i];
  }

  int val1 = abs(a_one - b_one) + 1;
  int val2 = 0;
  for (int i = 0; i < len; i++)
  {
    if (a[i] != b[i])
      val2++;
  }
  cout << min(val1, val2) << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// rearrange and check diff and then check simple diff and return min