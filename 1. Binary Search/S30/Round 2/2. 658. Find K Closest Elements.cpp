#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/find-k-closest-elements/

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3 Output: [1,2,3,4]
Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]
*/

// Approach 1: Using heap - O(nlogk + klogk) time and O(k) space
class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first){ // distance same
               return a.second<b.second; // a has low priority, b on top - max heap
            }
            return a.first<b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        // k closest - maxheap
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq; // dist,value
        for(int num:arr){ // nlogk
            pq.push({abs(x-num),num});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(),result.end()); // klogk - asked in question to return sorted result
        return result;

    }
};
// Approach 2: Using two pointers - O(n+k) time and O(k) space
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-1;
        while(r-l+1>k){
            int distL = abs(x-arr[l]);
            int distR = abs(x-arr[r]);
            if(distL<distR) r--;
            else if(distL>distR) l++;
            else { // move pointer which has greater value 
              if(arr[l]>arr[r]) l++;
              else r--;
            }
        }
        vector<int>result;
        for(int i=l;i<=r;i++){ // o(k)
            result.push_back(arr[i]);
        }
        // time - o(n), space-o(1)
        return result;

    }
};

// Approach 3: Using Binary search - O(logn+k) time and O(1) space
class Solution {
public:
    int findClosestIndex(vector<int>& arr,int x) {
        int low=0,high=arr.size()-1;
        int close=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            // 1. diff of mid is less than close then close becomes mid
            // 2. when they have equal diff -> prefer smaller one
            if((abs(arr[mid]-x) < abs(arr[close]-x)) || 
                (abs(arr[mid]-x) == abs(arr[close]-x) && arr[mid]<arr[close])
            ) close=mid;

            if(arr[mid]<x) low=mid+1;
            else high=mid-1;
        }
        return close;

    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // sorted so we could use binary search
        // 1. idea is to find closest Index to x
        // 2. find k closest neigbors around closest index
         
         int n=arr.size();
        int closeIndex = findClosestIndex(arr,x);
        int left=closeIndex-1;
        int right=closeIndex+1;
        vector<int>result;
        result.push_back(arr[closeIndex]);
        k--;
        while(k--){
            if(left<0) result.push_back(arr[right++]);
            else if(right>=n) result.insert(result.begin(),arr[left--]);
            else if(abs(arr[left]-x)>abs(arr[right]-x)){ // right is closer
               result.push_back(arr[right++]);
            }
            else{
                result.insert(result.begin(),arr[left--]);
            }
        }
        return result;
    }
};

// Approach 4: Using Binary search - O(log(n-k)+k) time and O(1) space

 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // sorted so we could use binary search
        // maintain a k sized window and move the window mid->mid+k window
        // 1. check if mid is correct start point or not
         
        int n=arr.size();
        vector<int>result;
        int low=0,high=n-k;
        while(low<high){
            int mid=low+(high-low)/2; // window start
            int end=mid+k; // window end
            int distStart = x-arr[mid];
            int distEnd = arr[end]-x;
            if(distStart>distEnd){ // closer to end, eliminate start half
               low=mid+1;
            }
            else high=mid; // closer to start, eliminate end half
        }
        for(int i=low;i<low+k;i++) result.push_back(arr[i]);
        return result;
    }