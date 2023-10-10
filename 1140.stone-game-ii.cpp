/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& piles, int p, int i, int m, vector<vector<vector<int>>> &dp){
        if(i==piles.size()){
            return 0;
        }
        if(dp[p][i][m]!=-1){
            return dp[p][i][m];
        }
        int res = p==1?1000000:0;
        int sum = 0;
        for(int x=1; x<=min(2*m, int(piles.size()-i)); x++){
            sum+= piles[i+x-1];
            if(p==0){
                res = max(res, sum+helper(piles, 1, x+i, max(x, m), dp));
            }
            else{
                res = min(res, helper(piles, 0, x+i, max(x,m), dp));
            }
        }
        return dp[p][i][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return helper(piles, 0, 0, 1, dp);
    }
};
// @lc code=end

