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
  int n;
  cin >> n;
  for (int i = 1; i <= n / 2; i++)
  {
    cout << i + n / 2 << " " << i << " ";
  }
  if (n % 2 != 0)
    cout << n;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }
  return 0;
}