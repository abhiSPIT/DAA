#include <stdio.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Set initial distances to infinity
        visited[i] = false; // Mark all vertices as not visited
    }
    dist[source] = 0; // Set distance of source vertex to 0

    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited); // Choose the vertex with minimum distance
        visited[u] = true; // Mark the chosen vertex as visited

        for (int v = 0; v < V; v++) {
            // Update distance[v] only if it is not visited, there is an edge from u to v,
            // and the total weight of path from source to v through u is smaller than current distance[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {{0, 4, 0, 0, 0, 0},
                       {4, 0, 8, 0, 0, 0},
                       {0, 8, 0, 7, 0, 4},
                       {0, 0, 7, 0, 9, 14},
                       {0, 0, 0, 9, 0, 10},
                       {0, 0, 4, 14, 10, 0}};

    dijkstra(graph, 0);

    return 0;
}
