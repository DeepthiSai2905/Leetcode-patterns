#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(); // here it is sure that peak is in middle of the array, so no need to check for edge cases like first and last element
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid+1]<arr[mid]){
                return mid;
            }
            if(arr[mid]<arr[mid+1]){ // increasing slope to right
              low=mid+1;
            }
            else high=mid-1;
        }
        return -1;

    }
};