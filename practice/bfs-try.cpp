#include <iostream>
#include "vector"
#include "queue"
using namespace std;

// N is the max number of vertices and we are creating N number of vectors named adj
const int N = 1e5 + 2;
bool vis[N] = {false};
vector<int> adj[N];

int main()
{
  int n, m;
  // number of nodes and edges
  cin >> n >> m;

  int x, y;
  // two variable for edge input x and y as edge b/w 2 edges
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    // making an undirected edge btw x and y
  }

  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    cout << u << " ";
    // for (int i : adj[u])
    // {
    //   q.push(i);
    // }
    vector<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
      // if vis[*i] has false then push *i as i is a pointer
      if (!vis[*i])
      {
        vis[*i] = true;
        q.push(*i);
      }
    }
  }
  // here we push 1 in queue at the start as we need a starting vertex for bfs
}

// bfs - go to a node in an adjacency list and then go through all it's predecessors and then store them in queue
// layer by layer