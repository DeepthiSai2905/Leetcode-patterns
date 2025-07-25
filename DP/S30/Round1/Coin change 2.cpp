#include<bits/stdc++.h>
using namespace std;
/*
Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1

*/

int change(int amount, vector<int>& coins) {
        // // space optimisation 
        int n=coins.size();
        vector<unsigned long long>curr(amount+1);
        vector<unsigned long long>prev(amount+1,0);
        // take first coin and check for amount
        prev[0]=1;
        for(int i=0;i<n;i++){
            curr[0]=1;
            for(int j=coins[i];j<=amount;j++){
                curr[j]= prev[j] + curr[j-coins[i]];
            }
            prev=curr;
        }
        return prev[amount];  
    }

int change(int amount, vector<int>& coins) {
        // // space optimisation 
        int n=coins.size();
        // int dp[n][amount+1];
        vector<unsigned long long>dp(amount+1);
        // take first coin and check for amount
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]= dp[j] + dp[j-coins[i]];
            }
        }
        return dp[amount];  
    }

