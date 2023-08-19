/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for(int i=0; i<trips.size(); i++){
            m[trips[i][1]]+=trips[i][0];
            m[trips[i][2]]-=trips[i][0];
        }
        int cur=0;
        for(auto i:m){
            cur+=i.second;
            if(cur>capacity){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

