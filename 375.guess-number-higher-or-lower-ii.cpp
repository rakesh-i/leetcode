/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
public:
    int dp[201][201];
    int helper(int l, int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans = INT_MAX;
        for(int i=l; i<=r; i++){
            ans = min(ans, i+max(helper(l, i-1), helper(i+1, r)));
        }
        return dp[l][r] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(1, n);
    }
};
// @lc code=end

