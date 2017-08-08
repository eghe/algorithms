#include <iostream>

#define INF 100000

#define V 100

using namespace std;

int distMin(int dist[V], int visited[V], int n) {
    int d = INF;
    int node;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && d > dist[i]) {
            d = dist[i];
            node = i;
        }
    }
    return node;
}

void shortestPath(int a[V][V], int s, int n) {
    int d[100];
    int visited[100];

    for(int i = 0; i < n; i++) {
        d[i] = INF;
        visited[i] = 0;   
    }

    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int node = distMin(d, visited, n);
        visited[node] = 1;

        for(int j = 0; j < n; j++) {
            if(j != node && !visited[j] && a[node][j] && 
                d[j] > d[node] + a[node][j]) {
                d[j] = d[node] + a[node][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << "Node: " << i << " " << d[i] << endl;
    }
}

int main() {
    int n;
    int a[V][V];

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    shortestPath(a, 0, n);
}
