#include<stdc++.h>
using namespace std;
/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/
// brute force tc-o(n^2) sc-o(1)
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int>result;
    int n=temperatures.size();
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i+1;j<n;j++){
            if(temperatures[j]>temperatures[i]){
                flag=true;
                result.push_back(j-i);
                break;
            } 
        }
        if(!flag) result.push_back(0);
    }
    return result;
}

// stack - tc-o(n) sc-o(n)
/*
monotonic stack - stack is either increasing or decreasing
monotonic increasing stack - top element smallest
monotonic decreasing stack - top element largest
monotonic stack - used to find next greater element, next smaller, prev smaller, stock span, histogram, daily temperatures, next greater element in circular array, next greater element in right side of array, next greater element in left side of array, next smaller element in right side of array, next smaller element in left side of array, next greater element in right side of array
https://leetcode.com/problems/daily-temperatures/description/

*/
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int>result(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && temperatures[i]>temperatures[st.top()]){
            int poppedIdx = st.top();
            result[poppedIdx]=i-poppedIdx;
            st.pop();
        }
        st.push(i);
    }
    return result;
}