#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
//    adj[v].push_back(u);
}

void Graph::BFS(int src) {
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(src);
    visited[src] = 1;
   
    list<int>::iterator i;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(i = adj[node].begin(); i != adj[node].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = 1;
                q.push(*i);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.BFS(2);
    cout << endl;
}
