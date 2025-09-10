#include<bits/stdc++.h>
using namespace std;
/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

*/

/*
// 1. edge 0s and conected 0 chunks are waste, change it to 1s
// 2. count 0 chunks convert them to 1 -> in middle of board
*/
vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isBoundary(int i,int j,int m,int n){
        return (i==0 || i==m-1) || (j==0 || j==n-1);
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        //base
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=0) return ;
        grid[i][j]=1;

        //logic
        for(auto [dx,dy]: direction){
            dfs(grid,i+dx,j+dy,m,n);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        // 1. edge 0s and conected 0 chunks are waste, change it to 1s
        int m = grid.size(), n = grid[0].size();
        int countOfIslands=0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==0 && isBoundary(i,j,m,n)){
                    dfs(grid,i,j,m,n);
                }
            }
        }
        int count=0;
        // 2. count 0 chunks in middle of board
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }