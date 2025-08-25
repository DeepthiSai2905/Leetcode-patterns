#include<bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

*/

/*QUESTIONS TO ASK:
1. DOES IT HAVE TO BE LEFT TO RIGHT? YES
2. WHAT IF TWO NODES HAVE SAME COLUMN? SORT BY ROW
3. WHAT IF TWO NODES HAVE SAME ROW AND COLUMN? SORT BY VALUE
4. WHAT IF THE TREE IS EMPTY? RETURN EMPTY ARRAY
*/
// here row is required as we need to maintain order at same column 
// in DFS, depth is fine maintained but row is not maintained, so we need to pass row as well
void dfs(TreeNode* root, int row, int col, map<int,vector<pair<int,int>>>&mp){
        if(!root) return ;
        mp[col].push_back({row,root->val});
        dfs(root->left, row+1, col-1, mp);
        dfs(root->right, row+1, col+1, mp);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int,vector<pair<int,int>>>mp;
        dfs(root,0,0,mp);
        int n=mp.size();
        vector<vector<int>>result;
        for(auto [col,nodes]:mp){
            // sort(nodes.begin(), nodes.end()); // if rows are equal?
            sort(nodes.begin(), nodes.end(),[](auto &a, auto &b){
                if(a.first==b.first) a.second>b.second;
                return a.first<b.first;
            }); 
            vector<int> column;
            for (auto& [row, val] : nodes) column.push_back(val);
            result.push_back(column);
        }
        return result;
    }

// BFS - by default natural choice to get order from left to right in every level
vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>>mp;
        vector<vector<int>>result;
        queue<pair<int, TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto node=q.front(); q.pop();
            int col=node.first;
            TreeNode* curr = node.second;
            mp[col].push_back(curr->val);
            if(curr->left){
                q.push({col-1,curr->left});
            }
            if(curr->right){
                q.push({col+1,curr->right});
            }
        }
        for(auto node: mp){
            result.push_back(node.second);
        }
        
        return result;
    }