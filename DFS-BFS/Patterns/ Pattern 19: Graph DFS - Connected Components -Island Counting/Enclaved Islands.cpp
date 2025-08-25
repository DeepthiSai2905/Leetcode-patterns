#include<bits/stdc++.h>
using namespace std;
/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.



*/


/*
approach is
just eliminte the 1 chunk(dfs) connected to the boundary
and count rest of the 1s

*/
vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isBoundary(int i,int j,int m,int n){
        return (i==0 || i==m-1) || (j==0 || j==n-1);
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        // base
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1) return ;
        grid[i][j]=0; // make it zero
        for(auto [dx,dy]:direction){
            dfs(grid,i+dx,j+dy,m,n);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1 && isBoundary(i,j,m,n)){
                    // make that chunk 0
                    dfs(grid,i,j,m,n);
                }
            }
        }
        int count=0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // count all leftover ones in middle
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }