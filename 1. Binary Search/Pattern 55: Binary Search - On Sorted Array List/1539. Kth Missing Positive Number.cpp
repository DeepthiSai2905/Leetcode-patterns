#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/kth-missing-positive-number/
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // exmapke: 3 6 8 10 - missing elements to left 
        // missing count=arr[mid]-mid-1
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int missingCount = arr[mid]-mid-1;
            if(missingCount<k){ // go right
            // then kth missing must be after mid
               i=mid+1;
            }
            else j=mid-1;

        }
        // wt is the intuition here?
        // at the end of the loop, i is the first index where the missing count is greater than or equal to k
        // so, the kth missing number is at index i+k
       // ?? - The kth missing number is found at left + k, where left is the smallest index where the missing count exceeds or equals k
        return i+k;
    }
};