#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/string-to-integer-atoi/description/
8. String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

*/

class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
    
    int myAtoi(string s) {
        int n=s.length();
        bool neg=false;
        int i=0;

        // 1. remove leading whitespaces
        while(i<n && s[i]==' ') i++;

       // check for + or - sign
        if(i<n && (s[i]=='-' || s[i]=='+')){
            neg=(s[i]=='-');
            i=i+1;
        }
         
        // after sign they should not have whitespaces
        long res=0;

        // stop reading when you reach non-digits
        while(i<n && isDigit(s[i])){

            // conversion
            int val = (s[i]-'0');
            // INT_MAX = 2^31-1, INT_MIN = -2^31
            // if(res>INT_MAX || res<INT_MIN){
            //     overflow=true;
            // }

            //rounding
            if (res > (INT_MAX - val) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }
            res=res*10+val;
            i++;
        }
        // if(overflow) neg ? INT_MIN : INT_MAX;
        return neg ? res*-1 : res;
        
    }
};