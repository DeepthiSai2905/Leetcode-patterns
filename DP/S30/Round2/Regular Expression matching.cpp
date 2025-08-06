#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/regular-expression-matching/

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

bool isMatch(string s, string p) {
    int m=s.length();
    int n=p.length();
    vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true; //empty string
    for(int j=1;j<=n;j++){
        if(p[j-1]=='*'){
            // go 2 steps back
            dp[0][j]=dp[0][j-2];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                // 0 1
                // 0 1 case - curr char at src == prev char of * in p
                if(s[i-1]==p[j-2] || p[j-2]=='.'){ 
                    dp[i][j]=dp[i-1][j] || dp[i][j-2];
                }
                // 0 caseis always available and will 2 steps back
                else  dp[i][j]=dp[i][j-2]; // only 0 case
            }
            else{ // character
                // check if they match
                if(p[j-1]==s[i-1] || p[j-1]=='.'){ 
                /* if . no need to match as it can 
                match with any character(considered matched) */
                // matched - left diag
                    dp[i][j]=dp[i-1][j-1];
                }
                else{ // this is not required -> by default false;
                    dp[i][j]=false;
                }

            }
        }
    }
    return dp[m][n];
    
}

// space optimized solution
bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<bool>dp(n+1);
        dp[0]=true; //empty string
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                // go 2 steps back
                dp[j]=dp[j-2];
            }
        }
        for(int i=1;i<=m;i++){ 
            bool diagUp=dp[0];
            dp[0]=false;
            for(int j=1;j<=n;j++){
                bool temp=dp[j];
                if(p[j-1]=='*'){
                    // 0 1
                    // 0 1 case - curr char at src == prev char of * in p
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){ 
                        //dp[i][j]=dp[i-1][j] || dp[i][j-2];
                        dp[j]=dp[j] || dp[j-2];
                    }
                    // 0 caseis always available and will 2 steps back
                    // else  dp[i][j]=dp[i][j-2]; // only 0 case
                    else dp[j]=dp[j-2];
                }
                else{ // character
                   // check if they match
                   if(p[j-1]==s[i-1] || p[j-1]=='.'){ 
                    /* if . no need to match as it can 
                    match with any character(considered matched) */
                    // matched - left diag
                      dp[j]=diagUp;
                   }else{
                    dp[j]=false;
                   }
                }

                diagUp=temp;
            }
        }
        return dp[n];
        
    }