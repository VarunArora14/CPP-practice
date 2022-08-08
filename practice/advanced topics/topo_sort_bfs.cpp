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

const int N = 1e5 + 5; // max number of nodes as assumption
vi adj[N];

void topo_sort(vi adj[N], int n)
{
  // if u create sorted(n) and push ele, it adds next ele excluding the first n as 0 values

    vi sorted, indegree(n);

  // calc the indegree of all
  for (int i = 0; i < n; i++)
  {
    for (int j : adj[i])
    {
      indegree[j]++;
    }
  }

  queue<int> q; // store the nums with 0 indegree

  // find those ele with 0 indegree
  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  // till q empty, pop the node at end, remove the edges from the node by reducing the indegree of its nbrs and check if their indegree==0 then push in queue
  while (!q.empty())
  {
    int val = q.front();
    cout << val << " ";
    q.pop();
    sorted.push_back(val);

    for (int node : adj[val])
    {
      indegree[node]--;
      if (indegree[node] == 0)
        q.push(node);
    }
  }

  // check for cycle if indegree[i]!=0 it means there was a cycle. Consider cycles of [1-><-2] and [1, 2-><-3] for understanding
  for (int i = 0; i < n; i++)
  {
    if (indegree[i])
    {
      cout << " NOT POSSIBLE as cycle detected";
      return;
    }
  }
  cout << "\n";
  for (int val : sorted)
    cout << val << " ";
}

int main()
{
  int n, m;
  cin >> n >> m; // m is edges
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  topo_sort(adj, n); // n max number of nodes
  return 0;
}

/*
5 5
0 1
0 2
1 3
2 3
3 4
*/