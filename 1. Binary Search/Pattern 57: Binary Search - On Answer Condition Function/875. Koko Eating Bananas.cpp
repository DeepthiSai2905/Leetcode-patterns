#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/koko-eating-bananas/description/
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/
// take speed (bananas/hr) to k and it goes from 1 to max element in piles
// for each speed k, calculate time taken to eat all bananas and check if it is less than or equal to h
// time - O(n*k) where n is size of piles and k is max element in piles
class Solution {
public:
    long calcTime(vector<int>& piles,int speed){
        long time=0;
        for(int num:piles){
            int rem=(num%speed) ? 1:0;
            time+=(num/speed)+rem;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // speed k can be 1 to max element from piles
        int n=piles.size();
        int maxElement=-1;
        for(int num:piles) maxElement=max(maxElement,num);
        for(int k=1;k<=maxElement;k++){
            long time = calcTime(piles,k);
            if(time<=h) return k;
        }
        return -1;
    }
};

// we can apply binary search on k
// tc: O(n*log(maxElement)) where n is size of piles and maxElement is max element in piles
long calcTime(vector<int>& piles,int speed){
        long time=0;
        for(int num:piles){
            int rem=(num%speed) ? 1:0;
            time+=(num/speed)+rem;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // speed k can be 1 to max element from piles
        int n=piles.size();
        int maxElement=-1;
        int res=-1;
        for(int num:piles) maxElement=max(maxElement,num);
        int low=1,high=maxElement;
        while(low<=high){
            int mid=low+(high-low)/2;
            long time = calcTime(piles,mid);
            if(time<=h){
                res=mid; // lesser value of k is possible so go left
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }