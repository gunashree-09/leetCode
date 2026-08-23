class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> twe;
    unordered_map<int,unordered_set<int>> fol;
    int time;
    Twitter() {
         time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        twe[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it : twe[userId]){
            pq.push(it);
            if(pq.size()>10){
                pq.pop();
            }
        }
        for(auto flo:fol[userId]){
          for(auto it:twe[flo]){
            pq.push(it);
            if(pq.size()>10){
                pq.pop();
            }
          }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
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