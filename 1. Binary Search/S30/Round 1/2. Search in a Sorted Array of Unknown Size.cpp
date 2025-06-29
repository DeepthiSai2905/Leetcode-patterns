/*
https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/
https://www.geeksforgeeks.org/dsa/find-position-element-sorted-array-infinite-numbers/

Given a sorted array arr[] of infinite numbers. The task is to search for an element k in the array.
Examples:

Input: arr[] = [3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170], k = 10
Output: 4
Explanation: 10 is at index 4 in array.

Input: arr[] = [2, 5, 7, 9], k = 3
Output: -1
Explanation: 3 is not present in array.
*/

// Approach 1: while loop untill i find the element - O(n)
int searchInInfiniteArray(int arr[], int k) {
    int i = 0;
    while (arr[i] == k) {
        if (arr[i] == k) {
            return i;
        }
        i++;
    }
}

// Approach 2: Binary search - O(log n)
/* Intuition:
// initial idea - i can take a fixed size range like 10 and keep going to next 10 elements if my element lies in correct window i would do binary search in that range.
better approach - 
1. Start with a small range and double it until the element is found or the range exceeds the size of the array.(low=0,high=1)
2. moving on - double high and move low to high (search window)
2. Once the range is found, perform a binary search within that range to find the element.
3. If the element is not found, return -1. 
*/

int binarySearch(int arr[], int low, int high, int k) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}
int searchInInfiniteArrayOptimise(int arr[], int k) {
    int low=0,high=1;
    // Find the range where the element might be present
    while (arr[high] < k) {
        low = high;
        high *= 2; // Double the range
    }
    int index = binarySearch(arr, low, high, k);
    return index;
}
