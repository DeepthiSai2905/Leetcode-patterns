#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/house-robber/description/
*/
// recursion
int robHelper(vector<int>& nums, int i) {
    if (i < 0) return 0;      // no houses left
    if (i == 0) return nums[0]; // only one house

    // two choices:
    // 1) Rob current house + rob up to i-2
    int robCurrent = nums[i] + robHelper(nums, i - 2);

    // 2) Skip current house, rob up to i-1
    int skipCurrent = robHelper(nums, i - 1);

    return max(robCurrent, skipCurrent);
}

// optimised dp

int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            // max(notake,take)
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }

// no space
    int rob(vector<int>& nums) {
    int a = 0, b = 0;
        int n=nums.size();
    for (int i=0; i<n; i++){
        if (i%2==0){
            a = max(a+nums[i], b);
        }
        else{
            b = max(a, b+nums[i]);
        }
    }
    
    return max(a, b);
    }