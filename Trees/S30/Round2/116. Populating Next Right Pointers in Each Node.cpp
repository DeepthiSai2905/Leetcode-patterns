#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/
// Approach 1 - BFS - time complexity: O(n), space complexity: O(n)
Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>Q;
        Q.push(root);
        while(!Q.empty()){
            int len=Q.size();
            for(int i=0;i<len;i++){
                Node* curr=Q.front();
                Q.pop();
                if(i==len-1) curr->next=NULL;
                else curr->next = Q.front();
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }
        }
        return root;
    }
// Approach 2 - Iterative - time complexity: O(n), space complexity: O(1)
// This is a perfect binary tree, so we can use the property if left is present, right is also present.
// We can traverse level by level and connect the nodes in the same level.
Node* connect(Node* root) {
        if(!root) return root;
        Node* level=root;
        while(level->left){
            Node* curr=level;
            while(curr){
                // 1. connect leftchild to rightchild
                curr->left->next=curr->right;
                // 2. connect right of left node chunk to left of right node chunk 
                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                // 3. go to next 
                curr=curr->next;
            }
            level=level->left;
        }
        return root;
    }

    // Approach 3 - DFS  Recursive - time complexity: O(n), aux space complexity: O(1) in-place
    void dfsConnect(Node* root){
        // preorder  inorder works 
        if(root->left==NULL) return ; // for level
        // logic
        // 1. connect leftchild to rightchild
        root->left->next=root->right;
        // 2. connect right of left node chunk to left of right node chunk 
        if(root->next){
            root->right->next = root->next->left;
        }
        dfsConnect(root->left);
        dfsConnect(root->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        dfsConnect(root);
        return root;
    }
// extra
// this inorder works
void dfsConnect(Node* root){
        // preorder  inorder works 
        if(root->left==NULL) return ; // for level
        // logic
        // 1. connect leftchild to rightchild
        root->left->next=root->right;
        // 2. connect right of left node chunk to left of right node chunk 
        
        dfsConnect(root->left);
        if(root->next){
            root->right->next = root->next->left;
        }
        dfsConnect(root->right);
    }
// this inorder doesnt work
void dfsConnect(Node* root){
        // preorder  inorder works 
        if(root->left==NULL) return ; // for level
        // logic
        
        dfsConnect(root->left);

        // 1. connect leftchild to rightchild
        root->left->next=root->right;
        // 2. connect right of left node chunk to left of right node chunk 
        if(root->next){
            root->right->next = root->next->left;
        }
        dfsConnect(root->right);
    }

    // this postorder also doesnt work - because curr.next is not formed yet
void dfsConnect(Node* root){
        // preorder  inorder works 
        if(root->left==NULL) return ; // for level
        // logic
        
        // 1. connect leftchild to rightchild  - this should always be done
        root->left->next=root->right;
        dfsConnect(root->left);

        dfsConnect(root->right);
        // 2. connect right of left node chunk to left of right node chunk 
        if(root->next){
            root->right->next = root->next->left;
        }
    }

// OTHER APPROACHES
// remind of mirror image of tree - dfs pattern
void dfsConnect(Node* left,Node* right){
        // preorder
        // if(root->left==NULL) return ; // for level this becomes
        if(left==NULL) return;
        // logic
        // 1. connect leftchild to rightchild
        // root->left->next=root->right; This becomes
        left->next=right;
        // 2. connect right of left node chunk to left of right node chunk 
        // if(root->next){
        //     root->right->next = root->next->left;
        // } - this becomes
        // right->next = next->left; - which covers under dfsConnect(left->right,right->left);
        dfsConnect(left->left,left->right);
        dfsConnect(left->right,right->left);
        dfsConnect(right->left,right->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        dfsConnect(root->left,root->right);
        return root;
    }

    // these are 2 independent nodes, so all pre,post,inorder works (like when u shift left->next=right to next of all three recursive calls)
