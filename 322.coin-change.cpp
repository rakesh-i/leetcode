/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int dp[13][10001];
    int helper(vector<int>&coins, int a, int cur){
        if(cur>=coins.size()||a<=0){
            return a==0?0:INT_MAX-1;
        }
        if(dp[cur][a]!=-1){
            return dp[cur][a];
        }
        int res = -1;
        if(coins[cur]>a){
            return dp[cur][a] = helper(coins, a, cur+1);
        }
        else{
           return dp[cur][a] = res = min(1+helper(coins, a-coins[cur], cur),helper(coins, a, cur+1));
        }

    }
    int coinChange(vector<int>& coins, int amount) {
       memset(dp, -1, sizeof(dp)); 
       int res = helper(coins, amount, 0);
       return res==INT_MAX-1?-1:res;
    }
};
// @lc code=end

