#include<stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/array-partition/description/
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 
*/

int arrayPairSum(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    // sort and then take sum of 1st elements in pairs(min of 2 numbers)
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i+=2){
        sum+=nums[i];
    }
    return sum;
}

/*
optimised intuition - optimise sorting to reduce time complexity
take window of min and max element of array
sorting nlogn -> optimise counting sort n
*/

int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX,maxi=INT_MIN;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
            mp[nums[i]]++;
        }
        int skipFlag=false; // if current element is computed, skip next
        // window from mini to maxi
        for(int num=mini;num<=maxi;num++){
            int currCount=mp[num];
            if(currCount<1) continue;
            while(currCount>0){
                if(skipFlag){ // skip
                    currCount--;
                    skipFlag=false;
                }else{ // dont skip 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }
                mp[num]=0;
            }
        }
        return sum;
    }
// we dont need to traverse over all currCount in above soln
int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX,maxi=INT_MIN;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
            mp[nums[i]]++;
        }
        int skipFlag=false; // if current element is computed, skip next
        // window from mini to maxi
        for(int num=mini;num<=maxi;num++){
            int currCount=mp[num];
            if(currCount<1) continue;
            // we dont need to iterate over freq 
            /*if(skipFlag){
                currCount--; // skip one
                int rem=currCount%2;
                sum+=num*(currCount/2);
                currCount/=2;
                // now skipflag will be false
                skipFlag=false;
                if(rem==1) { 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }
            }
            else{ // dont skip
                sum+=num*(currCount/2);
                int rem=currCount%2;
                // now skipflag will be false
                if(rem==1) { 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }

            }*/
            if(skipFlag){
                    currCount--; // skip one
                    skipFlag=false;
            }
            int rem=currCount%2;
            sum+=num*(currCount/2);
            currCount/=2;
            if(rem==1) { 
                sum+=num;
                currCount--;
                skipFlag=true;
            }
            
            
        }
        return sum;
    }