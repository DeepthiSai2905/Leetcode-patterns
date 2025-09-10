#include <bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

*/
bool isCousins(TreeNode* root, int x, int y) {
    if(!root) return false;
    queue<TreeNode*>Q;
    Q.push(root);
    // Two rules to be cousins
    // 1. they should be in same level but not have same parent
    while(!Q.empty()){
        int size=Q.size();
        bool xExistLevel=false, yExistLevel=false;
        while(size--){
            TreeNode* curr=Q.front(); Q.pop();
            if(curr->val==x) xExistLevel=true;
            if(curr->val==y) yExistLevel=true;
            if(curr->left && curr->right && (
                (curr->left->val==x && curr->right->val==y) || (curr->left->val==y && curr->right->val==x)
            )) return false;
            
            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }
        if(xExistLevel && yExistLevel) return true;
    }
    return false;
}