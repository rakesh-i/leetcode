/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int dp[59];
    int helper(int n, int pro, int count){
        if(n==0){
            if(count<2){
                return 1;
            }
            // mx = max(mx, pro);
            return pro;
        }
        if(dp[n]!=-1){
            return pro*dp[n];
        }
        int ans = 1;
        for(int i=1; i<=n; i++){
            count++; 
            ans = max(helper(n-i, pro*i, count), ans);
            count--;
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 1,0);
        
    }
};
// @lc code=end

