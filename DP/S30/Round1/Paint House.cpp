#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/paint-house/description/
There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.

 

Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: costs = [[7,6,2]]
Output: 2
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        for(int i=1;i<n;i++){
            costs[i][0]+=min(costs[i-1][1],costs[i-1][2]);
            costs[i][1]+=min(costs[i-1][0],costs[i-1][2]);
            costs[i][2]+=min(costs[i-1][0],costs[i-1][1]);
        }
        // min in last row
        return min(costs[n-1][0],min(costs[n-1][1],costs[n-1][2]));
    }
};
