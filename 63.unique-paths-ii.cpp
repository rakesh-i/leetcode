/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        if(o[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i+1<m){
                    if(o[i+1][j]==1){
                        dp[i+1][j]=0;
                    }
                    else{
                        dp[i+1][j] += dp[i][j];
                    }
                }
                if(j+1<n){
                    if(o[i][j+1]==1){
                        dp[i][j+1]=0;
                    }
                    else{
                        dp[i][j+1] += dp[i][j];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

