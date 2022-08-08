#include<iostream>
#include<list>

using namespace std;

class graph
{
private:
    /* data */
    int V;
    //V is for vertices

    list<int> *adj;
public:
    graph(int v);
    void addedge(int v,int w);
    //addedge() to add new edges to the graph

    void bfs(int s);

    ~graph()
    {
        cout<<"memory deallocated";
    }
};

graph::graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}

void graph::addedge(int v , int w)
{
    adj[v].push_back(w);
    //creating an adjacency list and 


}

void graph::bfs(int a)
{
    bool *visit = new bool[V];
    for(int i=0;i<V;i++)
    {
        visit[i] = false;
        //all the indices marked false
    }

    // create queue for bfs
    list<int> queue;

    //mark the current node as visited and then enqueue it
    visit[a] = true;
    queue.push_back(a);

    //'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        a=queue.front();
        cout<<a<<" ";
        queue.pop_front();
        for(i=adj[a].begin();i!=adj[a].end();i++)
        {
            if(!visit[*i])
            {
                queue.push_back(*i);
                visit[*i]=true;
            }
        }
    }
}

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.bfs(2); 
  
    return 0; 
}