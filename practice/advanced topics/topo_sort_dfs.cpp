// https://ncduy0303.github.io/Competitive-Programming/Graphs/Topological%20Sort/Topological%20Sort%20(DFS).cpp
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

const int N = 1e5 + 5;
vi adj[N];
vi ans;
void topo_dfs(int i, vi &vis)
{
  // cout << "hello";
  vis[i] = 1; // mark as visited and go to nbrs
  for (int nbr : adj[i])
  {
    if (vis[nbr] == 0)
      topo_dfs(nbr, vis);
    else if (vis[nbr] == 1) // it means nbr and i are in same cycle or path
    {
      // cout << vis[nbr] << " " << nbr << " ";

      // not for vis[nbr]==2 as multiple nodes can point to same node and when vis[nbr]==2 it is outside the call stack
      // In course schedule it would mean course x requires 2 or more courses to be done before which is not problem
      cout << "cycle found so not possible";
      return;
    }
  }
  vis[i] = 2;       // means gone through nbrs and pulled out from function stack too
  ans.push_back(i); // push the node when gone through the nbrs and reverse ans for sorted order
}

int main()
{
  int n, m;
  cin >> n >> m; // n is num of nodes and m edges
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // directed
  }

  vi vis(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == 0) // not visited
    {
      topo_dfs(i, vis);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size();
  for (int val : ans)
    cout << val << " ";

  return 0;
}

/*
topological sorting is reverse of DFS so we do dfs and reverse the ans vector
we keep going the non visited and mark them visited and go to their nbrs, if vis found then cycle else keep pushing till end and at last push the
node in ans vector.
*/