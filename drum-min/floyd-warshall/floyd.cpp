#include <iostream>
#include <cstdlib>

#define INF 100000

using namespace std;

void floyd(int **a,int **d, int V) {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            for(int k = 0; k < V; k++) {
                int dist = d[k][j] + d[i][k];
                if(d[i][j] > dist)
                    d[i][j] = dist;
            }
        }
    }
}

int main() {
    int V;
    int **a = (int**)malloc(V * sizeof(int*));
    int **b = (int**)malloc(V * sizeof(int*));
    
    cin >> V;
    for(int i = 0; i < V; i++) {
        a[i] = (int*)malloc(V * sizeof(int)); 
        b[i] = (int*)malloc(V * sizeof(int)); 
    }

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                a[i][j] = INF;
            }
            if(i == j) {
                a[i][j] = 0;
            }
            b[i][j] = a[i][j];
        }

    floyd(a, b, V);    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
