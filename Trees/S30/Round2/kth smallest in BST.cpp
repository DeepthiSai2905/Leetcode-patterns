#include<bits/stdc++.h>
using namespace std;
/*
 Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
 
 */
// Time complexity: O(n) for traversing all nodes, space complexity: O(n) for recursion stack
class Solution {
public:
    int result;
    int count;
    void inorderTraverse(TreeNode* root){
        if(root==NULL) return ;
       // System.print.outln(root->val). // example 1: k=2 -> 3124 (prints all even if added return in 23)
       // to skip traversal after k is 0, add below line
        if(result!=INT_MAX) return ; // conditional exit // after adding this line 14 prints 312 not 4
        inorderTraverse(root->left);
        count--; // root
        if(count==0) {
            result = root->val;
            return ; // wtever goes in comes out of recrusion stack 
        }
        inorderTraverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        result=INT_MAX;
        count=k;
        // inorder
        inorderTraverse(root);
        return result;
        
    }
};

// approach - int based recursion
class Solution {
public:
    int result;
    int count;
    // lets do int based recursion
    int inorderTraverse(TreeNode* root){
        if(root==NULL) return INT_MAX;
        int left = inorderTraverse(root->left);
        if(left!=INT_MAX) return left;
        count--; // root
        if(count==0) {
            return root->val;
        }
        int right = inorderTraverse(root->right);
        // logic1 -  return right;
        // logic 2 return part - if left and right return INT_MAX, or if one return INT_MAX and other returns value - we return value;
        return min(left,right);
    }
    int kthSmallest(TreeNode* root, int k) {
        result=INT_MAX;
        count=k;
        // inorder
        return inorderTraverse(root);
        
    }
};


// Optimal approach thoughts - we are not taking advantage of eliminating right or left subtree based on k
// 1. Do ranking of nodes in BST so if root has rank m, and kth smallest would be 
// in left subtree if k<m, else in right subtree if k>m


// Extended question - lets say if the tree is dynamic, and we need to find kth smallest after every insertion
// In this case rankings change, its again O(n) to do ranking after every insertion
// so instead of tracking rank, we can track count of left elements for every node

// change TreeNode structure to add leftCount
// Time complexity: O(h) for finding kth smallest, O(h) for insertion
int kthSmallest(TreeNode* root, int k) {
        while(root){
            if(k==root->leftCount+1){ // +1 - root itself
                return root->val;
            }
            else if(k>root->leftCount+1){ // go right and k changes to (k-leftCount-1)
                root=root->right;
                k=(k-leftCount-1);
            }
            else root=root->left;
        }
        return -1;
        
        
    }
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
        root->leftCount++;
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

