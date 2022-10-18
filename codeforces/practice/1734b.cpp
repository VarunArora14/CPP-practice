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
    int n; // number of floors of pyramid
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= i; j++)
      {
        cout << (j == 1 || i == j) << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
// For pyramid to be nice, all it's floor must have same values
// the max value can be i and it is the upper bound which is achievable
// It is also possible to find a configuration of torches in the pyramid such that the
// brightnesses of the rooms on the i-th floor is exactly i, i.e. it attains the upper bound.
// The configuration is as follows: Room (i,j) contains a torch if and only if it is the leftmost room (i=1) or
// the rightmost room (i=j) on the i-th floor.
// This is valid because for all rooms (i,j), it can be reached from (1,1), (2,1), (3,1), …, (i−j+1,1) and (2,2), (3,3), …, (j,j).
// In other words, room (i,j) has brightness (i−j+1)+j−1=i, so the pyramid is nice.