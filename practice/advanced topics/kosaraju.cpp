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
vi adj[N], adj2[N];

void dfs(int val, vi &vis, vi &topo)
{
  vis[val] = 1; // mark as visited and travel the adj nodes

  for (int node : adj[val])
  {
    if (!vis[node])
    {
      dfs(node, vis, topo);
    }
  }

  topo.push_back(val);
}

void dfsUtil(int val, vi &vis)
{
  vis[val] = 1;
  cout << val << " ";

  for (int node : adj2[val])
  {
    if (vis[node] == 0)
    {
      // not visited
      dfsUtil(node, vis);
    }
  }
  // nothing to do here
}

void kosaraju(vi adj[N], int n)
{
  // do the topo sort by dfs and reverse the vector or put them in stack
  vi vis(n);
  vi topo;
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == 0)
    {
      dfs(i, vis, topo);
    }
  }
  // reverse the dfs for topological
  reverse(topo.begin(), topo.end());

  // Transpose the graph or use adj2 here and make vis empty again
  fill(vis.begin(), vis.end(), 0); // fill the vector with 0 to mark them unvisited as dfs made values 1

  // now process the elements from the first value of the topological order till the end
  for (int num : topo)
  {
    if (vis[num] == 0)
    {
      // call function which prints the connected components together in a single traversal
      dfsUtil(num, vis);
      cout << "\n";
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj2[v].push_back(u); // transpose of the graph
    // or we could have created a new graph and for each number of u named v, we could have done graph[v].push_back(u) for transpose
  }

  // for (int i = 0; i < n; i++)
  // {
  //   cout << i << "-> ";
  //   for (int j : adj2[i])
  //   {
  //     cout << j << " ";
  //   }
  //   cout << "\n";
  // }

  kosaraju(adj, n);

  return 0;
}

/*
5 5
1 0
0 2
2 1
0 3
3 4
*/