#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/multiply-strings/description/
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

*/
// Brute force approach - time O(n*m), space O(1) - TLE for large inputs works till 10*10
class Solution {
public:
    long long multiplyDigit(string num1, char d){
        if(d=='0') return 0;
        int m=num1.length();
        int carry=0;
        long long mul=0;
        long long pro=1;
        for(int i=m-1;i>=0;i--){
            long long prod=(num1[i]-'0')*(d-'0')+carry;
            mul+=(pro * (prod%10));
            carry=(prod/10);
            pro*=10;
        }
        if(carry>0){
            mul+=(pro*carry);
        }
        return mul;
    }
    string multiply(string num1, string num2) { 
        int n = num2.length();
        long long result=0;
        long long pro=1;
        for(int i=n-1;i>=0;i--){ // o(n)
            long long multipliedVal = multiplyDigit(num1,num2[i]); // o(m)
            result+= (pro*multipliedVal); 
            pro=pro*10;
        }
        return to_string(result);
    }
};
/* like pen-paper simulation - use matrix to store intermediate results
time complexity is fine, but interger overflow is the problem

take m+n as size of result vector - no need of using 2d matrix , use same 1d vector for every digit multiplication
*/
class Solution {
public:
    string multiply(string num1, string num2) { 
        if(num1=="0" || num2=="0") return "0"; 
        int n = num2.length();
        int m=num1.length();
        vector<int> res(n + m, 0);
        for(int i=n-1;i>=0;i--){ // o(n)
            // process num1
            for(int j=m-1;j>=0;j--){
                int prod=(num1[j]-'0')*(num2[i]-'0');
                int sum = res[i + j + 1] + prod;
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10; // carry
            }
        }
        // Convert res vector to string
        string result;
        int k=res.size();
        int i=0;
        while(i<k && res[i]==0) i++;
        while(i<k) {
            result += to_string(res[i++]);
        }
        return result.empty() ? "0" : result;
    }
};