#include <iostream>
#include "map"
#include "list"
using namespace std;

const int N = 1e5 + 5;
class Graph
{
  void dfsUtil(int);

public:
  map<int, list<int>> adj;
  map<int, bool> vis;
  void addEdge(int, int);
  void dfs();
};

void Graph::addEdge(int u, int v)
{
  // here it takes psuh back operation bcos of list and not that it has insert operation named push_back
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::dfs()
{
  // go through each vertex in a for loop
  for (auto i : adj)
  {
    // check if the value of vertex's vis map has false value or not
    if (vis[i.first] == false)
    {
      dfsUtil(i.first);
    }
  }
}

void Graph::dfsUtil(int v)
{
  vis[v] = true;
  cout << v << " ";
  for (int i : adj[v])
  {
    if (!vis[i])
    {
      dfsUtil(i);
    }
  }
}

int main()
{

  return 0;
}