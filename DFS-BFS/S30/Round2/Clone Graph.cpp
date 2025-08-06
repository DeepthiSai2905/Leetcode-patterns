#include<bits/stdc++.h>
using namespace std;
/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
*/

// BFS Solution Clone a graph using BFS tc: O(V+E) sc: O(V)
Node* cloneGraph(Node* node) {
    if(node==NULL) return NULL;
    unordered_map<Node*, Node*>mp;
    queue<Node*>Q;
    Node* clonedNode=new Node(node->val);
    mp[node]=clonedNode;
    Q.push(node); // iterate original graph
    while(!Q.empty()){
        Node* curr = Q.front(); Q.pop();
        for(Node* neigh: curr->neighbors){
            if(mp.find(neigh)==mp.end()){ // not found
                // then only create cloned nodes
                Node* clonedNeigh=new Node(neigh->val);
                Q.push(neigh);
                mp[neigh]=clonedNeigh;
            }
            // we have all neigh cloned nodes, create connections now
            mp[curr]->neighbors.push_back(mp[neigh]);
        }
    }
    return clonedNode;
}


// DFS Solution Clone a graph using DFS tc: O(V+E) sc: O(V)
void dfs(Node* curr, unordered_map<Node*, Node*>&mp){
    // base
    if(mp.find(curr)!=mp.end()) return ; // node present
    // logic
    Node* clonedNode=new Node(curr->val);
    mp[curr]=clonedNode;
    for(Node* neigh: curr->neighbors){
        // then only create cloned nodes
        dfs(neigh, mp);
        // we have all neigh cloned nodes, create connections now
        mp[curr]->neighbors.push_back(mp[neigh]);
    }
}
Node* cloneGraph(Node* node) {
    if(node==NULL) return NULL;
    unordered_map<Node*, Node*>mp;
    dfs(node,mp);
    return mp[node];
}