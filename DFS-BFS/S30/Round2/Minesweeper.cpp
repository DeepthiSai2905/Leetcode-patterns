#include<stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/minesweeper/description/
Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
 

Example 1:


Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
*/
// BFS - TC-O(m*n), SC-O(m*n)
vector<vector<int>>dirs = {{1,0},{1,1},{0,1},{-1,1}, {-1,0},{-1,-1},{0,-1},{1,-1}};
    bool isValid(int x,int y, int m,int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int countMines(vector<vector<char>>& board, int x, int y,int m,int n){
        int mines=0;
        for(auto d: dirs){
            int newX = d[0]+x;
            int newY = d[1]+y; 
            if(isValid(newX,newY,m,n) && board[newX][newY]=='M') mines++;
        }
        return mines;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(), n=board[0].size();
        int clickx=click[0],clicky=click[1];
        if(board[clickx][clicky]=='M'){ // initial click is mine
            board[clickx][clicky]='X'; // reveal it
            return board;
        }
        queue<pair<int,int>>Q;
        Q.push({clickx,clicky});
        board[clickx][clicky]='B';
        while(!Q.empty()){
            auto curr = Q.front(); Q.pop();
            int x = curr.first, y = curr.second;
            
           // check for mines around all sides
            int mines=countMines(board, x, y,m,n);
            if(mines>0) {
                board[x][y]=mines+'0';
                continue;
            }
            // no mines then only explore neighbors
            for(auto d: dirs){
                int newX = x+d[0];
                int newY = y+d[1]; 
                if(isValid(newX,newY,m,n) && board[newX][newY]=='E') {
                    // make it B and push into Q
                    board[newX][newY]='B'; // make it visited
                    Q.push({newX,newY});
                }
            }
            
        }
        return board;
    }


// DFS - TC-O(m*n), SC-O(m*n)
class Solution {
public:
    vector<vector<int>>dirs = {{1,0},{1,1},{0,1},{-1,1}, {-1,0},{-1,-1},{0,-1},{1,-1}};
    bool isValid(int x,int y, int m,int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int countMines(vector<vector<char>>& board, int x, int y,int m,int n){
        int mines=0;
        for(auto d: dirs){
            int newX = d[0]+x;
            int newY = d[1]+y; 
            if(isValid(newX,newY,m,n) && board[newX][newY]=='M') mines++;
        }
        return mines;
    }
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n){
        // base
        if(!isValid(x,y,m,n) || board[x][y]!='E') return ;

        //logic
        board[x][y]='B';
        int mines = countMines(board, x, y,m,n);
        if(mines>0) {
            board[x][y]=mines+'0';
            return ;
        }
        // no mines then only explore neighbors
        for(auto d: dirs){
            int newX = x+d[0];
            int newY = y+d[1];
            dfs(board,newX,newY,m,n);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(), n=board[0].size();
        int clickx=click[0],clicky=click[1];
        if(board[clickx][clicky]=='M'){ // initial click is mine
            board[clickx][clicky]='X'; // reveal it
            return board;
        }

        dfs(board, clickx, clicky,m,n);
        return board;
    }
};