#include<stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/rotate-array/description/
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


*/
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(k%n==0) return ;
    k=k%n;
    // input 1234567
    reverse(nums.begin(),nums.end()); // 7654321
    reverse(nums.begin(),nums.begin()+k); // 5674321
    reverse(nums.begin()+k,nums.end()); // 5671234
}