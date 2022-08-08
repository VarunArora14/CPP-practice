#include<iostream>
#include<list>

using namespace std;

class graph
{
private:
    /* data */
    int V;  //No of vertices

    //Pointer to the array containing adjacency lists
    list<int> *adj;
    void dfsutil(int a , bool visit[]);
public:
    graph(int v);
    void addedge(int a , int b);
    void dfs(int a);
    // ~graph();
};

graph::graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}

void graph::addedge(int a , int b)
{
    adj[a].push_back(b);
    // push back the b so that 0->1 link is made in adjacency list
}

// void graph::bfs(int a)
// {
//     bool *visit = new bool[V];
//     //marks all visited vertices as true to avoid repetition
//     for(int i=0;i<V;i++)
//     {
//         visit[i]=false;
//     }

//     list<int> queue;
//     //queue for bfs

//     visit[a] = true;
//     queue.push_back(a);

//     //now we have inserted a new vertex for which we have to find all the connec ted vertices
//     //and thn add them to the queue 

//     list<int>::iterator i;

//     while (!queue.empty())
//     {
//         /* code */
//         //dequeue vertex from queue and then print it
//         a=queue.front();
//         cout<<a<<" ";
//         queue.pop_front();

//         for(i=adj[a].begin();i!=adj[a].end();i++)
//         {
//             if(!visit[*i])
//             {
//                 visit[*i]=true;
//                 queue.push_back(*i);
//             }
//         }
//     }
    
// }


void graph::dfsutil(int a , bool visit[])
{

    visit[a] = true;
    cout<<a<<" ";

    //recur all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i=adj[a].begin();i!=adj[a].end();i++)
    {
        if(!visit[*i])
        {
            dfsutil(*i,visit);
        }
    }

}

void graph::dfs(int a)
{
    bool *visit = new bool[V];
    //need to initialise with visit as dynamic allocation as size of visit array not fixed
    //which will be decided only when an object is created of class graph. Since arrays have
    //static allocation but with variables, we must declare them dynamically 
    //This is dynamic allocation, not pointer array
    for(int i=0;i<V;i++)
    {
        visit[i] =false;

    }

    dfsutil(a,visit);
   

}

int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(3,4);
    g.addedge(3,0);
    g.addedge(4,1);
    g.dfs(4);
}

// [0]->1->2
// [1]->3
// [2]->2
// [3]->4->0
// [4]->1