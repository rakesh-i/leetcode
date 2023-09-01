/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0){
            return 0;
        }
        int mx = 0;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i=1; i<=(n-1)/2; i++){
            dp[2*i]=dp[i];
            dp[2*i+1] = dp[i]+dp[i+1];
        }
        sort(dp.begin(), dp.end());
        return dp[n];
    }
};
// @lc code=end

