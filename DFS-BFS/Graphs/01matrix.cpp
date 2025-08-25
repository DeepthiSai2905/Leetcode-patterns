/*

1. Direction Array

For 4-directional traversal (up, down, left, right):

int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};


For 8-directional traversal (including diagonals):

int dirs[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

// to optimise space, instead of visited array, we can mark the grid itself as 0 or 2 based on the problem requirements
If the grid can be modified, we can mark it as 0
// If the grid cannot be modified, we can use a separate visited array or replace with 2 and then restore it later.
*/
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j] = 2; // mark visited

    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();

        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1) {
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
}

//3. Applying to DFS (C++ example)
void dfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    if (x<0 || x>=m || y<0 || y>=n || grid[x][y]!=1) return;

    grid[x][y] = 2; // mark visited
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (auto& d : dirs) {
        dfs(grid, x+d[0], y+d[1]);
    }
}