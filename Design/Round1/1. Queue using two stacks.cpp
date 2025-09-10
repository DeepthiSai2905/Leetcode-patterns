/*


*/

// pop heavy push light - push o(1), pop o(n)
class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
       /* 
       1. shift elements of s1 to s2 
       2. pop top of s2
       3.  shift elements of s2 to s1 back to keep push in o(1)
       */
       while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       int poppedEle = s2.top(); s2.pop();
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       return poppedEle;
    }
    
    int peek() {
        while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       int topEle = s2.top();
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       return topEle;
    }
    
    bool empty() {
        return s1.empty();
    }
};
// push heavy, pop, top light - push o(n), pop o(1)
class MyQueue {
public:
  // push heavy, pop top light
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        /* 
       1. shift elements of s1 to s2 
       2. push element to s1
       3. shift elements of s2 to s1 back to keep pop in o(1)
       */
       while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       s1.push(x);
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       
    }
    
    int pop() {
       if(s1.empty()) return -1;
       int poppedEle = s1.top(); s1.pop();
       return poppedEle;
    }
    
    int peek() {
       if(s1.empty()) return -1;
       return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// optimised solution - push and pop in o(1) amortised
class MyQueue {
public:
  
    stack<int>s1;
    stack<int>s2;
    // use it as a team effeciently
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() { // how to make pop efficient
       /* 
        1. move elements from s1 to s2
        2. pop top of s2
        3. move back all elements from s2 to s1(why ???) - optimise try solving without moving them back
       idea is to consider s2 top as front and s1 top as end of queue
       */
       int poppedEle = peek();
       s2.pop();
       return poppedEle;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top()); s1.pop();
            }
        }
        if(s2.empty()) return -1;
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
