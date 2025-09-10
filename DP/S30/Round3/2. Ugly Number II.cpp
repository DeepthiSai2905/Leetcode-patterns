#include<bits/stdc++.h>
using namespace std;
/*
uGly Number II
https://leetcode.com/problems/ugly-number-ii/description/
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

*/

// soln1: check from 1 to x value, till u get n ugly numbers and check if it is ugly or not
bool isUgly(int n) {
        while(n){
            if(n%2==0) n/=2;
            else if(n%3==0) n/=3;
            else if(n%5==0) n/=5;
            else break;
        }
        return n==1;
    }
    int nthUglyNumber(int n) {
        int num=2;
        while(n>1){
            if(isUgly(num)){
                n--;
            }
            num++;
        }
        return num-1;
    }
/*
soln2: use min heap to get the next ugly number tree structure
    1 -> 2,3,5
    2 -> 4,6,10
    3 -> 6,9,15
    5 -> 10,15,25 

    so here 2 problems -> 1. repeatitiions of numbers, 2. not in order
    soln: 1. set 2. min heap
*/ 
// TC solution using min heap and set -> TC: O(nlogn) SC: O(n)
    int nthUglyNumber(int n) {
        unordered_set<long>st;
        priority_queue<long,vector<long>,greater<long>>minHp;
        vector<int>primes={2,3,5};
        st.insert(1); minHp.push(1);
        int count=0;
        long currUgly=1l;
        while(count<n){
            currUgly = minHp.top(); minHp.pop();
            count++;
            if(count==n) break;
            for(int prime:primes){
                long newUgly = currUgly*prime;
                if(st.find(newUgly)==st.end()){ // not present
                   st.insert(newUgly); minHp.push(newUgly);
               
                }
            }
        }
        return (int)(currUgly);
    }

// Using pointers to get the next ugly number - TC: O(n) SC: O(n)
int nthUglyNumber(int n) {
    int p2=0, p3=0, p5=0;
    int n2=2,n3=3,n5=5;
    vector<long>result(n);
    result[0]=1;
    for(int i=1;i<n;i++){
        result[i]=min(n2,min(n3,n5));
        // find who gave us the minimum
        if(result[i]==n2) {
            p2++;
            n2 = result[p2]*2;
        }
        if(result[i]==n3) {
            p3++;
            n3 = result[p3]*3;
        }
        if(result[i]==n5) {
            p5++;
            n5 = result[p5]*5;
        }
    }
    return result[n-1];
}
