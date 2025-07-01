#include<bits/stdc++.h>
using namespace std;
/*
49. Group Anagrams, 242. Valid Anagram
*/

/*
242. Valid Anagram
check if two strings are anagrams of each other
best way - size shd be equal, then count frequency of each character in both strings
*/
bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
             count[t[i]-'a']--;
        }
        for(int c:count){
            if(c!=0) return false;
        }
        return true;
    }

/*49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

*/

// Brute force approach - time O(n * klogk), space O(n*k) - TLE
/*
1. create a map of sorted string -> vector of strings
2. for each string in strs, sort it and add it to the map 
3. Then return the values of the map as a vector of vectors
*/

// better force approach - time O(n * (k+26)), space O(26) (reusing count array for all strings) 
/*
1. create a map of sorted string -> vector of strings
2. for each string in strs, instead of sorting take a count array and make a decoded string
like eat, ate, tea all have a decoded string a1e1t1
3. Then return the values of the map as a vector of vectors
*/

// Optimal approach - make a single decode string for all anagrams, like tea,eat all can have a1e1t1 - kind of decoded string
string decodeString(string s){
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        string res;
        for(char c='a';c<='z';c++){
           if(v[c-'a']!=0){
            res+= (c+(v[c-'a']+'a'));
           } 
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>mp;
        for(string s:strs){ // o(n)
            string decode=decodeString(s); // o(k+26) - k is length of string
            mp[decode].push_back(s);
        }
        for(auto x:mp){// worst case - o(n)
            res.push_back(x.second);
        }
        return res;
    }