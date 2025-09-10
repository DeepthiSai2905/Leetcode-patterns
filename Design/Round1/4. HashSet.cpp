#include<bits/stdc++.h>
using namespace std;
/*
Double hashing works perfectly fine than linear chaining

why? double hashing uses array, linear chaining uses linked list
so, in double hashing, we can access the element in O(1) time, 
but to search an element in linked list, we need to traverse the entire linked list which takes O(n) time
We take boolean present/not in down array (mainitain square matrix - O(1000*1000) space)
*/

class MyHashSet {
public:
    // datastructure in a datastructure is always a pointer
    vector<vector<bool>>storage;
    int buckets;
    MyHashSet() {
        buckets = 1000;
        storage = vector<vector<bool>>(buckets);
    }

    int hashFunction1(int key){
        return key%buckets;
    }

    int hashFunction2(int key){
        return key/buckets;
    }
    
    void add(int key) {
        int hashidx1 = hashFunction1(key);
        if(storage[hashidx1].empty()){ // empty
           // create nested array
           int size;
           if(hashidx1==0){ // including 0 we have 1001 in down array
            size=buckets+1;
           }
           else size=buckets;
           storage[hashidx1] = vector<bool>(size);

        }
        int hashidx2 = hashFunction2(key);
        storage[hashidx1][hashidx2]=true;
    }
    
    void remove(int key) {
        int hashidx1 = hashFunction1(key);
        if(storage[hashidx1].empty()) return ; // bucket not found
        int hashidx2 = hashFunction2(key);
        storage[hashidx1][hashidx2]=false;

    }
    
    bool contains(int key) {
        int hashidx1 = hashFunction1(key);
        if(storage[hashidx1].empty()) return false; // bucket not found
        int hashidx2 = hashFunction2(key);
        return storage[hashidx1][hashidx2];
    }
};