#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFSUtil(int s, bool visited[]);
    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
   adj[u].push_back(v); 
}

void Graph::DFSUtil(int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    
    for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); i++) {
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int s) {
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    DFSUtil(s, visited);    
}

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) n\n";
    g.DFS(2);
    cout << endl;

    return 0;
}
