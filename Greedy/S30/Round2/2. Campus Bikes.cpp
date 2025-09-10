#include<bits/stdc++.h>
using namespace std;
/*
On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. All the given positions are unique.

Assign a bike to each worker. Among the available bikes and workers, we choose the (workeri, bikej) pair with the shortest Manhattan distance between each other and assign the bike to that worker.

If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index. If there are multiple ways to do that, we choose the pair with the smallest bike index. Repeat this process until there are no available workers.

Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith worker is assigned to.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

*/


/*
for each bike assign worker with minimum distance

*/
vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n=workers.size();
        int m=bikes.size();
        unordered_map<int,vector<pair<int,int>>>mp; // distance->(bike,worker)
        
        int mini=0,maxi=0;
        // TC O(m*n)
        for(int i=0;i<m;i++){ // bikes
            for(int j=0;j<n;j++){ // worker
                int dist = abs(bikes[i][0]-workers[j][0])+abs(bikes[i][1]-workers[j][1]);
                mp[dist].push_back({i,j});
                mini=min(mini,dist);
                maxi=max(maxi,dist);
            }
        }
        vector<int> result(n);
        int count=0;
        vector<int>bikesAssigned(m,false);
        vector<int>workersOccupied(n,false);
        for(int dist=mini;dist<=maxi;dist++){ // O(2000) 
            if(mp.find(dist)==mp.end()) continue;
            for(auto bikeWorkerPair:  mp[dist]){ // can have same distances
                int bike=bikeWorkerPair.first, worker=bikeWorkerPair.second;
                if(!bikesAssigned[bike] && !workersOccupied[worker]){
                    bikesAssigned[bike]=true;
                    workersOccupied[worker]=true;
                    result[worker]=bike;
                    count++;
                    if(count==n) return result;
                } 
            }
        }
        return result;

        
    }