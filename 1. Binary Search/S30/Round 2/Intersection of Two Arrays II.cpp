
#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // o(m+n) time and o(m) space
        // Intuition: Use hash map to store frequency of elements in smaller array and then check
        // if the element is present in bigger array, add it to result and decrease frequency in map
        int m=nums1.size(); // considering m small
        int n=nums2.size();
        if(m>n) return intersect(nums2,nums1);
        vector<int>result;
        unordered_map<int,int>mp;
        for(int num:nums1) mp[num]++;
        for(int ele:nums2){
            if(mp[ele]>0){
                result.push_back(ele);
                mp[ele]--;
            }
        }
        return result;
    }


    // If array is sorted, we can use binary search 
    int firstOccurence(vector<int>& nums, int target, int i,int j){
        int res = -1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                res=mid;
                j=mid-1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return res;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); // considering m small
        int n=nums2.size();
        if(m>n) return intersect(nums2,nums1);

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        // mlogn - search each element of smaller array in bigger array using binary search
        vector<int>result;
        int low=0,high=n-1;
        for(int num:nums1){
            int bsIndx = firstOccurence(nums2,num, low,high); // handling duplicates
            if(bsIndx==-1) continue;
            low=bsIndx+1;
            result.push_back(num);
        }
        return result;
    }