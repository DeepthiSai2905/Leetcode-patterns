/*
https://leetcode.com/problems/powx-n/description/
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

*/
double myPow(double x, int n) { // o(log n) time and O(1) space
    long k=n;
    if(k==0) return 1;
    if(k<0){
        x=1/x;
        k=-k;
    }  
    double res=1.0;
    while(k>0){
        if(k%2!=0) res*=x;  // odd
        x=x*x; // base is squared
        k/=2; // exponent is halved
    }
    return res;
}