/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter
{
    int time = 0;
    struct Tweet
    {
        Tweet *next;
        int id;
        int time;
    };
    map<int, Tweet *> u;
    map<int, set<int>> f;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        if (u.find(userId) == u.end())
        {
            Tweet *tw = new Tweet();
            tw->id = tweetId;
            tw->next = NULL;
            tw->time = time++;
            u[userId] = tw;
        }
        else
        {
            Tweet *tw = new Tweet();
            tw->id = tweetId;
            tw->next = u[userId];
            tw->time = time++;
            u[userId] = tw;
        }
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<vector<int>> res;
        Tweet *temp = u[userId];
        vector<int> ans;
        while (temp)
        {
            res.push_back({temp->time, temp->id});
            temp = temp->next;
        }

        for (auto i : f[userId])
        {
            int c = 0;
            Tweet *t = u[i];
            while (t && c < 10)
            {
                res.push_back({t->time, t->id});
                t = t->next;
                c++;
            }
        }

        sort(res.begin(), res.end());
        int c = 0;
        for (int i = res.size() - 1; i >= 0 && c < 10; i--)
        {
            ans.push_back(res[i][1]);
            c++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        f[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (f[followerId].find(followeeId) != f[followerId].end())
        {
            f[followerId].erase(followeeId);
        }
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
// @lc code=end
