#include<stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/next-permutation/
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
*/


/*
intuition - j poimter from back
ideally it should be increasing from back (which means it doesnt have next permutation)
non-ideal case: (it has next permutation)
step 1 - from back find index1 where arr[j]>arr[j-1]
        if(index1==-1) which means ideal case (increasing from back)

step 2 - from index1 to n -> find immediate greater number(index2) of index1 
step 3 - swap them
step 4 - reverse after index1


*/
void nextPermutation(vector<int>& nums) {
        // 2186495321 
        // from last find first element nums[i-1]<nums[i] 
        int n=nums.size();
        int j=n-1;
        while(j>0 && nums[j]<=nums[j-1]){
            j--;
        }
        // reached start - no next permutation
        if(j==0) {
            reverse(nums.begin(),nums.end());
            return ;
        }
        int index1=j-1; // number - 4
        int index2; // number - 5
        // find index2 element greater than nums[j]
        while(j<n && nums[j]>nums[index1] ){
            index2=j;
            j++;
        }
        swap(nums[index1],nums[index2]); // number becomes 2186594321 
        // reverse after index1 - 2186512349
        reverse(nums.begin()+index1+1, nums.end());
    }