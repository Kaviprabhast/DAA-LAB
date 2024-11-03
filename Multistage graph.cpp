#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int a[7][7]; 
    int dist[7];  
    cout << "Enter the adjacency matrix (use " << INF << " for no direct edge):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    int target = n - 1; 
    dist[target] = 0; 
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != INF) {
                dist[i] = min(dist[i], a[i][j] + dist[j]);
            }
        }
    }

    cout << "Minimum distances from each vertex to the target vertex:" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": Unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}