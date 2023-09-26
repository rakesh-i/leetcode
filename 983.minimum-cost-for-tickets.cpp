/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int dp[366][366];
    int helper(vector<int> &days, vector<int>&costs, int i, int val){
        if(i>=days.size()||val>=366){
            return 0;
        }
        if(dp[i][val]!=-1){
            return dp[i][val];
        }
        if(days[i]<=val){
            return dp[i][val] = helper(days, costs, i+1, val);
        }
        else{
            int ch1 = costs[0]+helper(days, costs, i+1, days[i]);
            int ch2 = costs[1]+helper(days, costs, i+1, days[i]+6);
            int ch3 = costs[2]+helper(days, costs, i+1, days[i]+29);
            return dp[i][val]=min(ch1, min(ch2, ch3));
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return helper(days, costs, 0, 0);
    }
};
// @lc code=end

