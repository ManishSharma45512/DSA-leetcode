class Twitter {
private:
    
    int timeStamp; // Global counter to track the absolute order of when tweets are made
    
    
    unordered_map<int, vector<pair<int, int>>> usertweets;// Maps userId to a vector of pairs: {time_created, tweet_id}
    
    
    unordered_map<int, vector<int>> userfollowed;// Maps userId to a vector of followeeIds

public:
    Twitter() {
        timeStamp = 0; // Initialize time at 0
    }
    
    void postTweet(int userId, int tweetId) {
        // Record the tweet along with the current timestamp, then tick time forward
        usertweets[userId].push_back({timeStamp, tweetId});
        timeStamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // This pool will gather all eligible tweets (own tweets + followee tweets)
        vector<pair<int, int>> feedPool;

        // Grab all of the user's own tweets
        for (auto& tweet : usertweets[userId]) {
            feedPool.push_back(tweet);
        }

        // Look up who this user follows and grab their tweets too
        vector<int> followedPeople = userfollowed[userId];
        for (int i = 0; i < followedPeople.size(); i++) {
            int followeeId = followedPeople[i];
            
            // A user can accidentally follow themselves in some test cases. 
            // Avoid adding your own tweets twice!
            if (followeeId == userId) continue; 

            for (auto& tweet : usertweets[followeeId]) {
                feedPool.push_back(tweet);
            }
        }

        //Sort the entire pool so the highest timeStamp (most recent) comes first
        // This lambda tells C++ to sort in descending order based on the .first (timeStamp) element
        sort(feedPool.begin(), feedPool.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // Use clean extraction loop to pull out the top 10 tweet IDs
        vector<int> result;
        int count = 0;
        for (int i = 0; i < feedPool.size(); i++) {
            if (count < 10) {
                result.push_back(feedPool[i].second); // Extract just the tweetId
                count++;
            } else {
                break;
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        
        vector<int>& currfollowed = userfollowed[followerId];
        for (int i = 0; i < currfollowed.size(); i++) {
            if (currfollowed[i] == followeeId) return;
        }
        
        userfollowed[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int> nowfollows;
        vector<int> currfollowed = userfollowed[followerId];

        for (int i = 0; i < currfollowed.size(); i++) {
            if (currfollowed[i] == followeeId) continue;
            nowfollows.push_back(currfollowed[i]);
        }

        userfollowed[followerId] = nowfollows;
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
