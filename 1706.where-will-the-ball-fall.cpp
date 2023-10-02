/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i=0; i<n; i++){
            dp[0][i] = i;
        }
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j-1]==1&&grid[i][j]==1){
                    if(dp[i][j-1]>=0){
                        dp[i+1][j] =dp[i][j-1];
                    }
                }
                if(grid[i][j-1]==-1&&grid[i][j]==-1){
                    if(dp[i][j]>=0){
                        dp[i+1][j-1] =dp[i][j];
                    }
                }
            }
        }
        vector<int> res(n,-1);
        for(int i=0; i<n; i++){
            if(dp[m][i]>=0){
                res[dp[m][i]]=i;
            }
        }
        return res;
    }
};
// @lc code=end

