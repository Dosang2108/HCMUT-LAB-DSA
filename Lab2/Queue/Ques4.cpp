#include <iostream>
#include <vector>
#include <queue> // For queue

using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color(n, -1); // -1 indicates uncolored
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) { // If not colored, start BFS
            queue<int> q;
            q.push(start);
            color[start] = 0; // Color the starting node with 0
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                // Check all adjacent nodes
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) { // If neighbor is uncolored
                        // Color it with the opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        // If the neighbor has the same color, it's not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true; // Graph is bipartite
}