// BFS in matrix in terms of graph, how do we write BFS for it?

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& grid, int startRow, int startCol) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int,int>> q;

    // directions: up, down, left, right
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        cout << "Visiting (" << r << ", " << c << ") value=" << grid[r][c] << endl;

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    bfs(grid, 0, 0);
    return 0;
}

// 🔹 Python Implementation
// from collections import deque

def bfs(matrix, start):
    rows, cols = len(matrix), len(matrix[0])
    directions = [(1,0), (-1,0), (0,1), (0,-1)]
    
    visited = set([start])
    q = deque([start])
    
    while q:
        r, c = q.popleft()
        print(f"Visiting ({r}, {c}) value={matrix[r][c]}")
        
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in visited:
                visited.add((nr, nc))
                q.append((nr, nc))

# Example
matrix = [[1,2,3],[4,5,6],[7,8,9]]
bfs(matrix, (0,0))

// 🔹 Java Implementation
// import java.util.*;

public class MatrixBFS {
    public static void bfs(int[][] grid, int startRow, int startCol) {
        int rows = grid.length, cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        
        Queue<int[]> q = new LinkedList<>();
        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        q.add(new int[]{startRow, startCol});
        visited[startRow][startCol] = true;
        
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0], c = cell[1];
            
            System.out.println("Visiting (" + r + ", " + c + ") value=" + grid[r][c]);
            
            for (int[] dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.add(new int[]{nr, nc});
                }
            }
        }
    }

    public static void main(String[] args) {
        int[][] grid = {{1,2,3}, {4,5,6}, {7,8,9}};
        bfs(grid, 0, 0);
    }
}