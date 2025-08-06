#include <bits/stdc++.h>
using namespace std;
/*


https://leetcode.com/problems/jump-game-ii/description/
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 
*/
// clarify ques - is it guarentted that we can reach the last index?
// recursion - draw recursion tree for better understanding
int minSteps(int i, int jumps, vector<int>& nums, int n){
    if(i>=n-1) return jumps; // reached or crossed last index
    int minStepsVal=INT_MAX;
    for(int step=1;step<=nums[i];step++){
        minStepsVal = min(minStepsVal, minSteps(i+step, jumps+1,nums,n)); // steps from current index
    }
    return minStepsVal;
}
int jump(vector<int>& nums) {
    return minSteps(0,0,nums,nums.size());
}

// memoization
int minSteps(int i, int jumps, vector<int>& nums, int n, vector<vector<int>>& dp){
    if(i>=n-1) return jumps; // reached or crossed last index
    if(dp[i][jumps]!=-1) return dp[i][jumps];
    int minStepsVal=INT_MAX;
    for(int step=1;step<=nums[i];step++){
        minStepsVal = min(minStepsVal, minSteps(i+step, jumps+1,nums,n,dp)); // steps from current index
    }
    return dp[i][jumps]=minStepsVal;
}

// greedy - maintain range of jumps

// 2 3 1 4 1 1 1 2
/*
l=0,r=0, jumps=0 -> now i can take 1 or 2 steps at index 0 => l=1,r=2,jumps=1
l=1,r=2,jumps=1 -> now from index 1 max i can go is to index 4 => l=r+1 (next window right after r)=> l=3,r=4,jumps=2
l=3,r=4,jumps=2 -> now from index 3 max i can go is to index 7 => l=r+1 (next window right after r)=> l=5,r=7,jumps=3
now 7(n-1) is reached so return jumps
*/
int jump(vector<int>& nums) {
    int n=nums.size();
    int jumps=0;
    // using greedy - range method
    int l=0,r=0;
    int farthest;
    while(r<n-1){ // if n-1 or more, we reached destination
        // find farthest it can reach
        farthest=INT_MIN;
        for(int i=l;i<=r;i++){
            // find farthest to in current range to create next range
            farthest=max(farthest, i+nums[i]);
        }
        l=r+1; // move to next window
        jumps++;
        r=farthest;
    }
    return jumps;
}
