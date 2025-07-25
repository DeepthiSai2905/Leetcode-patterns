#include<stdc++.h>
using namespace std;
/*

https://leetcode.com/problems/trapping-rain-water/description/
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
water lock - when u have taller left and taller right, then only water can be trapped
for max water trap - min(leftMax, rightMax) - height[i] for each index i

*/
// bruteforce tc - o(n^2) sc - o(1)
int trap(vector<int>& height) {
        // brute -> trap possible - left taller right taller
        int totalArea=0,currArea;
        int n=height.size();
        for(int i=0;i<n;i++){
            int leftMax=height[i], rightMax=height[i];
            for(int j=0;j<i;j++){
                leftMax=max(leftMax,height[j]);
            }
            for(int j=n-1;j>i;j--){
                rightMax=max(rightMax,height[j]);
            }
            currArea=min(leftMax, rightMax)-height[i];
            totalArea+=currArea;

        }
        return totalArea;
    }

// tc - o(3n) sc - o(n) - using arrays to store leftMax and rightMax
int trap(vector<int>& height) {
        // brute -> trap possible - left taller right taller
        int totalArea=0,currArea;
        int n=height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            currArea=min(leftMax[i], rightMax[i])-height[i];
            totalArea+=currArea;
        }
        return totalArea;
    }
// can use only suffixmax and remember prefixmax with a variable - o(2n) to o(n) space
// tc - o(n) sc - o(1) - using 2 pointers

/*
min(leftMax, rightMax) - height[i] for each index i
intuition is i either neeed leftmax or rightmax (smaller one) - smaller building playing major role in trapping water
we need traversal from left and right - because going from left to right traversal we dont see right portion and vice versa


*/
int trap(vector<int>& height) {
        // optimal -> trap possible - left taller right taller
        int totalArea=0;
        int n=height.size();
        int i=0,j=n-1;
        int rightMax,leftMax;
        while(i<=j){// always stop/endup at tallest building
            if(height[i]<=height[j]){ // right Max - check leftmax (as we need min value)
                if(leftMax>height[i]) {
                    totalArea += leftMax-height[i];
                }else{
                    leftMax = height[i];
                }
                // left processed so move forward
                i++;
            }else{
                if(rightMax>height[j]){
                    totalArea += rightMax-height[j];
                }else{
                    rightMax = height[j];
                }
                j--;
            }
        }
        return totalArea;
    }