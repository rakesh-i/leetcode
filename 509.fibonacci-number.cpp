/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
       vector<int> dp(n+2, 0);
       dp[1] = 1;
       for(int i=1; i<n; i++){
            dp[i+1] += dp[i];
            dp[i+2] += dp[i];
       }
       //cout<<dp[n]<<endl;
       return dp[n];

    }
};
// @lc code=end

