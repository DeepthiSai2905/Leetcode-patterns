#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/integer-to-english-words/description/
Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

*/
class Solution {
public:
    vector<string> units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> suffix = {"","Thousand", "Million", "Billion"};
    
    string trim(const string& str) {
        int start = str.find_first_not_of(' ');
        int end = str.find_last_not_of(' ');
        return (start == string::npos) ? "" : str.substr(start, end - start + 1);
    }f

    string decodeTriplet(int curr){
        // 543
        if(curr>=100){
            return units[curr/100] + " Hundred " + decodeTriplet(curr%100);
        }
        else if(curr>=20){
            return tens[curr/10] + " " + units[curr%10];
        }
        else{
            return units[curr];
        }
        return "";
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        string result;
        int i=0;

        // chunk of triplets
        while(num>0){
            if(num%1000!=0){
                string triplet = trim(decodeTriplet(num%1000));
                // result = triplet + " " + suffix[i] +" " + result; 
                if (!triplet.empty()) {
                    result = triplet + (suffix[i].empty() ? "" : " " + suffix[i]) + (result.empty() ? "" : " " + result);
                }
            }
            i++;
            num=num/1000;
        }
        // trim ending spaces
        return trim(result);
    
    }
};
