#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/

/* Approach: Binary Search

   
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            if (nums[i] <= nums[j]) return nums[i];

            int mid=i+(j-i)/2;
            int prev = (mid-1);
            int next = (mid+1);
            if(mid>0 && mid<n-1 && nums[mid]<=nums[prev] && nums[mid]<=nums[next]){ // check if mid is the minimum
                return nums[mid];
            }
            else if(nums[i]<=nums[mid]){ // left sorted
                i=mid+1;
            }
             else if(nums[mid]<=nums[j]){ // right sorted
                j=mid-1;
            }
        }
        return -1;
    }
};