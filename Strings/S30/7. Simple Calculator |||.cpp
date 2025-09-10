#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/basic-calculator-iii/
brackets, and operators +, -, *, /.
Implement a basic calculator to evaluate a simple expression string containing non-negative integers, '+', '-', '*, '/' and parentheses '()'.
The integer division should truncate toward zero.

*/

int helper(const string& s, int& i) {
    int num = 0, lastNum = 0, result = 0;
    char op = '+';

    while (i < s.size()) {
        char ch = s[i];
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '(') {
            i++;
            num = helper(s, i);  // recursive call for sub-expression
        } 

        // if operator or end of expression or ')'
        if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1 || ch == ')') {
            if (op == '+') {
                result += lastNum;
                lastNum = num;
            } else if (op == '-') {
                result += lastNum;
                lastNum = -num;
            } else if (op == '*') {
                lastNum = lastNum * num;
            } else if (op == '/') {
                lastNum = lastNum / num;
            }

            if (ch == ')') {
                result += lastNum;
                return result;
            }

            op = ch;
            num = 0;
        }
        i++;
    }
    return result + lastNum;
}

int calculate(string s) {
    int i = 0;
    return helper(s, i);
}


/*
my buggy code:
*/
class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        int n=s.length();
        stack<int>st;
        char lastSign='+';
        int num=0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isDigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='('){ // process sign before (
               if(lastSign=='+') st.push(1);
               else if(lastSign=='-') st.push(-1);
               else if(lastSign=='*') st.push(2);
                else st.push(-2);
              
               st.push(INT_MAX); // to identify '(' to evaluate exp from ')'
               num=0; lastSign='+';
            }
            else if(ch==')'){
                // unwrap stack upto ( - u find INT_MAX
                // put last element first
                if(lastSign=='+') st.push(num);
               else if(lastSign=='-') st.push(-num);
               else if(lastSign=='*') {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last*num);
              }
               else {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last/num);
               }
               

               // unwrap stack upto ( - u find INT_MAX
               int interRes=0;
               while(st.top()!=INT_MAX){
                 interRes+=st.top(); st.pop();
               }// reached ( in stack
               st.pop(); // pop INT_MAX ( first
               int popedEle = st.top(); // last sign before (
               st.pop();
               if(popedEle==1 || popedEle==-1) interRes*=popedEle;
                else if(popedEle==2){ // multiply logic
                   int last = st.top(); st.pop();
                   interRes*=last;
                }
                else if(popedEle==-2){ // divide logic
                   int last = st.top(); st.pop();
                   interRes=last/interRes;
                
                }
              
              st.push(interRes);
              num=0;
              lastSign='+'; // we processed all +,-,*,/ so make it '+'
            }
            else if((!isDigit(ch) && ch!=' ') ){ // operator
               // process last sign first before updating lastSign
               if(lastSign=='+') st.push(num);
               else if(lastSign=='-') st.push(-num);
               else if(lastSign=='*') {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last*num);
              }
               else {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last/num);
               }
               
               num=0;
               lastSign=ch;
            }
            
        }

        int result=0;
        // this is not handled, though num is calculated operator calculation is not done
        if(s[n-1]!=')'){
            if(lastSign=='+') st.push(num);
            else if(lastSign=='-') st.push(-num);
            else if(lastSign=='*') {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last*num);
              }
               else {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop();
                st.push(last/num);
               }
        }
        while(!st.empty()){
            result+=st.top(); st.pop();
        }
        return result;
    }
};