#include<bits/stdc++.h>
using namespace std;
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
    //base
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return ;
    grid[i][j]='0';

    //logic
    for(auto [dx,dy]: direction){
        dfs(grid,i+dx,j+dy,m,n);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int countOfIslands=0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='1'){
                countOfIslands++;
                dfs(grid,i,j,m,n);
            }
        }
    }
    return countOfIslands;
}