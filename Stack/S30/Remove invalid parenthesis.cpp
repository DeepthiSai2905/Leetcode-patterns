#include <bits/stdc++.h>
using namespace std;
/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]


*/

bool isValid(string s){
        int count=0;
        for(char ch:s){
            if(ch=='(') count++;
            else if(ch==')') count--;
            if(count<0) return false;
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>result;
        unordered_set<string>vis;
        if(s.length()==0) return {};
        // dfs+backtracking or bfs
        queue<string>Q;
        Q.push(s);
        vis.insert(s);
        bool foundValid=false;
        while(!Q.empty()){
            int size=Q.size();
            for(int i=0;i<size;i++){
                string sub = Q.front(); Q.pop();
                if(isValid(sub)){
                    foundValid=true;
                    result.push_back(sub);
                    // vis.insert(sub);
                }
                // now apply for loop recursion for each substring if not valid
                else {
                    if(!foundValid){// then only create babies
                      for(int j=0;j<sub.length();j++){
                        if(sub[j]>='a' && sub[j]<='z') continue;
                        string child = sub.substr(0,j)+sub.substr(j+1);
                        // process only unvisited nodes
                        if(vis.count(child)==0){
                            Q.push(child);
                            vis.insert(child);
                        }
                      }
                    }
                }
            }
        }
        return result;

        
    }


    // DFS
bool foundValid=false;
     int maxLen = 0;

    bool isValid(string s){
        int count=0;
        for(char ch:s){
            if(ch=='(') count++;
            else if(ch==')') count--;
            if(count<0) return false;
        }
        return count==0;
    }
    void dfs(string s, unordered_set<string>&vis,unordered_set<string>&result){
        //base
        if (vis.count(s)) return;

        // logic 
        vis.insert(s);
        if (isValid(s)) {
            int len = s.length();
            if (len > maxLen) {
                result.clear();
                result.insert(s);
                maxLen = len;
            } else if (len == maxLen) {
                result.insert(s);
            }
            return; // no need to remove more if valid
        }
        // now apply for loop recursion for each substring if not valid
        else {
            for(int j=0;j<s.length();j++){
                if(s[j]>='a' && s[j]<='z') continue;
                string child = s.substr(0,j)+s.substr(j+1);
                // process only unvisited nodes
                if(vis.count(child)==0){
                    dfs(child,vis,result);
                }
            }
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        if(s.length()==0) return {};
        unordered_set<string>result;
        unordered_set<string>vis;
        dfs(s,vis,result);
        return vector<string>(result.begin(), result.end());
    }