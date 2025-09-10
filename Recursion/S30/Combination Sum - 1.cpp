#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/combination-sum/description/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/

//approach 1 - Recursion + Backtracking when using reference path
void combinationSumhelper(vector<int>& candidates,int index, int target, vector<int>&path,vector<vector<int>>&res){
    if(index==candidates.size() || target<0) return ;
    if(target==0) {
        res.push_back(path);
        return;
    }

    // take
    path.push_back(candidates[index]);
    combinationSumhelper(candidates,index,target-candidates[index],path,res);
    path.pop_back(); // add this for path by reference
    // no take
    combinationSumhelper(candidates,index+1,target,path,res);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>path;
    combinationSumhelper(candidates,0,target,path,res);
    return res;
}



// for loop bsaed recursion
void combinationSumhelper(vector<int>& candidates,int pivot, int target, vector<int>&path,vector<vector<int>>&res){
    if(pivot==candidates.size() || target<0) return ;
    if(target==0) {
        res.push_back(path);
        return;
    }
    for(int i=pivot;i<candidates.size();i++){
        // take
        path.push_back(candidates[i]);
        combinationSumhelper(candidates,i,target-candidates[i],path,res);
        path.pop_back(); // add this for path by reference
    }
    // no take condition is not at all present in this for-loop based recursion
}