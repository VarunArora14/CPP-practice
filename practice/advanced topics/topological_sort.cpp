// https://www.scaler.com/topics/data-structures/topological-sort-algorithm/
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

void top_sort(vi adj[N], int n)
{
  vi indegree(n, 0);
  vi sorted(n, 0);
  for (int i = 0; i < n; i++)
  {
    // go through it's adjancency list nodes
    for (auto j : adj[i])
    {
      // increase their indegree
      indegree[j]++;
    }
  }

  queue<int> zero_q;
  // now push ele in queue where indegree[j]==0
  for (int node = 0; node < n; node++)
  {
    if (indegree[node] == 0)
    {
      zero_q.push(node);
    }
  }

  // have a count for visited nodes to see if over
  int vis = 0;
  while (!zero_q.empty())
  {
    // take node with indegree 0 and push into the queu
    int front = zero_q.front();
    zero_q.pop();
    sorted.push_back(front);
    vis++;

    // go to it's nbrs and decrease their indegree as we removed the node from the graph named front which pointed towards them
    for (int nbr : adj[front])
    {
      indegree[nbr]--; // decrease the nbr indegree as we removed one ele which pointed to them in graph
      if (indegree[nbr] == 0)
      {
        zero_q.push(nbr); // if nbr has 0 indegree after reducing then push that also
      }
    }
  }

  // outside the while loop check if number of visited nodes same as total
  if (vis != n)
    cout << "cycle found";
  else
  {
    for (int val : sorted)
      cout << val << " ";
  }
}

const int N = 1e5 + 5;
int main()
{
  int n, m;
  cin >> n >> m; // for nodes and m for edges
  vi adj[N];     // N adjacency lists where N nodes
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // directed graph
  }
  // calculate the indegree before sort

  return 0;
}

/*
firse create an adjacency list, then create indegree vector to calc the indegree of each node where you do indegree[nbr]++ for node having nbrs.
Push all nodes with 0 indegree in queue bcos of first in first out property of queue.

Then, for each node in zero_q, pop the last ele and check all it's neighbours while decreasing their indegree and if thei indegree is 0 then push them also
in zero_q
*/