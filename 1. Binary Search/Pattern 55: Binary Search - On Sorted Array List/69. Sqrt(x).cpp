#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/sqrtx/description/
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we 
*/

/*
Intuition: sqrt(x) - take range from low=1 to high=x take mid and check if mid*mid==x return mid
if(mid*mid>x) j=mid-1 // move left to get smaller value of mid
else i=mid+1 // move right to get larger value of mid

*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low=1,high=x;
        while(low<=high){
            int mid=low+(high-low)/2; // mid* mid can be out of bound for int
            long long square = 1LL * mid * mid;  // use long long to avoid overflow
            if(square==x) return mid;
            else if(square<x) { // increase mid - go right
               low=mid+1;
            }
            else high=mid-1;
        }
        /*  why?? The loop runs while low <= high.

            Eventually, low becomes greater than high, so the loop stops.
            At this point:
            Every number less than or equal to high has a square ≤ x.
            Every number greater than or equal to low has a square > x
            So high is the last safe number — the biggest one that didn’t overshoot.

            Find the biggest number such that number * number <= x.
            high is the last value where mid * mid <= x. So, high is the floor of sqrt(x).
        */
        return high;
    }
};