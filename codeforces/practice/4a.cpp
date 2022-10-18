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
  int w;
  cin >> w;
  if (w <= 3)
  {
    cout << "NO";
    return 0;
  }

  int i, j;
  i = 2, j = w - 2; // initial values
  while (i <= j)
  {
    if (i % 2 == 0 && j % 2 == 0)
    {
      cout << "YES";
      return 0;
    }
    i += 2;
    j -= 2; // increase and decrease both by 2 as we want even
  }
  cout << "NO";

  return 0;
}