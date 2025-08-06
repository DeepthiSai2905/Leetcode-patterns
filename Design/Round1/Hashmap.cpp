#include <bits/stdc++.h>
using namespace std;
/*

*/
/*
 initially storage array - primary, each index is a bucket
 so, based on hashfunction value, elements will go into that bucket
 each bucket is a linked list - to handle collisions

 10^6 are total elements, 10^4 would be buckets, where each bucet on avg can have 100 elements

*/
class MyHashMap {
public:
    class Node{
    public:
        int key;
        int value;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };

    vector<Node*> storage;
    int buckets;
    int hashFunction(int key){
        return key%buckets;
    }

    MyHashMap() {
        buckets=10000;
        storage = vector<Node*>(buckets);
    }
    
    Node* helper(Node* head, int key){
        Node* prev=NULL;
        Node* curr=head;
        while(curr && curr->key!=key){
            prev=curr;
            curr=curr->next;
        }
        return prev;
    }
    void put(int key, int value) {
        int hashIndex = hashFunction(key);
        Node* head = storage[hashIndex];
        if(head==NULL) {
            head=new Node(-1,-1);
        }
        storage[hashIndex]=head;
        Node* prev = helper(head, key);
        // present in map or not
        if(prev->next && prev->next->key == key){ // key present - not fresh
           prev->next->value=value; // replace existing value
        }else{ // fresh node
            prev->next = new Node(key,value);
        }
    }
    
    int get(int key) {
        int hashIndex = hashFunction(key);
        Node* head = storage[hashIndex];
        if(!head) return -1;
        Node* prev = helper(head, key);
        if(!prev->next) return -1;
        return prev->next->value;
    }
    
    void remove(int key) {
        int hashIndex = hashFunction(key);
        Node* head = storage[hashIndex];
        if(!head) return ;
        Node* prev = helper(head, key);
        if(!prev->next) return ;
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;

    }
};