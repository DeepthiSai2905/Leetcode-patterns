#include<bits/stdc++.h>
using namespace std;
/*
28. Find the Index of the First Occurrence in a String
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length();
        int i=0,j=0;
        while(i<=n-m){
            if(haystack[i]==needle[0]){ // if found first char
               int k=i,j=0;
               while(haystack[k]==needle[j]){
                k++; j++;
                if(j==m) return i; // match found
               }
               // if match not found
               i++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};

// Optimised - KMP algorithm - O(n+m) time and O(m) space
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length();
        if(m>n) return -1;
        const int mod = 1e9 + 7;
        long hashP=0,k=26;
        for(char ch:needle){
            hashP = (hashP*k+(ch-'a'+1))%mod;
        }
        
        long hashS=0;
        // long long power = pow(k, m-1);
        long long power = 1;
        for (int i = 1; i < m; i++) {
            power = (power * k) % mod;
        }
        for(int i=0;i<n;i++){
            long out=0;
            if(i>=m){ // actual sliding window
               // outgoing char
               char outChar = haystack[i-m];
                out = ((outChar-'a'+1)*power)%mod;
                hashS= (hashS-out+mod)%mod;
            }
            hashS = (hashS*k+(haystack[i]-'a'+1))%mod; // add current char
            
            if(hashS==hashP) return i-m+1;
        }

        
        return -1;
    }
};