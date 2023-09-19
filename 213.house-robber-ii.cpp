/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int dp[101];
    int helper(vector<int>&nums, int idx, int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = 0;
        int temp = INT_MIN;
        for(int i=2; i<n; i++){
            ans=nums[idx]+helper(nums, idx+i, n);
            temp = max(ans, temp);
        }
        return dp[idx] = temp;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        if(nums.size()==1){
            return nums[0];
        }
        int mx = nums[0];
        int nx = nums[1];
        for(int i=0; i<nums.size()-1; i++){
            mx = max(mx, helper(nums, i, nums.size()-1));
        }
        memset(dp, -1, sizeof(dp));
        for(int i=1; i<nums.size(); i++){
            nx = max(nx, helper(nums, i, nums.size()));
        }
        return max(nx, mx);
    }
};
// @lc code=end

