V = 4
INF = 10000

def floydWarshall(graph):
    dist = graph

graph = [
    [0, 5, INF, 10],
    [INF, 0, 3, 4],
    [INF, INF, 0, 1],
    [INF, INF, INF, 0]
    ]
                
def floydWarshall(graph):                
    dist = graph

    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k])

    print "Sol:"
    printSolution(dist)
    
def printSolution(dist):
    for i in range (V):
        for j in range(V):
            if(dist[i][j] == INF):
                print "7%s" %("INF"),
            else:
                print "%7d\t" %(dist[i][j]),
            
            if j == V - 1:
                print ""                        
