#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include "cmath"

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
  int n, m, a;
  cin >> n >> m >> a;

  long long x, y, sum;
  x = n / a;
  y = m / a;

  if (n % a != 0)
    x++; // add one more tile even if it takes more area

  if (m % a != 0)
    y++;

  sum = x * y; // number of horizontal tiles * vertical
  cout << sum;
  return 0;
}