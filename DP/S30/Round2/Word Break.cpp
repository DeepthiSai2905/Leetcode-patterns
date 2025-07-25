#include<bits/stdc++.h>
using namespace std;
/*
word break
https://leetcode.com/problems/word-break/description/
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

*/
/*
Approach:
for leetcode, split into l,le,lee,leet,leetc,leetcod,leetcode
for each substring, check if it is present in the dictionary
If it is present, then check for the remaining string recusively
If the remaining string can be segmented, then return true
If no substring can be segmented, then return false
*/
// recursion tc: O(2^n) sc: O(n)
bool wordBreakHelper(string s,unordered_set<string>st,int pivot){
        // base
        if(pivot==s.length()) return true;
        // logic
        for(int i=pivot;i<s.length();i++){ // Get substring from pivot to i
            string sub = s.substr(pivot,i-pivot+1); // substr(startindex,len)
            if(st.find(sub)!=st.end() && wordBreakHelper(s,st,i+1)){ 
                /* else here we can take s as rest of string in that case, and change basecase to s.length==0 */
               return true;
            }
        }
        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return wordBreakHelper(s,st,0);
    }

// wihtout pivot
 bool wordBreakHelper(string s,unordered_set<string>st){
    // base
    // if(pivot==s.length()) return true;
    if(s.length()==0) return true;
    // logic
    for(int i=0;i<s.length();i++){ // Get substring from pivot to i
        string sub = s.substr(0,i+1); // substr(startindex,len)
        if(st.find(sub)!=st.end() && wordBreakHelper(s.substr(i+1),st)){ // 
            return true;
        }
    }
    return false;

}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string>st(wordDict.begin(),wordDict.end());
    return wordBreakHelper(s,st);
}

