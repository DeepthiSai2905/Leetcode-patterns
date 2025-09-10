#include <bits/stdc++.h>
using namespace std;
/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/
/*
example1: 3[a]2[bc]
ex2: 3[a2[c]]

so
if(ch=='num') curr_num=curr_num*10+(ch-'0')
if(ch is alphabet) curr_string+=ch
if(ch=='[') push(curr_string, curr_num) and reset curr_string and curr_num
if(ch==']') {
   1. pop from stack and get prev_string and num (like a in ex2)
   2. add curr_string num times to itself
   3. curr_string = prev_string+curr_string


*/

// recursion

string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }

    string helper(string s, int &i) {

        // num [ recurse ]
        string result = "";
        int n = s.size();

        while (i < n && s[i] != ']') {
            // prepare number num
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {  // parse number
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++; // skip '['
                string decoded = helper(s, i); // recursive decode inside [...]
                i++; // skip ']'

                // repeat decoded string num times
                while (num--) result += decoded;
            } else {
                result += s[i]; // normal char
                i++;
            }
        }
        return result;
    }

/* Time Complexity: O(n + k)
n for parsing, k for building the final expanded string.
Space Complexity: O(n + recursion depth) → O(n) in worst case. 
*/

string decodeString(string s) {
    stack<pair<string,int>>st;
    int curr_num=0;
    string curr_string="";
    for(char ch: s){
        if(isdigit(ch)){
            curr_num = curr_num*10+(ch-'0');
        }
        else if(ch=='['){
            st.push({curr_string, curr_num});
            curr_string="";
            curr_num=0;
        }
        else if(ch==']'){
            string prev_string=st.top().first;
            int num=st.top().second;

            st.pop();
            string curr=curr_string;
            while(num>1){
                curr_string += curr;
                num--;
            }
            curr_string = prev_string+curr_string;
        }
        else{
            curr_string+=ch;
        }
    }
    return curr_string;
}


/* iterative

Time Complexity: O(n + k)
n for parsing, k for building the final expanded string.
Space Complexity: O(n + recursion depth) → O(n) in worst case. 
*/