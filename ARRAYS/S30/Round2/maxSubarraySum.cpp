#include<stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/maximum-subarray/description/
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

*/
int maxSubArray(vector<int>& nums) {
    int curr_max_sum=nums[0], final_max_sum=nums[0];
    for(int i=1;i<nums.size();i++){
        curr_max_sum = max(curr_max_sum+nums[i], nums[i]);
        if(curr_max_sum > final_max_sum) final_max_sum=curr_max_sum;
    }
    return final_max_sum;
}
/*
int maxSubArray(vector<int>& nums) {
    int curr_max_sum=0, final_max_sum=0; // fails - what if all are negative numbers
    for(int i=0;i<nums.size();i++){
        curr_max_sum = max(curr_max_sum+nums[i], nums[i]);
        if(curr_max_sum > final_max_sum) final_max_sum=curr_max_sum;
    }
    return final_max_sum;
}

*/

// find indices
