#include <iostream>
#include <vector>
#include <queue> // For queue

using namespace std;

void bfs(vector<vector<int>> graph, int start) {
	int n = graph.size();
    vector<bool> visited(n, false); // Track visited nodes
    queue<int> q; // Queue for BFS
    // Start from the given node
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Process the node (print it)
        // Traverse the adjacent nodes
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor); // Add to the queue
            }
        }
    }
}