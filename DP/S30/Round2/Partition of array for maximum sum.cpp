#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/partition-array-for-maximum-sum/description/
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
*/

// recursion  - tc: o(k^n)
int helper(vector<int>& arr, int k, int index){
        // base
        if(index>=arr.size()) return 0;
        // logic
        int maxi=0;
        int maxPartition = arr[index];
        for(int j=1;j<=k && index+j-1<arr.size() ;j++){
            maxPartition=max(maxPartition, arr[index+j-1]);
            int curr=maxPartition*j + helper(arr,k,index+j);
            maxi=max(maxi,curr);
        }
        return maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        // recursion
        return helper(arr,k,0);

    }

// dp
int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            // that particular subarray maximum
            int maxi=arr[i];
            for(int j=1;j<=k && (i-j+1)>=0; j++){
                int curr=arr[i-j+1];
                maxi=max(curr,maxi);
                if(i-j>=0) dp[i]=max(dp[i],maxi*j + dp[i-j]);
                else dp[i]=max(dp[i],maxi*j);
            }
        }
        return dp[n-1];
    }