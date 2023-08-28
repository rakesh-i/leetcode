/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int> &nums, int n, int t,vector<int> &dp){
        if(t==0){
            return 1;
        }
        if(t<0){
            return 0;
        }
        if(dp[t]!=-1){
            return dp[t];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += helper(nums, n, t-nums[i],dp);
        }
        return dp[t]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        int x = helper(nums, nums.size(), target, dp);
        return x;
    }
};
// @lc code=end

