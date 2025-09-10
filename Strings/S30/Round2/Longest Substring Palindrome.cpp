#include <bits/stdc++.h>
using namespace std;
/*
Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/

/*
Expand around center and consider both odd and even length palindromes at every index i.
*/
// Approach: Expand Around Center
// Time Complexity: O(n^2) where n is the length of the string
// Space Complexity: O(1) since we are not using any extra space except for variables

string longestPalindrome(string s) {
    int n=s.length();
    if(n<=1) return s;
    int st=0,end=0;
    int max_len=1;
    
    // Odd length
    for(int i = 0; i < n-1; ++i){
        int l = i, r = i;
        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                l--; r++;
            }else
                break;
        }
        int len = r-l-1;
        if(len > max_len){
            max_len = len;
            st = l+1;
            end = r-1;
        }
    }
    
    // Even length
    for(int i = 0; i < n-1; ++i){
        int l = i;
        int r=i+1;
        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                l--; r++;
            }else
                break;
        }
        int len = r-l-1;
        if(len > max_len){
            max_len = len;
            st = l+1;
            end = r-1;
        }
    }
    return s.substr(st,max_len);

}

// some helper funcition to avoid repetitive code for odd and even length palindromes
void helper(int &max_len, int l, int r, int &start, int end, string s){
    int n=s.length();
    while(l>=0 && r<n){
        if(s[l]==s[r]){
            l--; r++;
        }
        else break;
    }
    int windowLen = r-l-1;
    if(windowLen>max_len){
        max_len=windowLen;
        start=l+1;
        end=r-1;
    }
}
string longestPalindrome(string s) {
    int n=s.length();
    if(n<=1) return s;
    int max_len=1, start=0,end=0;
    for(int i=0;i<n-1;i++){
        helper(max_len,i,i,start,end,s);
        helper(max_len,i,i+1,start,end,s);
    }
    return s.substr(start,max_len);
}