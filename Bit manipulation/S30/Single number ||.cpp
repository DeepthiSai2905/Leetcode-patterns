#include<bits/stdc++.h>
using namespace std;
// SINGLE NUMBER II - all elements appear thrice except one
/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

//sol1: using bit manipulation
int singleNumber(vector<int>& nums) {
    int ans=0;
    // using bit manipulation count all bits if divisible by 3 ignores
    for(int bitIdx=0;bitIdx<32;bitIdx++){ // o(32)
        int count=0;
        for(int num:nums){ // o(n)
            if((num & (1<<bitIdx))){ // check if bitIdx is set
                count++;
            }
        }
        if(count%3==1){ // set ans bit to 1
            ans = ans | (1<<bitIdx);
        }
    }
    // tc-o(n*32)
    return ans;
}

// sol2: sorting then check for every 3rd element
int singleNumber(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=1;i<n;i+=3){
        if(nums[i]!=nums[i-1]) return nums[i-1];
    }
    return nums[n-1]; // when single element is at last index
    // tc - o(nlogn + n/3) here when n=2^32 it is o(32*n) worst case(rare) but for small inputs this soln works btr
}