#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/custom-sort-string/description/
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 m- order size, n - s size

Example 1:

Input: order = "cba", s = "abcd"

Output: "cbad"

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "bcafg", s = "abcd"

Output: "bcad"

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

*/

//Brute force - O(m*n) time and O(1) space
string customSortString(string order, string s) {
        string result;
        for(char cho:order){ // check for each of its occurence in s
           for(char chs:s){
             if(chs==cho){ // search cho in s - optimisation hashset/hashmap - need count so hashmap
                result+=chs;
             }
           }
        }
        for(char chs:s){
            if(order.find(chs)==string::npos){ // not found
                result+=chs;
            }
        }
        return result;
    }
// optimiastion - hashmap - search optimise and freq count - time o(m+n) o(1) space 
string customSortString(string order, string s) {
        string result;
        unordered_map<int,int>mp;
        for(char chs:s) mp[chs]++;
        for(char cho:order){ // check for each of its occurence in s
            while(mp[cho]>0){ // search cho in s - optimisation hashset/hashmap - need count so hashmap
                result+=cho;
                mp[cho]--;
            }
        }
        for(auto m:mp){
            int count=m.second;
            while(count>0){ // add all freq elements
                result+=m.first;
                count--;
            }
        }
        return result;
    }


