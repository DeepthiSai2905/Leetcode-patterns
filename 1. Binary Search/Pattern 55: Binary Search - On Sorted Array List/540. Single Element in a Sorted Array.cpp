#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/single-element-in-a-sorted-array/description/
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
*/

// Brute force - traverse and Do XOR for elements - O(n) time and O(1) space
// Optimal - Binary Search - O(log n) time and O(1) space
// Intuition??
int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            // mid can be even or odd
            // mid is even, and nums[mid] == nums[mid + 1] → Single element is on the right.
            // mid is odd, and nums[mid] == nums[mid - 1] → Single element is on the right.
            // This is because pairs before the unique element start at even indices, and the pattern breaks at or after the unique element.
            if(mid>0 && mid<n-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            // intuition - either left or right have single element
            // 1122334 - right unique (mid=2, mid-1 is also 2)
            // 1123344 - left unique (mid=3, mid+1 is also 3)
            if(mid>0 && mid<n-1  && (mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid] == nums[mid - 1])){ // move right
                 i=mid+1;
            }
            else j=mid-1;
        }
        return nums[i];
    }