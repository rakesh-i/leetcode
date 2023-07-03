/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& t) {
        int n = t.size();
        sort(t.begin(), t.end());
        vector<vector<int>>a;
        for(int i=0; i<n; i++){
            if(t[i][0]!=-1){
                int x = t[i][0];
                int y = t[i][1];
                for(int j=i; j<n; j++){
                    if(t[j][0]>=x &&t[j][0]<=y){
                        y = max(y, t[j][1]);
                        t[j][0] = -1;
                    }
                }
            a.push_back({x, y});
            }
            
        }
        return a;
    }
};
// @lc code=end

