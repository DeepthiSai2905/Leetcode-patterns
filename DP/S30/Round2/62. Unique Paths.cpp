#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/unique-paths/description/

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 
*/
// recursion time complexity: O(2^(m+n)) space complexity: O(m+n)
int helper(int r,int c,int m,int n){
    if(r==m-1 && c==n-1) return 1;
    if(r==m || c==n) return 0;
    return helper(r+1,c,m,n)+helper(r,c+1,m,n);
}
int uniquePaths(int m, int n) {
    return helper(0,0,m,n);
}

// dynamic programming tc: O(m*n) sc: O(m*n)
int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    // space optimisation tc: O(m*n) sc: O(n)
    int uniquePaths(int m, int n) {
        vector<int>curr(n,0);
        vector<int>prev(n,1);
        prev[0]=1, curr[0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
             // dp[i][j]=dp[i-1][j]+dp[i][j-1];
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    
    } 
