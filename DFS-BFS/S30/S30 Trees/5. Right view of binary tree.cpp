#include<bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:
Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []




*/
vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int size=Q.size();
            while(size--){
                TreeNode* curr=Q.front(); Q.pop();
                if(size==0) res.push_back(curr->val);
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }
        }
        return res;
    }
void rightSideViewDFS(TreeNode* root,vector<int>&res,int level){
        if(!root) return ;
        if(res.size()==level){
            res.push_back(root->val);
        }
        else res[level]=root->val;
        rightSideViewDFS(root->left, res,level+1);
        rightSideViewDFS(root->right, res,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        int level=0;
        rightSideViewDFS(root,res,level);
        return res;
    }