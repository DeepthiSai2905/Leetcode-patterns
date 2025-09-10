#include <bits/stdc++.h>
using namespace std;
/*
366. Find Leaves of Binary Tree
Medium

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 

Example 1:
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]

*/
bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}
void removeLeaf(TreeNode* &root,vector<int>&subRes){ // -> pass by reference &root
    if(!root) return ;
    if(isLeaf(root)){
        subRes.push_back(root->val);
        root=NULL;
        return ;
    }
    removeLeaf(root->left,subRes);
    removeLeaf(root->right,subRes);
}
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> result;
    while(root){
        vector<int>subRes;
        removeLeaf(root,subRes);
        result.push_back(subRes);
    }
    return result;
    
}

// Optimised approach using DFS -> using depth calculation concept

int dfs(TreeNode* root,vector<vector<int>> &result){
    if(!root) return -1;
    int leftDepth = dfs(root->left, result);
    int rightDepth = dfs(root->right, result);
    int depth = max(leftDepth, rightDepth)+1;
    if(result.size()<=depth){
        result.push_back({});
    }
    result[depth].push_back(root->val);
    return depth;
}
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> result;
    int depth=0;
    dfs(root, result);
    return result;
    
}