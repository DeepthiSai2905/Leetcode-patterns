#include <bits/stdc++.h>
using namespace std;
/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
*/

// simple and direct approach
Node* connect(Node* root) {
    if(!root) return root;
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        int size=Q.size();
        for(int i=0;i<size;i++){
            Node* curr=Q.front(); Q.pop();
            if(i==size-1) curr->next = NULL;
            else curr->next = Q.front();
            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }
    }
    return root;
}

// optimized approach using already established next pointers
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

// dfs
void dfsConnect(Node* root){
    // preorder
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


// dfs optimise
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
