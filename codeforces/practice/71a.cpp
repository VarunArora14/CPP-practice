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
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    if (str.length() > 10)
    {
      int n = str.length();
      int len = n - 2;
      string mid = to_string(len);
      string ans = str[0] + mid + str[n - 1];
      cout << ans << "\n";
    }
    else
      cout << str << "\n";
  }
  return 0;
}