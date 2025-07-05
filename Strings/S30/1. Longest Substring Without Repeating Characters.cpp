#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string s, find the length of the longest substring without duplicate characters.
 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


// Approach 2: Sliding Window - O(n+n) time and O(1)fixed 26 characters space ( double pass)
/*
Intuition:
1. Use a sliding window to keep track of the current substring without repeating characters.
2. Use a hash set to store the characters in the current substring. 
3. If a character is already in the set, move the left pointer of the window to the right until the character is removed from the set.
5. Continue until the right pointer reaches the end of the string.
*/
int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        int l=0,r=0; // l to r is window
        unordered_set<int>st;
        while(r<n){ // o(n+n)
            char rightChar = s[r];
            if(st.find(rightChar)==st.end()){ // not found
               st.insert(rightChar);
            }
            else{
                // move the left ptr to escpe repeat char
                while(s[l]!=rightChar){
                    st.erase(s[l++]);
                }
                l++; // skip that character and start from next
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }

    // Approach 2: Sliding Window - O(n) time and  O(1)fixed 26 characters space ( single pass)
    /*
    1. Take map (char -> indxe)
    2. if a repeated char is found and it is within the curent window (l to r), then move l to the right of that character
    else if it is not in current window keep the l as it is
    3. if char is not found in map, add it to map with index

    
    */
   int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        int l=0,r=0; // l to r is window
        unordered_map<int,int>mp;
        while(r<n){ // o(n+n)
            char rightChar = s[r];
            if(mp.find(rightChar)==mp.end()){ // not found
               mp[rightChar]=r;
            }
            else{ // found
                int oldOcc = mp[rightChar];
                // if lets say first occ of repeated one index is x, if x is left of l - we dont worry as its not in current window range
                l=max(oldOcc+1,l);
                mp[rightChar]=r;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }