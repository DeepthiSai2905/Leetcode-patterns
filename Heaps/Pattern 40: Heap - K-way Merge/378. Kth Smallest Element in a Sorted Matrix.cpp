#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

*/
// Approach 1: two pointers Binary Search - O(n*log(max-min)) time and O(1) space
class Solution {
public:
    
    int countKElements(vector<vector<int>>& matrix, int mid){
        int n=matrix.size();
        int row=n-1,col=0;
        int count=0;
        while(row>=0 && col<n){
            if(matrix[row][col]>mid){ 
                // that row do not have elements less than mid
                row--;
            }
            else{
                // all above row elements are <=(row value) so also <=8 
                // kind of count straight up from that row
                count+=(row+1); 
                col++; // move to next column
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while(low<=high){ // log(high-low)
            int mid = low+(high-low)/2;
            int count = countKElements(matrix,mid); // o(n)
            if(count<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

// Approach 2: Heap - O(n*logn) time and O(n) space
/*
// similar to https://leetcode.com/problems/merge-k-sorted-lists/description/
Intuition:
1. Use a min-heap to store the elements of the matrix.
2. Iterate through the matrix and push each element into the min-heap.
3. Pop the smallest element from the heap k times to get the kth smallest element.          
4. The kth smallest element will be the last popped element.

*/

class Solution {
public:
    
    struct Cell {
    int val, r, c;
    bool operator>(const Cell& other) const {
        return val > other.val;
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
    priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

    // Push the first element of each row
    for (int i = 0; i < min(n, k); i++) {
        minHeap.push({matrix[i][0], i, 0});
    }

    int count = 0, result = 0;
    while (count < k) {
        Cell curr = minHeap.top();
        minHeap.pop();
        result = curr.val;
        count++;

        int r = curr.r, c = curr.c;
        if (c + 1 < n) {
            minHeap.push({matrix[r][c + 1], r, c + 1});
        }
    }

    return result;
    }
};