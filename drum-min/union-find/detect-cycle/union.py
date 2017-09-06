from collections import defaultdict

class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)
        
    def find_parent(self, parent, x):
        if(parent[x] == -1):
            return x;
        return self.find_parent(parent, parent[x])
        
    def perform_union(self, parent, x, y):
        px = self.find_parent(parent, x)
        py = self.find_parent(parent, y)
        
        parent[px] = py
        
    def has_cycle(self):
        parent = [-1]*(self.V)
        
        for i in self.graph:
            for j in self.graph[i]:
                px = self.find_parent(parent, i)
                py = self.find_parent(parent, j)
                
                if(px == py):
                    return True
                
                self.perform_union(parent, px, py)
        return False        
                

g = Graph(3)

g.addEdge(0,1)
g.addEdge(1,2)
g.addEdge(2,1)

res = g.has_cycle()

print res                                       
