#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
int maxval = INT_MIN, minval = INT_MAX;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{

  int n = maze.size(), m = maze[0].size();
  int x = entrance[0], y = entrance[1];

  if (maze[x][y] == '+')
    return -1;

  queue<vector<int>> q;
  vector<vector<int>> vis(n + 1, vector<int>(m + 1));
  vis[x][y] = 1;
  q.push({x, y, 0}); // 0 is the starting distance

  vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();

    int r = front[0];
    int c = front[1];

    for (auto dir : dirs)
    {
      int nrow = r + dir[0];
      int ncol = c + dir[1];

      if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && maze[nrow][ncol] == '.' && vis[nrow][ncol] == 0)
      {

        if (nrow == 0 || ncol == 0 || nrow == n - 1 || ncol == m - 1)
          return front[2] + 1; // prev ans computed +1 for new visited

        q.push({nrow, ncol, front[2] + 1}); // add 1 to prev distance
        vis[nrow][ncol] = 1;
      }
    }
  }

  return -1;
}

int main()
{
  vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
  vi entrance = {1, 2};

  cout << nearestExit(maze, entrance);
  return 0;
}