class Twitter {
    int time;
    
    struct Tweet {
        int tweetId;
        int timeStamp;
        Tweet(int tweetId, int timeStamp) : tweetId(tweetId), timeStamp(timeStamp) {}
    };
    
    struct CompareTimeStamp { 
        bool operator()(Tweet& t1, Tweet& t2) {
            return t1.timeStamp < t2.timeStamp; 
        } 
    };
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet>> tweets;
    
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    // Time: O(1)
    void postTweet(int userId, int tweetId) {
        followers[userId].insert(userId);
        tweets[userId].push_back(Tweet(tweetId, ++time));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    // Time: O(NlogN), N = Number of folllowees x Tweets for each followee
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, CompareTimeStamp> pq;
        for(auto &id: followers[userId]) {
            for(Tweet &tweet: tweets[id])
                pq.push(tweet);
        }
        
        vector<int> newsFeed;
        while(pq.size() != 0) {
            newsFeed.push_back(pq.top().tweetId);
            pq.pop();
            if(newsFeed.size() == 10)
                break;
        }
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    // Time: O(1)
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    // Time: O(1)
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId && followers.find(followerId) != followers.end())
            followers[followerId].erase(followeeId);
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
