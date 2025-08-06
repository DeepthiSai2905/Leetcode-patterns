#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/jump-game/description/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/
// recursion
bool canJumpFrom(int i, vector<int>& nums) {
    if (i >= nums.size() - 1) return true; // reached or crossed last index

    for (int jump = 1; jump <= nums[i]; ++jump) {
        if (canJumpFrom(i + jump, nums)) return true; // try next positions
    }
    return false;
}

bool canJump(vector<int>& nums) {
    return canJumpFrom(0, nums);
}

// bfs while recursion
bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return true;
        queue<int>Q;
        unordered_set<int>s; // to aviod repeated computatinos in recursion
        Q.push(0);
        s.insert(0);
        while(!Q.empty()){
            int curr=Q.front(); Q.pop();
            for(int j=1;j<=nums[curr];j++){
                int newInd = curr+j;
                if(newInd==n-1) return true;
                if(!s.count(newInd)){
                    Q.push(newInd);
                    s.insert(newInd);
                }
            }
        }
        return false;
    }

// dfs
bool canJump(vector<int>& nums) {
    int n=nums.size();
    if(n<2) return true;
    return dfs(nums,0);
}
bool dfs(vector<int>& nums,int index){
    // base
    if(index==nums.size()-1) return true;
    // logic
    for(int j=1;j<=nums[index];j++){
        int newIndex = index+j;
        if(dfs(nums,newIndex)) return true;
    }
    return false;
}

// greedy
bool canJump(vector<int>& nums) {
    int n=nums.size();
    int maxReach=0;
    for(int i=0;i<n;i++){
        if(i>maxReach) return false; // not reachable
        maxReach=max(maxReach,nums[i]+i);
    }
    return true;
}

bool canJump(vector<int>& nums) {
    int n=nums.size();
    int step=nums[0];
    for(int i=1;i<n;i++){
        step--;
        if(step<0){
            return false;
        }
        if(nums[i]>step){
            step=nums[i];
        }
    }
    return true;
}


/*
Simple drive through interview:


*/

// recursion
bool canReach(index, arr){
    if(index>=n-1) return true; // reached or crossed last index
    for(int step=1;step<=arr[index];step++){
        if(canReach(index+step, arr)) return true; // try next positions
    }
    return false;
}
// now memorise - dp[n] = -1
bool canReach(index, arr, dp){
    if(index>=n-1) return true;
    if(dp[index]!=-1) return dp[index]; // already computed
     // reached or crossed last index
    for(int step=1;step<=arr[index];step++){
        if(dp[index+step]) return dp[index]=true; // try next positions
    }
    return dp[index]= false;
}
/* greedy - This can be done greedily. I keep track of the farthest index reachable so far. If I can reach or pass the end, I return true. 
If at some point I can’t move forward, return false.*/
bool canReach(vector<int>& arr) {
    int n = arr.size();
    int maxReach = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false; // not reachable
        maxReach = max(maxReach, i + arr[i]);
    }
    return true; // can reach the end
}