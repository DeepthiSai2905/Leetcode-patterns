#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/maximal-square/

*/

int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){ // pivot
                   // square starts
                   int len=1;
                   bool squareFlag=true;
                   // falling on diagonal
                   while(i+len<m && j+len<n && squareFlag){
                     // go up from current node till pivot row - same column
                     for(int k=i+len;k>=i;k--){
                        if(matrix[k][j+len]!='1'){ // finds '0'
                           squareFlag=false;
                           break; // break the square formation
                        }
                     }
                     // go left from current node till pivot column - same row
                     for(int p=j+len;p>=j;p--){
                        if(matrix[i+len][p]!='1'){ // finds '0'
                           squareFlag=false;
                           break; // break the square formation
                        }
                     }

                     if(squareFlag) len++;

                   }

                   maxArea=max(maxArea, len*len);
                }
            }
        }
        return maxArea;
    }