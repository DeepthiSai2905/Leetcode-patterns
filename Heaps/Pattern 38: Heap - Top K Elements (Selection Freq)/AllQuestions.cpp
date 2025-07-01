#include<bits/stdc++.h>
using namespace std;
/*215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();   
}

/*
347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<vector<int>>v(n+1);
        for(auto itr:mp){ // O(n)
            v[itr.second].push_back(itr.first);
        }
        for(int i=n;i>0 && result.size()<k;i--){ // o(n)
            for(auto num: v[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};

/*
451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/description/
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s) mp[ch]++;

        int n=s.length();
        string result;
        vector<vector<char>>v(n+1);
        for(auto itr:mp){ // O(n)
            v[itr.second].push_back(itr.first);
        }
        for(int i=n;i>0;i--){ // o(n)
            for(auto ch: v[i]){
                for(int count=0;count<i;count++){
                    result+=ch;
                }
            }
        }
        return result;

    }
};

/*
506. Relative Ranks
https://leetcode.com/problems/relative-ranks/description/
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
*/
vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        vector<pair<int, int>> v;
        vector<string> ans(size);

        for (int i = 0; i < size; i++) {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end(), greater<>{});
        for (int i = 0; i < size; i++) {
            if (i == 0) 
                ans[v[i].second] = "Gold Medal";
            else if (i == 1)
                ans[v[i].second] = "Silver Medal";
            else if (i == 2)
                ans[v[i].second] = "Bronze Medal";
            else 
                ans[v[i].second] = to_string(i + 1);
        }
        return ans;
    }

/*
703. Kth Largest Element in a Stream
Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8
*/
class KthLargest {
public:
    int len;
    priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        len=k;
        for(int num:nums){ // nlogk
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) { 
        pq.push(val);
        if(pq.size()>len) pq.pop();
        return pq.top();
    }
};



/*973. K Closest Points to Origin,
https://leetcode.com/problems/k-closest-points-to-origin/description/
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>result;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist = x*x+y*y;
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            int index = pq.top().second;
            result.push_back(points[index]);
            pq.pop();
        }
        return result;
    }

/*1046. Last Stone Weight
https://leetcode.com/problems/last-stone-weight/description/
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1


*/
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int stone:stones){ // o(nlogn)
            pq.push(stone);
        }
        while(pq.size()>1){
            int y=pq.top(); pq.pop();
            int x=pq.top(); pq.pop();
            if(x!=y){
                pq.push(y-x);
            }
        }
        return pq.empty() ? 0: pq.top();
    }

/*2558. Take Gifts From the Richest Pile
https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
Return the number of gifts remaining after k seconds.

 

Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
*/
long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int gift:gifts){
            pq.push(gift);
        }
        while(k--){
            int val = pq.top(); pq.pop();
            int sqrtVal = sqrt(val); pq.push(sqrtVal);
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top(); pq.pop();
        }
        return sum;
    }