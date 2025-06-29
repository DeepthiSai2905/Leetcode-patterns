#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-in-mountain-array/description/
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.


*/

/*
Things to clarify:
no duplicates in left and right side of the peak

Intuition:
// ascending from 0 to peak, then descending
// first find peak index
// search in asc part for target - if found return first occ 
// search in descending part for target
*/

class Solution {
public:
   int findPeakElement(MountainArray &nums) {
        int n=nums.length();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid>0 && mid<n-1 && nums.get(mid)>nums.get(mid-1) && nums.get(mid)>nums.get(mid+1)) return mid;
            else if(nums.get(mid)<nums.get(mid+1)) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
    int binarySearch(MountainArray &nums,int i, int j, int target, int asc) { 
        int res=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums.get(mid)==target) {
                return mid;
            }
            if(asc){
                if(nums.get(mid)<target) i=mid+1;
                else j=mid-1;
            }
            else{
                if(nums.get(mid)>target) i=mid+1;
                else j=mid-1;
            }
        }
        return res;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        // ascending from 0 to peak, then descending
        // first find peak index
        // search in asc part for target - if found return first occ 
        // search in descending part for target
        int peakIndex = findPeakElement(mountainArr);
        // left part of sorted array 0 to peakindex
        int findTargetIndexLeft = binarySearch(mountainArr,0,peakIndex, target, true);
        if(findTargetIndexLeft!=-1) return findTargetIndexLeft; // if found no need to search in right part, as we need first occurence
        // decreasing so find lastocc from back
        int findTargetIndexRight = binarySearch(mountainArr,peakIndex+1,n-1, target, false);
        return findTargetIndexRight;
        
    }
};