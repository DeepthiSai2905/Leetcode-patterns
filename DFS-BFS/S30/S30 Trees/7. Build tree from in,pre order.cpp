#include <bits/stdc++.h>
using namespace std;
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

// this gives TLE on large test cases if you dont pass map by reference
TreeNode* buildTreeUtil(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeUtil(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeUtil(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap; 
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode* root = buildTreeUtil(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}

// optimized approach
/*
What to Pass by Reference vs Value:
✅ preIndex → Pass by reference (&)

Because it changes in each recursive call.

It tracks the current node in preorder globally.

✅ inStart, inEnd → Pass by value

They are local to each recursive call.

You don’t need to share or update them globally.

✅ inMap → Pass by reference (&)

It’s a large, read-only map used in all calls.

Passing by value would copy it every time — inefficient.

*/
TreeNode* buildTreeUtil(vector<int>& preorder, int &preIndex, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(inStart > inEnd) return NULL;
// one preIndex should be enough, instead of two preStart,preEnd as preorder already travels root,left,right by default
    TreeNode* root = new TreeNode(preorder[preIndex++]); 
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeUtil(preorder, preIndex, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeUtil(preorder, preIndex, inorder, inRoot + 1, inEnd, inMap);

    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap; 
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    int preIndex=0;
    TreeNode* root = buildTreeUtil(preorder, preIndex, inorder, 0, inorder.size() - 1, inMap);
    return root;
}