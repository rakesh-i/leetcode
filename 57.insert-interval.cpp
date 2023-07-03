/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& t1, vector<int>& t2) {
        t1.push_back(t2);
        int n = t1.size();
        vector<vector<int>> a;
        for(int i=0; i<n; i++){
            if(t1[i][0]!=-1){
                int x = t1[i][0];
                int y = t1[i][1];
                for(int j=i; j<n; j++){
                    if(t1[j][0]>=x&&t1[j][0]<=y){
                        y = max(y, t1[j][1]);
                        t1[j][0] = -1;
                    }
                }
                a.push_back({x,y});
            }
        }
        return a;
    }
};
// @lc code=end

