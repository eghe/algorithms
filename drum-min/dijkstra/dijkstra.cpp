#include <iostream>
#include <vector>
#include <list>
#include <queue>   // priority_queue
#include <utility> // std::pair
#include <iostream>

#define INF 100000

using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V; // number of edges
    list< iPair > *adj;

public:
    Graph(int V);
    
    void addEdge(int u, int v, int w);

    void shortestPath(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list< iPair >[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));    
    adj[v].push_back(make_pair(u, w));    
}

void Graph::shortestPath(int src) {
    vector<int> d(V, INF);
    vector<int> p(V, 0);
    priority_queue< iPair, vector< iPair >, greater< iPair > > q;

    q.push(make_pair(0, src));
    d[src] = 0;
    while(!q.empty()) {
       pair<int, int> pp = q.top();
       q.pop();
       int node = pp.second;

       list< iPair >::iterator it;

       for(it = adj[node].begin(); it != adj[node].end(); it++) {
            int tNode = (*it).first;
            int tWeight = (*it).second;

            if(d[tNode] > d[node] + tWeight) {
                d[tNode] = d[node] + tWeight;
                p[tNode] = node;
                q.push(make_pair(d[tNode], tNode));
            }
       }
    }

    cout << "Dist to each vertex" << endl;
    for(int i = 0; i < V; i++) {
        cout << "Node: " << i << " dist: " << d[i] << endl;
    }
}

int main() {
    int V;
    cin >> V;
    
    Graph g(V);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    
    g.shortestPath(0);
}
