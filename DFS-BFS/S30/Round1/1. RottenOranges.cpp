#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/rotting-oranges/description/
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/
int orangesRotting(vector<vector<int>>& grid) {
    int freshOranges = 0, time = 0;
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>>rottenOranges;
    
    vector<pair<int,int>>direction = {{0,1},{1,0},{-1,0},{0,-1}};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2)
                rottenOranges.push({i, j});
            else if(grid[i][j] == 1)
                freshOranges++;
        }
    }
    while(!rottenOranges.empty() && freshOranges>0){
        int size=rottenOranges.size();
        time++;
        while(size--){
            auto [x,y] = rottenOranges.front(); rottenOranges.pop();
            for(auto [dx,dy]: direction){
                int newX = dx+x;
                int newY = dy+y;
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                    // make it rotten and reduce fresh count
                    grid[newX][newY]=2;
                    rottenOranges.push({newX,newY});
                    freshOranges--;
                }
            }
        }
    }
    return freshOranges==0 ? time:-1; // important**
}