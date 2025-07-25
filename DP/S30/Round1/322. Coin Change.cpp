#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/coin-change/description/
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


*/

// approach 1: recursion
int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) {
        // Base case: can only use coins[0]
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9; // impossible
    }
    if (dp[i][amount] != -1) return dp[i][amount];

    int notTake = helper(i - 1, amount, coins, dp);
    int take = 1e9;
    if (coins[i] <= amount){
        int value = helper(i, amount - coins[i], coins, dp);
        if (value != 1e9){ // only take if it's possible
           take = 1 + value;
        }
    }

    return dp[i][amount] = min(take, notTake);
}

// approach 2: dp top-down
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n][amount+1];
        // take first coin and check for amount
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                // no take
                int notake=dp[i-1][j];
                // take
                int take=INT_MAX;
                // here dp[i][j-coins[i]] can be INT_MAX
                if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,notake);
            }
        }
        return dp[n-1][amount] == INT_MAX ? -1: dp[n-1][amount];
}

// approach 3: space optimized dp
int coinChange(vector<int>& coins, int amount) {
        // space optimisation 
        int n=coins.size();
        // int dp[n][amount+1];
        vector<int>curr(amount+1);
        vector<int>prev(amount+1);
        // take first coin and check for amount
        for(int j=0;j<=amount;j++){
            /*if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=INT_MAX;*/
             if(j%coins[0]==0) prev[j]=j/coins[0];
            else prev[j]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                // no take
                // int notake=dp[i-1][j];
                int notake=prev[j];
                // take
                int take=INT_MAX;
                // here dp[i][j-coins[i]] can be INT_MAX
                // if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX) take=1+dp[i][j-coins[i]];
                if(coins[i]<=j && curr[j-coins[i]]!=INT_MAX) take=1+curr[j-coins[i]];
                // dp[i][j]=min(take,notake);
                curr[j]=min(take,notake);
            }
            prev=curr;
        }
        // return dp[n-1][amount] == INT_MAX ? -1: dp[n-1][amount];
        return prev[amount] == INT_MAX ? -1: prev[amount];
    }