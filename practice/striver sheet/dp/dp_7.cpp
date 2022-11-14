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

int rec(vvi &points, int day, int prev = -1)
{
  // cout << "hey\n";
  if (day == 0)
  {
    int maxval = 0;
    for (int j = 0; j <= 2; j++)
    {
      if (prev != j)
      {
        maxval = max(maxval, points[0][j]); // day=0
      }
    }
    return maxval;
  }

  int maxval = 0;
  for (int j = 0; j <= 2; j++)
  {
    if (j != prev)
    {
      // calculate the current day by considering points[day][j] and adding func of day-1 with j being the idx to be avoided for same training
      int curr = points[day][j] + rec(points, day - 1, j);
      maxval = max(maxval, curr);
    }
  }
  return maxval;
}

// prev=3 as dp cannot have negative indices
int memo(vvi &points, int day, vvi &dp, int prev = 3)
{
  if (dp[day][prev] != -1)
    return dp[day][prev];

  // base case
  if (day == 0)
  {
    int maxval = 0;
    for (int j = 0; j <= 2; j++)
    {
      if (j != prev)
      {
        maxval = max(maxval, points[0][j]);
      }
    }
    return dp[day][prev] = maxval;
  }

  int maxval = 0;
  for (int j = 0; j <= 2; j++)
  {
    if (j != prev)
    {
      int curr = points[day][j] + memo(points, day - 1, dp, j);
      maxval = max(maxval, curr);
    }
  }
  return dp[day][prev] = maxval;
}

int tabulation(vvi &points)
{
  int n = points.size();
  vvi dp(n, vi(4, 0));
  // base cases
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // day is for day, prev is for previous day(assumed as chosen) consideration and task is for current day task we can pick that day
  for (int day = 1; day < n; day++)
  {
    for (int prev = 0; prev < 4; prev++)
    {
      // here prev is day we assume was chosen before
      dp[day][prev] = 0;
      for (int task = 0; task < 3; task++)
      {
        if (task != prev)
        {
          // for current day choose the 'task' and add to last day's result where task is the day we avoid
          int curr_activity = points[day][task] + dp[day - 1][task];
          dp[day][prev] = max(curr_activity, dp[day][prev]); // for ith day and prev day chosen we find the current day max value
        }
        // since task goes from 0 to 2 and we use dp[day-1][task] for previous sum, we can assure except the first day, no prev=3
        // will be chosen
      }
    }
  }
  return dp[n - 1][3];
}

int optimal(vvi &points)
{
  int n = points.size();
  vi dp(3);
  dp[0] = points[0][0];
  dp[1] = points[0][1];
  dp[2] = points[0][2];

  for (int i = 1; i < n; i++)
  {
    int first = points[i][0] + max(dp[1], dp[2]);
    int second = points[i][1] + max(dp[0], dp[2]);
    int third = points[i][2] + max(dp[0], dp[1]);

    dp = {first, second, third};
  }
  int maxval = 0;
  for (int num : dp)
    maxval = max(num, maxval);
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
  // vvi dp(n, vi(4, -1));
  // // cout << rec(points, n - 1); // bottom up approach and prev=-1 at start, pass n-1 as day=n invalid memory location
  // cout << memo(points, n - 1, dp) << "\n"; // not passing prev again as default value=3
  // for (auto vec : dp)
  // {
  //   for (int num : vec)
  //     cout << num << " ";
  //   cout << "\n";
  // }

  cout << optimal(points);
  return 0;
}