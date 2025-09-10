#include <bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

*/
bool isSymmetricHelper(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2) return true;
        if(root1==NULL || root2==NULL) return false;
        return root1->val==root2->val && isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricHelper(root,root);
    }