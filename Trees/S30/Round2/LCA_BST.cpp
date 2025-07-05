#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

*/
// recursive approach - tc- o(h) sc- o(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val){
           return lowestCommonAncestor(root->right,p,q);
        }
       
        return root;
    }
// optimise space iterative approach - tc- o(h) sc- o(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        while(root){
            if(root->val<p->val  && root->val<q->val){
                root=root->right;
            }
            else if(root->val>p->val  && root->val>q->val){
                root=root->left;
            } 
            else return root;  
        }
        return root;
}