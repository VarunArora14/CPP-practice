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
  cin >> n;                   // number of force vectors
  vvi forces = vvi(n, vi(3)); // 2d vector of n*3 as 3 are the axes
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> forces[i][j];
    }
  }
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++)
  {
    x += forces[i][0]; // x coordinate
    y += forces[i][1]; // y ""
    z += forces[i][2];
  }
  if (x == 0 && y == 0 && z == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
// for the net force to be 0, the sum of x forces, y forces and z must net to 0