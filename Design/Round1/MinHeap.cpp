#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/min-stack/description/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

*/
// Approach: Use two stacks - one for normal stack, one for min stack
// Time Complexity: O(1) for all operations, Space Complexity: O(n) for two stacks
class MinStack {
public:
    stack<int>s;
    stack<int>minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minStack.empty() || val<minStack.top()){
            minStack.push(val);
        }
        else minStack.push(minStack.top());
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    int getMin() {
       if(minStack.empty()) return -1;
       return minStack.top();
    }
};

// Approach: Use one stacks kind of pairs(element, min_so_far)
// Time Complexity: O(1) for all operations, Space Complexity: O(n) for
class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }
        else {
            auto topEle = s.top();
            if(val<topEle.second){
                s.push({val,val});
            }
            else{
                s.push({val,topEle.second});
            }
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top().first;
    }
    
    int getMin() {
       if(s.empty()) return -1;
       return s.top().second;
    }
};

// Optimised solution - using single stack
// Time Complexity: O(1) for all operations, Space Complexity: O(n)
// long long is used to avoid overflow issues with int (when val is 2147483646 and minEle is 2147483647)
class MinStack {
public:
   /*
    newVal < val --- 1
    val < minEle
    val+val<minEle+val
    2*val - minEle < val -- 2
    comparing 1&2 => newVal = 2*val-minEle
   */
    stack<long long>s;
    long long minEle = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val); minEle=val;
            return ;
        }
        if(val<minEle){ // update mini but before that push newvalue
           long long newVal = 2LL*val-minEle;
           s.push(newVal);
           minEle = val;
        }
        else{
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return ;
        long long topEle = s.top(); s.pop();
        if(topEle < minEle){ // modified value found
           minEle = 2*minEle - topEle;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        long long topEle = s.top();
        if(topEle < minEle){ // modified value found
           return minEle;
        }
        return (int)topEle;
    }
    
    int getMin() {
       if(s.empty()) return -1;
       return (int)minEle;
    }
};