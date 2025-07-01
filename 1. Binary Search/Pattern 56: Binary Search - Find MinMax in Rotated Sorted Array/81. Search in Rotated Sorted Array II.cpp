#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return true;
            }
            // add extra condition for duplicates elmination
            if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
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
        return false;
    }
};