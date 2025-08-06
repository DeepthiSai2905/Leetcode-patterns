#include<bits/stdc++.h>
using namespace std;
/*
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

*/
// Brute - hashmap 1->1` tc: O(n) sc: O(n)
// clone nodes and make next pointer links, keep in hashmap.
// then clone random pointers using the hashmap
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        Node* copyHead=new Node(head->val);
        mp[head]=copyHead;
        Node* copycurr=copyHead;
        // create clone of next pointers
        while(curr->next){
            Node* copynode = new Node(curr->next->val);
            mp[curr->next]=copynode; // deep copy
            copycurr->next = copynode; // linking cloned nodes
            curr=curr->next;
            copycurr = copycurr->next;
        }
        // handle random pointers now
        curr=head;
        while(curr){
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
      
        return copyHead;
    }
};
// just clone nodes
// THEN, handle next and random pointers tc: O(n) sc: O(n)
Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        // create clone of next pointers
        while(curr){
            mp[curr]=new Node(curr->val); // deep copy
            curr=curr->next;
        }
        // handle random pointers now
        curr=head;
        while(curr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
}
// approach 2: can we create random pointers while creating next pointers? in first stage itself
Node* copyRandomList(Node* head) {
//  can we create random pointers while creating next pointers? in first stage itself
        if(!head) return head;
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        // create clone of next pointers and random pointers
        while(curr){
             // deep copy of next node
            if (mp.find(curr) == mp.end()) {
                mp[curr] = new Node(curr->val);
            }
            // make next pointer links
            if (curr->next) {
                if (mp.find(curr->next) == mp.end()) {
                    // Clone the next node if not cloned yet
                    mp[curr->next] = new Node(curr->next->val);  
                }
                mp[curr]->next = mp[curr->next];  // Link next pointer
            }
            // create deep copy of random node if not present else make link
            if(curr->random){
                if(mp.find(curr->random)==mp.end()){ // not present
                   mp[curr->random] = new Node(curr->random->val);
                  
                }
                mp[curr]->random = mp[curr->random]; //just link
            }
            curr=curr->next;
        }
        return mp[head];
    }
// same as above but diff way of writing code
Node* clone(Node* node,unordered_map<Node*,Node*>&mp){
        if(!node) return node;
        if(mp.find(node)!=mp.end()) return mp[node];
        // createcopy
        Node* copynode=new Node(node->val);
        mp[node]=copynode;
        return copynode;
    }
    Node* copyRandomList(Node* head) {
//  can we create random pointers while creating next pointers? in first stage itself
        if(!head) return head;
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        Node* copyHead=clone(head,mp);
        Node* copycurr=copyHead;
        // create clone of next pointers and random pointers
        while(curr){
            // deep copy of next node
            copycurr->next = clone(curr->next,mp);
            // create deep copy of random node if not present else make link
            if(curr->random){
                copycurr->random = clone(curr->random,mp);
            }
            curr=curr->next;
            copycurr=copycurr->next;
        }
        return mp[head];
}

// Approach 3: O(1) space, core idea is to keep clone nodes next to original nodes

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* curr = head;
    // Step 1: Clone nodes and place them next to original nodes
    while (curr) {
        Node* cloneNode = new Node(curr->val);
        cloneNode->next = curr->next;
        curr->next = cloneNode;
        curr = cloneNode->next;
    }

    // Step 2: Set random pointers for cloned nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next; // point to the cloned node
        }
        curr = curr->next->next; // move to the next original node
    }

    // Step 3: Separate the cloned list from the original list
    curr = head;
    Node* copyHead = head->next; // The head of the copied list
    Node* copyCurr = copyHead;

    while (curr) {
        curr->next = curr->next->next; // restore original list's next pointers
        if (copyCurr->next) {
            copyCurr->next = copyCurr->next->next; // set next for copied nodes
        }
        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return copyHead;
}


