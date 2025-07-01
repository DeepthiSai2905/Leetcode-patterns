#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/binary-search/description/
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

*/

int search(vector<int>& nums, int target) {
    int i=0,j=nums.size()-1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return -1;
}