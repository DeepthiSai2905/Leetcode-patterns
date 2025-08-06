#include<bits/stdc++.h>
using namespace std;
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/
int minDistanceRec(string word1, string word2, int m, int n) {
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++) dp[i][0]=i;
    for(int j=0;j<=n;j++) dp[0][j]=j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    } 
    return dp[m][n];
}
int minDistance(string word1, string word2) {
    int m=word1.length();
    int n=word2.length();
    return minDistanceRec(word1,word2,m,n);
}

// Space optimized solution for Edit Distance - using prev and curr
int minDistanceRec(string word1, string word2, int m, int n) {
    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);
    for (int j = 0; j <= n; j++) prev[j] = j;
    for(int i=1;i<=m;i++){
        curr[0] = i;  // This corresponds to dp[i][0] (deleting all characters from word1)
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
            }
        }
        prev=curr;
    }
    return prev[n];
}
int minDistance(string word1, string word2) {
    int m=word1.length();
    int n=word2.length();
    return minDistanceRec(word1,word2,m,n);
}

// Space optimized solution for Edit Distance - using single vector
vector<int> dp(n+1, 0); // prev row, now reused for curr row as well
for (int j = 0; j <= n; j++) dp[j] = j; // base case: word1 = ""

for (int i = 1; i <= m; i++) {
    int diagUp = dp[0]; // dp[i-1][0]
    dp[0] = i; // base case: word2 = ""
    
    for (int j = 1; j <= n; j++) {
        int temp = dp[j]; // store current dp[j] (which is dp[i-1][j])
        if (word1[i-1] == word2[j-1]) {
            dp[j] = diagUp; // characters match → no op
        } else {
            dp[j] = 1 + min(diagUp, min(dp[j], dp[j-1]));
        }
        diagUp = temp; // move diagUp to dp[i-1][j] for next j
    }
}