/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
public:
    unordered_map<long long, int> dp;
    long long helper(long long n){
        if(n==1){
            return 0;
        }
        if(dp[n]){
            return dp[n];
        }
        int ans1 = 0;
        int ans2 = INT_MAX;
        if(n%2==0){
            return dp[n] = 1+helper(n/2);
        }
        else{
            ans1 = 1+helper(n-1);
            // if(n!=INT_MAX){
                ans2 = 1+helper(n+1);
            // }
            
            return dp[n] = min(ans1, ans2);
        }

    }
    int integerReplacement(int n) {
        // dp[INT_MAX] = 32;
        long long x = n;
        dp[1] = 1;
        return (int)helper(x);
        // return x;
    }
};
// @lc code=end

