#include <iostream>
#include <vector>
#include <queue> // For queue

using namespace std;

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    // Step 1: Add all rotten apples to the queue and count fresh apples
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0; // No fresh apples to rot
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int time = 0;
    // Step 2: BFS to rot all fresh apples
    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;
        for (int i = 0; i < size; ++i) {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            for (auto& dir : dirs) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Rot the fresh apple
                    q.push({newX, newY});
                    fresh--;
                    rotted = true;
                }
            }
        }
        if (rotted) time++;
    }
    return fresh == 0 ? time : -1; // Return time if all apples are rotten, else -1
}