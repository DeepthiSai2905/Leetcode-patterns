#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

// Approach: Using Binary Search - O(logn) time and O(1) space
class Solution {
public:
    int findOccurence(vector<int>& nums, int target, int i,int j, bool firstOcc){
        int res = -1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                res=mid;
                if(firstOcc) j=mid-1; // there could be more occurences on left side
                else i=mid+1; // there could be more occurences on right side
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;
        int first = findOccurence(nums,target,i,j,true);
        int last = findOccurence(nums,target,i,j,false);
        return {first,last};
    }
};