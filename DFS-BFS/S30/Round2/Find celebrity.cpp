#include<bits/stdc++.h>
using namespace std;
/*
277. Find the Celebrity
Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given an integer n and a helper function bool knows(a, b) that tells you whether a knows b. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

Note that the n x n 2D array graph given as input is not directly available to you, and instead only accessible through the helper function knows. graph[i][j] == 1 represents person i knows person j, wherease graph[i][j] == 0 represents person j does not know person i.



*/
// approach: topological sort approach// Time Complexity: O(n^2) Space Complexity: O(n)
int findCelebrity(int n) {
    // no ned of adj list
        vector<vector<int>>adj(n);
        // indeg=+1, outdeg=-1
        vector<int>indeg(n,0);
        vector<int>outdeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && knows(i,j)){ // i knows j i->j
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j: adj[i]){
                indeg[j]++;
                outdeg[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0){
                return i;
            }
        }
        return -1;
    }
// approach - no need of adj list - TC-O(n^2), SC-O(n) -> very slow
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

// anything else than topological sort approach - linear
// approach: find candidate and verify it - TC-O(2n), SC-O(1)
int findCelebrity(int n) {
    int cand=0;
    for(int i=1;i<n;i++){
        if(knows(cand,i)){ // or !knows(i,cand) -> cand knows i
            cand=i;
        }
    }
    // verify candidate
    for(int i=0;i<n;i++){
        if(cand!=i) continue;
        if(knows(cand,i) || !knows(i,cand)){ // cand knows i or i does not know cand
            // cand is not celebrity
            return -1; // this is not candidate
        }
    }
    return cand;
}

