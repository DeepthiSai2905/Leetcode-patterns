#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// Brute approach - o(n*26) time complexity, o(1) space complexity
class Solution {
public:
    bool checkAnagram(vector<int>scount,vector<int>pcount){
        for(int i=0;i<26;i++){
            if(scount[i]!=pcount[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        vector<int>result;
        if (n < m) return result;
        // brute - sliding window - check each window for anagram
        vector<int>res;
        vector<int>pcount(26,0);
        vector<int>scount(26,0);
        for(char ch:p){
            pcount[ch-'a']++;
        }
        // first m elements only
        for(int i=0;i<m;i++){
            scount[s[i]-'a']++;
        }
        if(checkAnagram(scount,pcount)) result.push_back(0); // first window
        for(int i=m;i<n;i++){ // o(n)
            scount[s[i-m]-'a']--; // remove outgoing // next to this is first index of window
            scount[s[i]-'a']++; // add incoming
            if(checkAnagram(scount,pcount)){ // o(26)
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};

// optimal appraoch - o(n) time complexity, o(1) space complexity
/*
Intuition is take matchcount variable to keep track of unique matches in the window
manage incoming and outcoming characters in the sliding window
If matchCount is equal to the size of the map, it means all characters in p are matched in the current window of s.
We can then add the starting index of the window to the result vector.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        vector<int>result;
        if (n < m) return result;
        // optimal 
        unordered_map<int,int>mp; // p string map
        for(char ch:p){
            mp[ch]++;
        }
        int matchCount=0;
        for(int i=0;i<n;i++){

            // incoming processing
            char in=s[i];
            if(mp.find(in)!=mp.end()){
                mp[in]--;
                if(mp[in]==0){ // unique match coming into window
                 matchCount++;
                }
            }
            // outgoing possible only from mth
            if(i>=m){
                char out=s[i-m];
                if(mp.find(out)!=mp.end()){
                    mp[out]++; // would have been a match in prev window
                    if(mp[out]==1){ // unique match going out of window
                      matchCount--;

                    }
                }
            }
            if(matchCount==mp.size()){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};