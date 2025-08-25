#include <bits/stdc++.h>
using namespace std;
/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

*/
vector<pair<int,int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 1. track cells with 0 value
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>Q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) Q.push({i,j});
                else mat[i][j]=INT_MAX;
            }
        }
        while(!Q.empty()){
            auto curr = Q.front(); Q.pop();
            int x=curr.first, y =curr.second;
            for(auto [dx,dy]: directions){
                int newX = dx+x;
                int newY = dy+y;
                if(isValid(newX,newY,m,n) && mat[newX][newY]!=0){
                    if(mat[newX][newY] > 1+mat[x][y]){
                        mat[newX][newY] = 1+mat[x][y];
                        Q.push({newX,newY});
                    }
                }
            }
        }
        return mat;
    }