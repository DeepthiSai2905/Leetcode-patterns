#include <bits/stdc++.h>
using namespace std;    
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

*/
// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr=Q.front(); Q.pop();
            if(!curr) result+="#,";
            else {
                result+=to_string(curr->val)+=',';
                Q.push(curr->left);
                Q.push(curr->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#,") return NULL;
        int pos = data.find(',');
        string sub = data.substr(0,pos);
        data = data.substr(pos+1);
        TreeNode* root = new TreeNode(stoi(sub));
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr=Q.front(); Q.pop();

            // left child
            pos = data.find(",");
            string leftsub = data.substr(0,pos);
            data=data.substr(pos+1);

            if(leftsub!="#"){
                curr->left = new TreeNode(stoi(leftsub));
                Q.push(curr->left);
            }

            // right child
            pos = data.find(",");
            string rightsub = data.substr(0,pos);
            data=data.substr(pos+1);

            if(rightsub!="#"){
                curr->right = new TreeNode(stoi(rightsub));
                Q.push(curr->right);
            }

        }
        return root;


        
    }

// so instead of using substr for breaking string we can use stringstream and getline while deserializing
TreeNode* deserialize(string data) {
        if(data=="#,") return NULL;
        stringstream s(data);
        string sub,leftsub,rightsub;
        getline(s,sub,','); // break by ','
        TreeNode* root = new TreeNode(stoi(sub));
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr=Q.front(); Q.pop();

            // left child
           getline(s,leftsub,',');

            if(leftsub!="#"){
                curr->left = new TreeNode(stoi(leftsub));
                Q.push(curr->left);
            }

            // right child
            getline(s,rightsub,',');
            if(rightsub!="#"){
                curr->right = new TreeNode(stoi(rightsub));
                Q.push(curr->right);
            }

        }
        return root;
        
    }

