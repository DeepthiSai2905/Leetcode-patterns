#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

// approach 1 - Recursion + Backtracking when using reference path
void subsetsHelper(vector<int>& nums, vector<vector<int>>&res, int index, vector<int>path){
    if(index==nums.size()) {
        res.push_back(path);
        return ;
    }
    // take -  backtracking
    path.push_back(nums[index]);
    subsetsHelper(nums,res,index+1,temp);
    path.pop_back(); // backtrack

    // no take
    subsetsHelper(nums,res,index+1,path);

}

// approach 2 - For loop based recursion
void subsetsHelper(vector<int>& nums, vector<vector<int>>&res, int pivot, vector<int>&path){
    res.push_back(path);
    for(int i=pivot;i<nums.size();i++){
        path.push_back(nums[i]);
        subsetsHelper(nums,res,i+1,path);
        path.pop_back();
    }
}

// approach 3 - Bit Manipulation
vector<vector<int>> subsets(vector<int>& nums) {
        // no recursion
    int n=nums.size();
    vector<vector<int>>res;
    vector<int>path;
    res.push_back({});
    for(int i=0;i<n;i++){
        int resSize = res.size();
        for(int j=0;j<resSize;j++){
            vector<int>path=res[j];
            path.push_back(nums[i]);
            res.push_back(path);
        }
    }
    return res;
}