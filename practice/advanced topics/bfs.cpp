#include <iostream>
#include "vector"
#include "queue"
using namespace std;

// create them as global to be accessible by all
const int N = 1e5 + 5;
// max number of edges can be 1e5+4
vector<int> adj[N], dist;
// max N vertices
bool vis[N] = {false};
// all false as at start no vertex found

// starting vertex v
void bfs(int v, int n)
{
  queue<int> q;
  dist.assign(n + 1, -1);
  // assigning all the distances as -1 at start for the levels
  q.push(v);
  vis[v] = true;
  dist[v] = 0;
  // starting vertex has distance 0
  while (!q.empty())
  {
    int val = q.front();
    q.pop();
    cout << val << " ";
    for (int i : adj[val])
    {
      if (!vis[i])
      // we can change the if statement as if(dis[i]==-1)
      {
        vis[i] = true;
        dist[i] = dist[val] + 1;
        // cout << i << " ";
        q.push(i);
      }
    }
  }
  cout << "\n";
  for (int i = 1; i < 8; i++)
  {
    cout << dist[i] << " ";
  }
}

int main()
{

  // vertices n and edges m
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    // input 2 edges and mark them as their neighbours
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // call the bfs function with 1 node u know is present
  bfs(1, n);
  return 0;
}

/*
7 7
1 2
1 3
2 4
2 5
2 6
4 7
7 3

Here for last test case we have 7 3 meaning it has put 7 on the adjacency list of 3, if we remove that then the distance of 7 is 3
as 1->2 is 1, 2->4 is 2 and 4->7 is 3
*/