#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer n and a helper function bool knows(a, b) that tells you whether a knows b. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

Note that the n x n 2D array graph given as input is not directly available to you, and instead only accessible through the helper function knows. graph[i][j] == 1 represents person i knows person j, wherease graph[i][j] == 0 represents person j does not know person i.

 

Example 1:


Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.

*/

int findCelebrity(int n) {
    // indeg=+1, outdeg=-1
    vector<int>indeg(n,0);
    vector<int>outdeg(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && knows(i,j)){ // i knows j i->j
                indeg[j]++;
                indeg[i]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(indeg[i]==n-1 && outdeg[i]==0){
            return i;
        }
    }
    return -1;
}

// optimal approach   assume cand and then verify   
int findCelebrity(int n) {
    // indeg=+1, outdeg=-1
    int cand=0;
    for(int i=1;i<n;i++){
        if(knows(cand,i) || !knows(i,cand)){
            cand=i;
        }
    }
    // verify candidate
    for(int i=0;i<n;i++){
        if(cand!=i && (knows(cand,i) || !knows(i,cand))){
            return -1; // this is not candidate
        }
    }
    return cand;
}