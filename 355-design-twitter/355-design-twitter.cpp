class Twitter {
private:    
   unordered_map<int, set<int>> followMap;
   unordered_map<int, vector<pair<int, int>>> tweetMap;
   long long time; 

public:
/** Initialize your data structure here. */
Twitter() {
    time = 0;
}

/** Compose a new tweet. */
void postTweet(int userId, int tweetId) {
    tweetMap[userId].push_back({time++, tweetId});
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> maxHeap; 
    for (auto it = tweetMap[userId].begin(); it != tweetMap[userId].end(); ++it)
        maxHeap.push(*it);
    for (auto it1 = followMap[userId].begin(); it1 != followMap[userId].end(); ++it1){
        int usr = *it1;
        for (auto it2 = tweetMap[usr].begin(); it2 != tweetMap[usr].end(); ++it2)
            maxHeap.push(*it2);
    }   
    vector<int> recentTweets;
    while(maxHeap.size()>0) {
        recentTweets.push_back(maxHeap.top().second);
        if (recentTweets.size()==10) break;
        maxHeap.pop();
    }
    return recentTweets;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        followMap[followerId].insert(followeeId);
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void unfollow(int followerId, int followeeId) {
    followMap[followerId].erase(followeeId);
}
    

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */