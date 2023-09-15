/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>&t, int i, int j, int m, int n){
        if(i==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = t[i][j]+min(helper(t, i+1, j, m, n), helper(t, i+1, j+1, m, n));
        return  dp[i][j]= ans;

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return helper(triangle, 0, 0, triangle.size(), 0);
    }
};
// @lc code=end

