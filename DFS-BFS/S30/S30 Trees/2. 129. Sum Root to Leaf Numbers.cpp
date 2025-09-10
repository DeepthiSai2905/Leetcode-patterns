#include <bits/stdc++.h>    
using namespace std;
/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/


// approach: pass by value
class Solution {
public:
    void sumNumbersHelper(TreeNode* root, int curr_sum, int &ans){
        if(root==NULL) return ;
        curr_sum = curr_sum*10+root->val;
        if(!root->left && !root->right) ans+=curr_sum;
        sumNumbersHelper(root->left, curr_sum, ans);
        sumNumbersHelper(root->right, curr_sum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int curr_sum=0;
        int ans=0;
        sumNumbersHelper(root, curr_sum, ans);
        return ans;
    }
};

// approach: pass by reference + backtrack
bool isLeaf(TreeNode* root){
    if(!root) return true;
    return !root->left && !root->right;
}
void sumNumbersHelper(TreeNode* root,int &totalSum,int &currNum){
    if(!root) return ;
    currNum=currNum*10+root->val;
    if(isLeaf(root)){
        totalSum+=currNum;
    }
    //recur
    sumNumbersHelper(root->left,totalSum,currNum);
    sumNumbersHelper(root->right,totalSum,currNum);
    // backtrack
    currNum=(currNum-root->val)/10;
}
int sumNumbers(TreeNode* root) {
    int totalSum=0;
    int currNum=0;
    sumNumbersHelper(root,totalSum,currNum);
    return totalSum;
}