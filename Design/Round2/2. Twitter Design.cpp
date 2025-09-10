#include <bits/stdc++.h>
using namespace std;
/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.


in following map
f1->f2 => follower f1 follows f2(followee) => f1 want to see f2 posts in his feed
*/

// approach 1: 
class Twitter {
public:
    struct Tweet{
        int tweetId;
        int createdAt;
        Tweet(int id,int timestamp){
            tweetId=id;
            createdAt=timestamp;
        }
    }; 

    struct comp{
        bool operator()(const Tweet &a, const Tweet &b){
            return a.createdAt > b.createdAt; // minheap - smalle integer have more prioity
        }
    };

    int timeStamp;
    unordered_map<int,unordered_set<int>>followMp;
    unordered_map<int,vector<Tweet>>tweetsList;

    Twitter() {
       timeStamp = 1;
    }
    
    void postTweet(int userId, int tweetId) {// o(1)
        follow(userId,userId); 
        Tweet twt(tweetId,timeStamp);
        timeStamp++;
        tweetsList[userId].push_back(twt);
    }
    
    vector<int> getNewsFeed(int userId) { // get 10 recent posts only o(N)
        vector<int> result;
        priority_queue<Tweet, vector<Tweet>,comp>pq;
        auto followingList = followMp[userId];
        if(followingList.empty()) return result;
        for(int followee: followingList){ // go to all followee tweets
            if(!followee) continue;
            for(Tweet t: tweetsList[followee]){
                pq.push(t);
                if(pq.size()>10) pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().tweetId);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) { // o(1)
        followMp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) { // o(1)
        // i dont want to unfollow myself because i want to get my tweets in my feed
        if(followerId==followeeId) return ; 
        // check if the followerId exists
        if(followMp.count(followerId)>0){
            auto followingList = followMp[followerId];
            // check if the followee is present to unfollow
            auto itr = find(followingList.begin(),followingList.end(),followeeId);
            if(itr!=followingList.end()){ //present
               followMp[followerId].erase(followeeId);
            }
        }
    }
};

// optimise getnewsfeed function, anyway recent tweets are added at end so, take only last 10 tweets from each followee
// use priority queue to get 10 most recent tweets from all followees
// time complexity: O(NlogN) where N is the number of tweets in the feed

vector<int> getNewsFeed(int userId) { // get 10 recent posts only o(N)
        vector<int> result;
        priority_queue<Tweet, vector<Tweet>,comp>pq;
        auto followingList = followMp[userId];
        if(followingList.empty()) return result;
        for(int followee: followingList){ // go to all followee tweets
            if(!followee) continue;
            auto tweets=tweetsList[followee];
            int len=tweets.size();
            // like k-merge from merging k sorted arrays
            // take last 10 tweets from the followee as they are the most recent
            for(int k=len-1;k>=0 && k>=len-10;k--){
                pq.push(tweets[k]);
                if(pq.size()>10) pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().tweetId);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    