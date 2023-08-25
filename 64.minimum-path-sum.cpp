/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int helper(vector<vector<int>> &g, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m&&j==n){
            return g[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=INT_MAX;
        int d=INT_MAX;
        if(i<m){
            d = helper(g, i+1, j, m, n, dp);
        }
        if(j<n){
            r = helper(g, i, j+1, m, n, dp);
        }
        return dp[i][j] = g[i][j]+min(r,d);
    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> dp(201, vector<int>(201,-1));
        return helper(grid, 0, 0, grid.size()-1, grid[0].size()-1, dp);
    }
};
// @lc code=end

