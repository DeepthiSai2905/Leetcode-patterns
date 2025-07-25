#include<stdc++.h>
using namespace std;
/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
*/
// BFS
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m=maze.size();
        int n=maze[0].size();
        queue<vector<int>>Q;
        Q.push(start);
        maze[start[0]][start[1]]=2; //mark it visited
        vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        while(!Q.empty()){
            /* minimum number of stopping points (keep track of size in that case)
             similar to courses can be taken or not (size - number of semesters)
            */
            vector<int>curr = Q.front(); Q.pop();
            for(auto dir: dirs){
                //stopping point - if neigh=0 continue in the direction untill you find 1
                int r=curr[0]; int c=curr[1];
                while(r>=0 && r<m && c>=0 && c<n && maze[r][c]!=1){ // m*n(4 directions until hitting wall)
                  r+=dir[0]; c+=dir[1];
                }
                // when it stops, check if we shd keep in queue/not 
                
                r-=dir[0]; c-=dir[1]; // going 1 step ahead
                if(r==destination[0] && c==destination[1]) return true;
                if(maze[r][c]!=2){
                    Q.push({r,c});
                    maze[r][c]=2;
                }
            }
        }
        return false;
    }
};
// tc - o(4*m*n)(4 directions until hitting wall) sc - o(m*n)