/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int dp[101];
    int helper(vector<int>&nums, int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = 0;
        int temp = INT_MIN;
        for(int i=2; i<=nums.size(); i++){
            ans=nums[idx]+helper(nums, idx+i);
            temp = max(ans, temp);
        }
        return dp[idx] = temp;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int mx = nums[0];
        for(int i=0; i<nums.size(); i++){
            mx = max(mx, helper(nums, i));
        }
        return mx;
    }
};
// @lc code=end

