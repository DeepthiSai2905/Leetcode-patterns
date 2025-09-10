#include<bits/stdc++.h>
using namespace std;

// SINGLE NUMBER I - all elements appear twice except one
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1
*/
int singleNumber(vector<int>& nums) {
    int result=0;
    for(int num: nums){
        result^=num; // a^a=0, a^0=a
    }
    return result;
}

/*260. Single Number III QUESTION2 --  What if 2 numbers appear once and rest appear twice
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]



