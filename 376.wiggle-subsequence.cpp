/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int dp[1001][2];
    int helper(vector<int>&nums, int i, int flag){
        if(i==nums.size()-1){
            return 1;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        int ans = 0;
        if(flag==1){
            if(nums[i+1]<nums[i]){
                ans = max(ans, 1+helper(nums, i+1, 0));
            }
            else{
                ans = max(ans, helper(nums, i+1, 1));
            }
        }
        else{
            if(nums[i+1]>nums[i]){
                ans = max(ans, 1+helper(nums, i+1, 1));
            }
            else{
                ans = max(ans, helper(nums, i+1, 0));
            }
        }
        return dp[i][flag] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        ans = max(ans, helper(nums, 0, 1));
        memset(dp, -1, sizeof(dp));
        ans = max(ans, helper(nums, 0, 0));
        return ans;
    }
};
// @lc code=end

