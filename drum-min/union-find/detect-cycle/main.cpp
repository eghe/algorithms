#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Edge {
    int src, dst;
};

struct Graph {
    int V, E;

    struct Edge *edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph *g = (struct Graph*) malloc (sizeof(struct Graph));

    g->E = E;
    g->V = V;
    
    struct Edge *e = (struct Edge*) malloc (E * sizeof(struct Edge));
    g->edge = e;

    return g;
}

int getParent(int *parent, int x) {
    if(parent[x] == -1) return x;
    return getParent(parent, parent[x]);
}

void unionData(int *parent, int x, int y) {
    int px = getParent(parent, x);
    int py = getParent(parent, y);

    parent[px] = py;
}

int hasCycle(struct Graph *graph) {
    int *parent = (int*) malloc (graph->V * sizeof(int));
    memset(parent, -1, sizeof(int) * graph->V);

    for(int i = 0; i < graph->E; i++) {
        int px = getParent(parent, graph->edge[i].src);
        int py = getParent(parent, graph->edge[i].dst);

        if(px == py) return 1;

        unionData(parent, graph->edge[i].src, graph->edge[i].dst);
    }
    return 0;
}


int main() {
    int V = 3, E = 3;
    struct Graph *graph = createGraph(V, E);
    
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dst = 2;

    graph->edge[2].src = 2;
    graph->edge[2].dst = 1;

    int res = hasCycle(graph);
    cout << "Has cycle: " << res << endl;

    return 0;
}
