#include<bits/stdc++.h>
using namespace std;
/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

https://leetcode.com/problems/repeated-dna-sequences/description/
*/

vector<string> findRepeatedDnaSequences(string s) {
    int n=s.length();
    if(n<10) return {};
    unordered_set<string>st;
    unordered_set<string>result;
    for(int i=0;i<= n-10;i++){
        string sub = s.substr(i,10); //o(10)
        if(st.find(sub)==st.end()){ // here we are repeatedly checking the same characters
            st.insert(sub);
        }
        else{
            result.insert(sub);
        }
    }
    
    return vector<string>(result.begin(),result.end());
}

// consider kind of sliding window approach - consider removing first character and adding the next character in next window
