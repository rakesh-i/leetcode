/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int dp[50];
    int helper(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = helper(n-1)+helper(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};
// @lc code=end

