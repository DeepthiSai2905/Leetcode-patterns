#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-peak-element/description/
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

*/

/* Intuition:
1. arr[mid] is a peak if arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]
2. If arr[mid] > arr[mid-1], there is no peak in left side so it should have peak in the right side
// **** keep moving towards increasing slope****
*/
int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int i=1,j=n-2;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
        else if(nums[mid]<nums[mid+1]) i=mid+1; // increasing slope from mid to mid+1, there is chance that higher peak is in right side
        else j=mid-1;
    }
    return -1;
}