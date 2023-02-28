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
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
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
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

vi solve(int n, vvi &red, vvi &blue)
{
  // create a adjacency list with color as well along with node connected to u-> {v, color}
  vector<vpii> graph(n); // n vectors of vector<pair<int,int>>

  for (auto r : red)
  {
    int u = r[0];
    int v = r[1];
    graph[u].pb({v, 1});
  }

  for (auto b : blue)
  {
    int u = b[0];
    int v = b[1];
    graph[u].pb({v, -1});
  }

  // now we need to store the shortest distances using bfs
}

int main()
{
  int n = 3;
  vvi redEdges = {{0, 1}, {1, 2}};
  vvi blueEdges = {};

  return 0;
}