#include<stdc++.h>
using namespace std;
/*

https://leetcode.com/problems/container-with-most-water/
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

int maxArea(vector<int>& A) {
    int maxAreaCalc = 0;
    int n=A.size();
    int i=0,j=n-1;
    while(i<j){
        int currArea = min(A[j],A[i])*(j-i);
        if(currArea>maxAreaCalc) maxAreaCalc=currArea;
        if(A[i]<A[j]){
            i++;
        }
        else j--;
        
    }
    return maxAreaCalc;

}