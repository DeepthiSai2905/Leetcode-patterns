#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
postorder is the postorder traversal of the same tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

*/
// here we are dealing with ranges, so we dont need to reverse left and right subtree as we are already passing the correct ranges
TreeNode* buildTreeUtil(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap) {
    if(inStart > inEnd || postStart>postEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]); 
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeUtil(inorder, inStart, inRoot-1 , postorder, postStart, postStart+numsLeft-1 , inMap);
    root->right = buildTreeUtil(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inMap);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap; 
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode* root = buildTreeUtil(inorder, 0, inorder.size()-1, postorder, 0, postorder.size() - 1, inMap);
    return root;
}

// optimized approach here we are dealing with single postIndex instead of postStart,postEnd
// as here we are just iterating not dealing with ranges, we have to resverse left and right subtree calls
TreeNode* buildTreeUtil(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int &postIndex, unordered_map<int, int>& inMap) {
    if(inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postIndex--]); 
    int inRoot = inMap[root->val];

    root->right = buildTreeUtil(inorder, inRoot+1, inEnd, postorder, postIndex, inMap);
    root->left = buildTreeUtil(inorder, inStart, inRoot-1 , postorder, postIndex , inMap);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap; 
    int n=postorder.size();
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    int postIndex=n-1;
    TreeNode* root = buildTreeUtil(inorder, 0, inorder.size()-1, postorder, postIndex, inMap);
    return root;
}


