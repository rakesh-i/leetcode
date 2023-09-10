/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int dp[10001] = {0};
    int helper(int n, vector<int>&nums, int idx){
        // if(nums[idx]==0){
        //     return 0;
        // }
        if(idx==n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = 10001;
        for(int i=idx;i<n&&i<idx+nums[idx]; i++){
            //cout<<i<<" "<<nums[idx]<<endl;
            // if(nums[idx]==0){
            //     continue;
            // }
            ans = min(1+helper(n, nums, i+1), ans);
            //cout<<ans<<" "<<idx<<endl;
        }
        return dp[idx] = ans; 
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums.size()-1, nums, 0);
        
    }
};
// @lc code=end

