#include <iostream>
#include <stack>
#include <cstring> // For memset

using namespace std;

bool canEatFoodRecursion(int maze[5][5], int x, int y, int fx, int fy, bool visited[5][5]){
    /*TODO*/
    if(x == fx && y == fy){
        return true;
    }
    visited[x][y]= true; // Mark the current cell as visited
    // Directions for moving in the maze (up, down, left, right)
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    for(int i =0; i < 4; ++i){
        // Check all four possible directions
        int newX = x + dx[i]; // Calculate new position
        int newY = y + dy[i]; // Calculate new position
        if(newX >= 0 && newX < 5 && newY >= 0 && newY < 5 && maze[newX][newY] == 1 && !visited[newX][newY]){ // Check if the new position is valid and not visited
            if(canEatFoodRecursion(maze, newX, newY, fx, fy, visited)){
                return true;
            }
        }
    }
    return false;
}
bool canEatFood(int maze[5][5], int fx, int fy){
    bool visited[5][5] = {false};
    bool canGo = canEatFoodRecursion(maze,0,0,fx,fy,visited);
    return canGo;
}