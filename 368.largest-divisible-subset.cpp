/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> ans;
    int dp[1001];
    void helper(vector<int>&nums, int i, int prev, vector<int>temp){
        if(i>=nums.size()){
            if(temp.size()>ans.size()){
                ans = temp;
            }
            return;
        }
        if((int)temp.size()>dp[i]&&nums[i]%prev==0){
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            helper(nums, i+1, nums[i], temp);
            temp.pop_back();
        }
        helper(nums, i+1, prev, temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        vector<int> temp;
        helper(nums, 0, 1, temp);
        return ans;
    }
};
// @lc code=end

