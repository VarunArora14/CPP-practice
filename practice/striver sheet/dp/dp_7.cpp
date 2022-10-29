// https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
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

int tabulation(vvi &points, int day, int prev)
{
  // base case fr day=0 the last day as we go from n-1 to 0
  int maxval = 0;
  if (day == 0)
  {
    for (int i = 0; i <= 2; i++)
    {
      if (i != prev)
      {
        maxval = max(maxval, points[0][i]); // at 0th day, return ith workout
      }
    }
    return maxval;
  }

  for (int i = 0; i <= 2; i++)
  {
    if (i != prev)
    {
      int activity = points[day][i] + tabulation(points, day - 1, i); // for day-1, i will be prev as go go from higher to smaller number of days
      maxval = max(maxval, activity);
    }
  }
  return maxval;
}

int main()
{
  int n;
  cin >> n;
  vvi points = vvi(n, vi(3));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> points[i][j];
    }
  }
  return 0;
}