#include<bits/stdc++.h>
using namespace std;
/*
9. Palindrome Number, 125. Valid Palindrome, 680. Valid Palindrome II
*/

/*
125.Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/
// two pointers approach - time O(n), space O(1)
bool checkAlphabet(char ch){
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
    }
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(!checkAlphabet(s[i])){
                i++;  continue;
            }
            if(!checkAlphabet(s[j])){
                j--; continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                 i++; j--;
            }
        }
        
        return true;
    }

/*
  680. Valid Palindrome II  
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false

 */
// brute force approach - time O(n^2), space O(1) - TLE
bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                 i++; j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        // no character deletion
        if(isPalindrome(s)) return true;
        // 1 character deletion
        for(int i=0;i<n;i++){ // find all possible strings with one deletion
            string subs = s.substr(0,i)+s.substr(i+1,n);
            if(isPalindrome(subs)) return true;
        }
        return false;
    }

// two pointers approach - time O(n), space O(1) - why to delete chars just move pointers
/*
approach - only find if a palindrome can be formed when opposite ends of characters are not equal
if they are not equal, try deleting either one of them and check if the remaining string is a palindrome
*/
bool isPalindrome(string s,int i,int j) {
        int n=s.length();
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; j--;
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                // delete either one - check which one could fit
              return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
            i++; j--; // move pointers
        }
        return true;
    }

