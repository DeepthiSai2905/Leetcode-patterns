#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/recover-binary-search-tree/description/
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

*/

/* Approach 1 - 
1. do inorder traversal and store in vector, 
2. then sort the vector and find the two swapped nodes, then swap them back in the tree.
- o(nlogn) time complexity for sorting, o(n) space complexity for storing the vector.
*/

/* better approach
1. do inorder traversal and store in vector, 
2. find the two swapped nodes first,second by comparing curr, prev in the vector, then swap them back in the tree.

10 20 30 50 140 80 90 100 110 115 120 130 60 160
so, maintain curr, prev and find first, second.
if(curr<=prev) // 1st anamoly node found -> first=prev, second=curr
if(curr<=prev) // 2nd anamoly node found -> second=curr
3. swap the values of first and second in the tree.
- o(n) time complexity for traversal, o(n) space complexity for storing the vector.

*/

class Solution {
public:
    void inorderTrav(TreeNode* root, vector<TreeNode*>&inOrder) {
        if(!root) return ;
        inorderTrav(root->left,inOrder);
        inOrder.push_back(root);
        inorderTrav(root->right,inOrder);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inOrder;
        inorderTrav(root, inOrder);
        // now find first,second nodes to swap
        // when first is NULL, it is first anamoly
        TreeNode* prev=NULL,*first=NULL,*second=NULL;
        for(int i=0;i<inOrder.size();i++){
            if(prev && prev->val >= inOrder[i]->val){
                if(!first) {
                    first = prev;
                    second=inOrder[i];
                }
                else{
                    second=inOrder[i];
                }
            }
            prev=inOrder[i];
        }
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};
/*

OPTIMIZED APPROACH
but do we need to store in vector?
- no, we can do it in o(1) space complexity by using prev,curr pointers and
inorder traversal.
- o(n) time complexity for traversal, o(1) space complexity for storing the pointers
*/
// now find first,second nodes to swap
    // when first is NULL, it is first anamoly
    TreeNode* prev=NULL,*first=NULL,*second=NULL;
    void inorderTrav(TreeNode* root) {
        if(!root) return ;
        inorderTrav(root->left);

        //logic
        if(prev && prev->val >= root->val){
            if(!first) {
                first = prev;
            }
            second=root;
        }
        prev=root;

        inorderTrav(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorderTrav(root);
        
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }

// lets do inorder in iterative way
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // now find first,second nodes to swap
    // when first is NULL, it is first anamoly
    TreeNode* prev=NULL,*first=NULL,*second=NULL;

    void inorderTravItr(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode*>st;
        // inorderTrav(root->left);
        // this takes care of rightsubtree left calls
        while(!st.empty() || root!=NULL){ 
            while(root){
                st.push(root);
                root=root->left;
            }
        
            root=st.top(); st.pop();
            //logic
            if(prev && prev->val >= root->val){
                if(!first) {
                    first = prev;
                }
                second=root;
            }
            prev=root;

            // inorderTrav(root->right);
            root=root->right;
        }
    }

    void inorderTrav(TreeNode* root) {
        if(!root) return ;
        inorderTrav(root->left);

        //logic
        if(prev && prev->val >= root->val){
            if(!first) {
                first = prev;
            }
            second=root;
        }
        prev=root;

        inorderTrav(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorderTravItr(root);
        
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};