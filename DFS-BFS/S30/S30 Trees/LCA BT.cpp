#include <bits/stdc++.h>
using namespace std;
/*



*/
vector<TreeNode*> pathP, pathQ;
void helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path){
    //base case
    if(root==NULL) return ;
    // after we got both path we dont need to iterate any furthur
    // if(pathP.size()>0 && pathQ.size()>0) return; // conditional exit
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


// Solution 2: Optimal, tc=O(n), sc=O(h)
// return node only if its value is p or q
// if both left and right are not null then return root
// else return left or right which is not null
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || p->val==root->val || q->val==root->val) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // when both are not null -> found ancestor
    if(left && right) return root;
    // if one is null, other is not null -> return non null
    return left ? left : right;
}