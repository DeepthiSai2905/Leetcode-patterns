#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/search-a-2d-matrix/description/
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

*/
// Linear search - O(m*n) time and O(1) space but each rows are sorted i could apply binary search
// Just apply binary search on each row - O(m*logn) time and O(1) space

/* Optimal approach 1: - 
1. Use binary search on the first column (or last column) to find the row where the target might exist. (lower bound - find immediate greater than or equal to target)
2. Perform binary search in that row.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        // traverse last column to find which row can have target 
        // apply binary search to last column to find target or immediate value which >=target (lower bound)

        int res=-1;
        int low=0, high=m-1;
        int targetRow=-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][n-1] == target) {
                targetRow=mid; break;
            } else if (matrix[mid][n-1] < target) {
                low = mid + 1;
            } else {
                targetRow=mid;
                high = mid - 1;
            }
        }
        if (targetRow == -1) return false; // *** IMPORTANT: [[1]] target=2 case
        // binary search on targetRow to check for target
        int targetCol = binarySearch(matrix[targetRow],target);
        if(targetCol==-1) return false;
        return true;
    }

// Approach 2: Binary Search Optimal - O(log(m*n)) time and O(1) space 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0, j=m*n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int midR=(mid/n), midC=(mid%n);
            if(matrix[midR][midC]==target){
                return true;
            }
            else if(matrix[midR][midC]<target){
                i=mid+1;
            }
            else j=mid-1;

        }
        return false;
    }
};

// https://leetcode.com/problems/search-a-2d-matrix-ii/
// row sorted column sorted - O(m+n) time and O(1) space - cant form a sorted 1d array
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }