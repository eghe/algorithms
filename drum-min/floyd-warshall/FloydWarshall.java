import java.util.*;

class FloydWarshall {
    final static private int V = 4, INF = 10000;

    void floydWarshal(int graph[][]) {
        int d[][] = new int[V][V];
        
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++) {
                d[i][j] = graph[i][j];
            }
        
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                for(int k = 0; k < V; k++)
                    if(d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
        
        printSolution(d);                
    }

    public void printSolution(int dist[][]) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++)
                if(dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");    
            System.out.println();       
        }
    }

    public static void main(String args[]) {
        int graph[][] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
        };

        FloydWarshall a = new FloydWarshall();
        a.floydWarshal(graph);
    }
}
