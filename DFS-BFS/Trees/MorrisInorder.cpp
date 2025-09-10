#include <bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

*/

vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int>result;
    TreeNode* curr = root;
    while(curr){
        if(curr->left==NULL){ // no left subtree
            result.push_back(curr->val); // root
            curr=curr->right; // right
        }
        else{
            // find inorder precedor of curr
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr){ // no thread
                prev = prev->right;
            }
            // Thread used - to go from child to parent 
            if(prev->right==NULL){ // no thread -> create one
                prev->right=curr;
                curr=curr->left;
            }
            else{ // thread already created -> remove that
                prev->right = NULL;
                result.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return result;
}