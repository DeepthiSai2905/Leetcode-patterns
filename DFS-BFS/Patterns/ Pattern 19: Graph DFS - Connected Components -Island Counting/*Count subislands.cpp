#include<bits/stdc++.h>
using namespace std;
/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



*/
class Solution {
public:
    vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        //base
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return ;
        grid[i][j]=0;

        //logic
        for(auto [dx,dy]: direction){
            dfs(grid,i+dx,j+dy,m,n);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(); int n = grid1[0].size();
        // 1. if grid2 has 1 and grid1 has 0 => make grid2 as 0 (as we are checking islands in grid2)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid1[i][j]==0 && grid2[i][j]==1){
// if this particular cell is not present (its chunk also wont be a subisland)
                    dfs(grid2,i,j,m,n);  
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    count++;
                    dfs(grid2,i,j,m,n);
                }
            }
        }
       return count;
    }
};