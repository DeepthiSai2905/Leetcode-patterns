#include <bits/stdc++.h>
using namespace std;
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/

/*

if input is of single type of bracket, then 
) count++ else count-- so if count=0 return true else false

if diff types of brackets, then use stack why above soln fails? 
({)}[] - here count is 0 but not valid
so problem is ) at this closing it should make sure that last opened bracket is same as this closing bracket type 
for which we use stack

*/
bool match(char c1,char c2){
        if(c1=='{' && c2=='}') return true;
        if(c1=='[' && c2==']') return true;
        if(c1=='(' && c2==')') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && match(st.top(),s[i])){
                    st.pop();
                }
                else return false;
            }
        }
        return(st.empty());
    }