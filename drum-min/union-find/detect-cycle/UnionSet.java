import java.util.*;

class Graph {
    int V, E;
    Edge edge[];
    
    class Edge {
        int src, dst;
    }

    Graph(int V, int E) {
        this.V = V;
        this.E = E;

        edge = new Edge[E];
        for(int i = 0; i < E; i++)
            edge[i] = new Edge();
    }

    void setEdges() {
        edge[0].src = 0;
        edge[0].dst = 1;

        edge[1].src = 1;
        edge[1].dst = 2;

        edge[2].src = 2;
        edge[2].dst = 0;
    }

    int getV() {return V;}
    int getE() {return E;}

    int getSrc(int x) {
        return edge[x].src;
    }
    
    int getDst(int x) {
        return edge[x].dst;
    }
}

public class UnionSet {
    
    int getParent(int[] parent, int x) {
        if(parent[x] == -1) return x;
        return getParent(parent, parent[x]);
    }

    void performUnion(int[] parent, int x, int y) {
        int px = getParent(parent, x);
        int py = getParent(parent, y);

        parent[px] = py;
    }

    int hasCycle(Graph g) {
        int[] parent = new int[g.getV()];
        for(int i = 0; i < g.getV(); i++)
            parent[i] = -1;

        for(int i = 0; i < g.getE(); i++) {
            int px = getParent(parent, g.getSrc(i)); 
            int py = getParent(parent, g.getDst(i)); 

            if(px == py) return 1;

            performUnion(parent, px, py);
        }

        return 0;
    }

    public static void main(String[] args) {
        UnionSet u = new UnionSet();
        Graph g = new Graph(3, 3);

        int res = u.hasCycle(g);

        System.out.println(res);
    }
}
