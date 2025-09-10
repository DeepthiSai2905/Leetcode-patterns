#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/basic-calculator-ii/description/
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/
// Approach: Stack - O(n) time and O(n) space
class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        int n=s.length();
        if(n==0) return 0;
        // trim start and end spaces in string

        stack<int>st;
        int currNum=0;
        char lastSign='+';
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isDigit(ch)){
                currNum=currNum*10+(ch-'0');
            }
            if((!isDigit(ch) && ch!=' ') || i==n-1){
                int value;
                if(lastSign=='+') value = currNum;
                else if(lastSign=='-') value = currNum*-1;
                else if(lastSign=='*'){
                    value = currNum*st.top();
                    st.pop();
                }else if(lastSign=='/'){
                    value = st.top()/currNum;
                    st.pop();
                }
                st.push(value);
                currNum=0;
                lastSign=ch;
            }
        }
        int result=0;
        while(!st.empty()){
            result+=st.top(); st.pop();
        }
       return result; 
    }
};

// Without using stack - O(n) time and O(1) space
/*
Intuition: needed stack only to handle * and / operations, but we can handle them using lastNum variable.

*/
int calculate(string s) {
        int n = s.length();
        int result = 0;
        int currNum = 0;
        int lastNum = 0;
        char sign = '+'; // Start with '+' so first num gets added to result

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            if (isDigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }

            // If not digit or last char: process operator
            if ((!isDigit(ch) && ch != ' ') || i == n - 1) {
                if (sign == '+') {
                    result += lastNum;
                    // use added value for next * and / operations
                    lastNum = currNum;
                } else if (sign == '-') {
                    result += lastNum;
                    // use added value for next * and / operations
                    lastNum = -currNum;
                } else if (sign == '*') {
                    lastNum = lastNum * currNum;
                } else if (sign == '/') {
                    lastNum = lastNum / currNum;
                }
                sign = ch;
                currNum = 0;
            }
        }

        result += lastNum; // Add the last evaluated number
        return result;
    }