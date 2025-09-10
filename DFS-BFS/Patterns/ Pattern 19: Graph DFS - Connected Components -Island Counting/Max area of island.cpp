#include<bits/stdc++.h>
using namespace std;
/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
*/

/* just find the max size of 1 chunks out of all possiable 1 chunks */
vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,int &ans){
    //base
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return ;
    ans++;
    grid[i][j]=0;

    //logic
    for(auto [dx,dy]: direction){
        dfs(grid,i+dx,j+dy,m,n,ans);
    } 
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int maxArea=0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int ans = 0;
            if(grid[i][j]==1){
                dfs(grid,i,j,m,n,ans);
                maxArea=max(ans,maxArea);
            }
        }
    }
    return maxArea;
}