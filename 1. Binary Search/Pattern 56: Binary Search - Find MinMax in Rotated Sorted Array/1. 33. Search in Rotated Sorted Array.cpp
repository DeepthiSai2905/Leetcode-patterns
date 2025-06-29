#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

// Approach: Using Binary Search - O(logn) time and O(1) space

/* Intuition: either left or right side of the array will be sorted, so we can use binary search to find the target.

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[i]){ // left side is sorted
                // check if target is in the left side
                // if yes, search in left side, else search in right side
                if(nums[i]<=target && nums[mid]>=target){
                    j=mid-1;
                }
                else i=mid+1;
            }
            else{ // right side is sorted
                // check if target is in the right side
                // if yes, search in right side, else search in left side
                if(nums[j]>=target && nums[mid]<=target){
                    i=mid+1;
                }
                else j=mid-1;
            }
        }
        return -1;
    }
};