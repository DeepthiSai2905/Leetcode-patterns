#include<bits/stdc++.h>
using namespace std;
/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 
horizal and vertical only not diagonal
Example 1:
xxxx
xxox
xoox
xoxx 
output should be:  as the chunk is connected to the edge, it is not surrounded
xxxx
xxox
xoox
xoxx    

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

Here protect edge connected Os with P, then change all O to X and 
later all dfs change P to O (protected) and O to X (unprotected -> surrounded), 

in simple terms,
protect all 0s connected to edge like make it P
then at last change all Ps to Os and Os to Xs 
*/

vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
bool isBoundary(int i,int j,int m,int n){
    return (i==0 || i==m-1) || (j==0 || j==n-1);
}
void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
    //base
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='O') return ;
    grid[i][j]='P';

    //logic
    for(auto [dx,dy]: direction){
        dfs(grid,i+dx,j+dy,m,n);
    }
}
void solve(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // protect my boundary Os
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='O' && isBoundary(i,j,m,n)){
                dfs(grid,i,j,m,n);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='P'){
                grid[i][j]='O';
            }
            else if(grid[i][j]=='O'){
                    grid[i][j]='X';
            }
        }
    }
}