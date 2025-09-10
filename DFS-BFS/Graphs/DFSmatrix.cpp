#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
    int rows = grid.size(), cols = grid[0].size();

    // directions: up, down, left, right
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    visited[r][c] = true;
    cout << "Visiting (" << r << ", " << c << ") value=" << grid[r][c] << endl;

    for (auto [dr, dc] : directions) {
        int nr = r + dr, nc = c + dc;
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
            dfs(grid, nr, nc, visited);
        }
    }
}

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    dfs(grid, 0, 0, visited);
    return 0;
}
🔹 Python Implementation
python
Copy
Edit
def dfs(matrix, r, c, visited):
    rows, cols = len(matrix), len(matrix[0])
    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    visited.add((r, c))
    print(f"Visiting ({r}, {c}) value={matrix[r][c]}")

    for dr, dc in directions:
        nr, nc = r + dr, c + dc
        if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in visited:
            dfs(matrix, nr, nc, visited)

# Example
matrix = [[1,2,3],[4,5,6],[7,8,9]]
visited = set()
dfs(matrix, 0, 0, visited)
🔹 Java Implementation
java
Copy
Edit
public class MatrixDFS {
    public static void dfs(int[][] grid, int r, int c, boolean[][] visited) {
        int rows = grid.length, cols = grid[0].length;
        int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        visited[r][c] = true;
        System.out.println("Visiting (" + r + ", " + c + ") value=" + grid[r][c]);

        for (int[] dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                dfs(grid, nr, nc, visited);
            }
        }
    }

    public static void main(String[] args) {
        int[][] grid = {{1,2,3}, {4,5,6}, {7,8,9}};
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        dfs(grid, 0, 0, visited);
    }
}