#include<bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:

Input: root = [1,2], targetSum = 0
Output: []

*/
class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(!root) return true;
        return !root->left && !root->right;
    }
    void pathSumHelper(TreeNode* root, int &targetSum, vector<int>&path, vector<vector<int>>&result){
        if(!root) return ;
        targetSum-=root->val;
        path.push_back(root->val);
        if(isLeaf(root) && targetSum==0){
            result.push_back(path);
        }
        //recur
        pathSumHelper(root->left, targetSum, path, result);
        pathSumHelper(root->right, targetSum, path, result);

        // backtrack
        path.pop_back();
        targetSum+=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       
        vector<vector<int>>result;
        vector<int>path;
        if(!root) return result;
        pathSumHelper(root, targetSum,path,result);
        return result;
    }
};