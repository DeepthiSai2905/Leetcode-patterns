#include<bits/stdc++.h>
using namespace std;
/*
refer notes
https://leetcode.com/problems/burst-balloons/   
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely. -> ORDER MATTERS       
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size(); // size*order dp
        vector<vector<int>>dp(n, vector<int>(n));
        
        // create 1-set, 2-set, 3-set, 4-set
        // length of burstable array
        for(int le=1 ;le<=n;le++){
            // i - start index of burstable array
            for(int i=0;i<=n-le;i++){
                int maxCoinsCollected=INT_MIN;
                int j=i+le-1;  // length of burstable array
                // we have burstable array - take each balloon and burst at end
                for(int k=i;k<=j;k++){
                    // calculate value
                    int beforeBustCoinsCollected=0, afterBustCoinsCollected=0;
                    if( k!=i){
                        beforeBustCoinsCollected=dp[i][k-1];
                    }
                    if(k!=j){
                        afterBustCoinsCollected=dp[k+1][j];
                    }
                    int leftNonBurstBalloon = i==0 ? 1 : nums[i-1];
                    int rightNonBurstBalloon = j==n-1 ? 1 : nums[j+1];
                    int coinsCollectedAtIndex = leftNonBurstBalloon*nums[k]*rightNonBurstBalloon;
                    int totalCoinsCollected = beforeBustCoinsCollected + coinsCollectedAtIndex + afterBustCoinsCollected;
                    maxCoinsCollected = max(maxCoinsCollected, totalCoinsCollected);
                }
                dp[i][j]=maxCoinsCollected;
            }

        }
        return dp[0][n-1];
    }
};