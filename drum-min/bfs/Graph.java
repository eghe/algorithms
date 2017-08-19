import java.io.*;
import java.util.*;

public class Graph {
    private int V;
    private LinkedList<Integer> adj[];

    Graph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for(int i = 0; i < V; i++) {
            adj[i] = new LinkedList();
        }
    }

    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    void BFS(int src) {
        // by default set a false
        boolean visited[] = new boolean[V];
        Queue<Integer> q = new LinkedList();
        q.add(src);
        visited[src] = true;

        while(q.size() != 0) {
            int node = q.poll();
            System.out.print(node + " ");

            Iterator<Integer> i = adj[node].listIterator();
            while(i.hasNext()) {
                int n = i.next();
                if(!visited[n]) {
                    visited[n] = true;
                    q.add(n);
                }
            }
        }
    }

    public static void main(String args[]) {
        Graph g = new Graph(4);
 
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
 
        System.out.println("Following is Breadth First Traversal "+
                           "(starting from vertex 2)");
 
        g.BFS(2);
    }
}
