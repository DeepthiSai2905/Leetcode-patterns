#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

*/

// Brute approach - find path to both nodes and compare them, wherever the uncommon element is the LCA
// Time complexity: O(h) for both path finding and comparison, space-o(h) for storing paths
class Solution {
public:
    vector<TreeNode*> pathP, pathQ;
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path){
        //base case
        if(root==NULL) return ;
        // after we got both path we dont need to iterate any furthur
        if(pathP.size()>0 && pathQ.size()>0) return; // conditional exit
        //logic

        //action
        path.push_back(root);
        if(root==p){
            pathP=path;
            pathP.push_back(root);
        }
        if(root==q){
            pathQ=path;
            pathQ.push_back(root);
        }
        // recurse
        helper(root->left,p,q,path);
        helper(root->right,p,q,path);
        //backtrack
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute create path for both p,q
        // base case
        if(root==NULL) return NULL;
        vector<TreeNode*> path;
        helper(root,p,q,path);
        for(int i=0;i<pathP.size();i++){
            if(pathP[i]!=pathQ[i]){
                return pathP[i-1];
            }
        }
        return NULL;
    }
};
// CORE CONCEPT OF LCA - root is lca for p and q when one node is in left of root and other is in right of root

// Optimised approach -  Iterate the tree and find the LCA
// if p or q is found return that, else return NULL if not found
// time complexity: O(n) for both finding p,q and LCA, space-o(h) for recursion stack

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL || root->val==p->val || root->val==q->val) return root;
        // logic
        // recurse
        TreeNode* left_lca = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_lca = lowestCommonAncestor(root->right,p,q);
        // action
        if(left_lca && right_lca) { // both are found
            return root; // both p,q found in left and right subtree
        }
        else if(left_lca && !right_lca){ // right null
            return left_lca; // p,q found in left subtree
        }
        else if(!left_lca && right_lca){ // left null
            return right_lca; // p,q found in right subtree
        }
        else { // both are null
            return NULL; // p,q not found in either subtree

        }
    }

// same in shorter version
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // ismirror
        if(root==NULL || root->val==p->val || root->val==q->val) return root;
        TreeNode* left_lca = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_lca = lowestCommonAncestor(root->right,p,q);
        if(left_lca && right_lca) return root;
        return !left_lca ? right_lca : left_lca;

    }