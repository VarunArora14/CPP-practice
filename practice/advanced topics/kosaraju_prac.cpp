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
vi adj[N], transpose[N];

void topo_sort(int node, vi &vis, vi &sorted)
{
  vis[node] = 1;
  for (int nbr : adj[node])
  {
    if (vis[nbr] == 0)
    {
      topo_sort(nbr, vis, sorted);
    }
  }
  sorted.push_back(node);
}

void dfs(int num, vi &vis)
{
  vis[num] = 1;
  cout << num << " ";
  for (int nbr : transpose[num])
  {
    if (vis[nbr] == 0)
    {
      dfs(nbr, vis);
    }
  }
  // nothing to do here
}
void kosaraju(vi adj[N], int n)
{
  // first do the topo sort
  vi vis(n, 0), sorted; // sorted stores the order of dfs which in reverse gives topo sort

  for (int i = 0; i < n; i++)
  {
    if (vis[i] == 0)
    {
      topo_sort(i, vis, sorted);
    }
  }
  // reverse the dfs order for topo sort
  reverse(sorted.begin(), sorted.end());

  fill(vis.begin(), vis.end(), 0); // make all ele of vis 0 again

  // transpose the graph, which we have done at start, now we dfs values from the sorted vector and print those ele in inorder manner
  for (int num : sorted)
  {
    if (vis[num] == 0)
    {
      dfs(num, vis);
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
    transpose[v].push_back(u);
  }
  kosaraju(adj, n);
  return 0;
}

/*
It is used for printing and finding all the SCC. For this we have 3 steps -
1. Find the topo sort order in a vector or stack
2. Create transpose of the graph either in input or new graph where you do adj2[nbr].push_back(val)
3. Do the dfs of this but in a way that you print the first element(preorder)

1->2->3

3 2 1

5 5
1 0
0 2
2 1
0 3
3 4
*/