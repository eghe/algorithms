import java.util.*;

public class Graph {
    private int V;
    private LinkedList<Integer> adj[];

    public Graph(int V) {
        this.V = V;
        adj = new LinkedList[V];

        for(int i = 0; i < V; i++) {
            adj[i] = new LinkedList();
        }
    }

    public void addEdge(int u, int v) {
        adj[u].add(v);
    }

    public void DFSUtil(int s, boolean visited[]) {
        visited[s] = true;
        System.out.print(s + " ");

        Iterator<Integer> i = adj[s].listIterator();
        while(i.hasNext()) {
            int node = i.next();
            if(!visited[node])
                DFSUtil(node, visited);
        }
    }

    public void DFS(int s) {
        // set by default to false
        boolean visited[] = new boolean[V];

        DFSUtil(s, visited);
    }

    public static void main(String args[]) {
        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is Depth First Traversal");

        g.DFS(2);
    }
}

