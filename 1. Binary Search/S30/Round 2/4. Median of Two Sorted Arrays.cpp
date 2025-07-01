#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

// Approach 1: Using 2 pointers - O(m+n) time and O(1) space
// Intuition: Two pointers for 2 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        int count=0;
        int medVal= (m+n)/2;
        int prev,curr; // track current value so when you reach m+n/2 elements, you can return median
        while(count<=medVal){
            prev=curr;
            if(i<m && j<n){
                if(nums1[i]<=nums2[j]) {
                    curr=nums1[i++];
                }
                else{
                    curr=nums2[j++];
                }
            }
            else if(i<m && j==n){
                curr=nums1[i++];
            }
            else if(j<n && i==m){
                curr=nums2[j++];
            }
            count++;
        }
        if((m+n)%2==0) return (prev+curr)/2.0;
        else return curr/1.0;

    }
};

// Approach 2: Using Binary Search partition - O(log(min(m,n))) time and O(1) space - refer notes
/* Intuition:
1. To sort the merged array we can use binary search to find the partition point in the smaller array, first take mid as partition point. (parX=mid)
2. Calculate parY so that both the arrays are divided into two/almost two halves. - parX + parY = (m+n)/2
3. Consider immediate left and right elements of the partition point in both arrays. lets say X1, Y1(left side) X2, Y2(right side)
   (for odd length i want to keep one extra to right side so that I can return max of left side as median)
4. Try to find right partition such that all elements in the left half are less than or equal to all elements in the right half, which is X1 <= Y2 and X2 <= Y1 this satisfies.
5. Median can be calculated from just 4 elements x1,x2,y1,y2. if (m+n) is even median is (max(x1,x2)+min(y1,y2))/2, if (m+n) is odd median is  min(Y1,Y2);
6. if X1>Y2 - partition becomes left tilted, so we need to move partition point to left side, i.e. high=parX-1;
7. if X2>Y1 - partition becomes right tilted, so we need to move partition point to right side, i.e. low=parX+1;

*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make m small - nums1 small
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int low=0,high=m;
        while(low<=high){
            int parX = low+(high-low)/2;
            int parY = (m+n)/2 - parX;
            double X1 = parX==0 ? INT_MIN : nums1[parX-1];
            double X2 = parY==0 ? INT_MIN : nums2[parY-1];
            double Y1 = parX==m ? INT_MAX : nums1[parX];
            double Y2 = parY==n ? INT_MAX : nums2[parY];
            if(X1<=Y2 && X2<=Y1){
                // correct partition
                if((m+n)%2 ==0) return (min(Y1,Y2)+ max(X1,X2))/2;
                else return min(Y1,Y2);
            }
            else if(X1>Y2){
                high=parX-1;
            }
            else low=parX+1;
        }
        return -1;

    }