/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    int dp[201][20001];
    bool helper(vector<int>&nums, int sum, int i){
        if(i<=0){
            return 0;
        }
        if(sum<=0){
            return sum==0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(nums[i-1]>sum){
            return dp[i][sum] = helper(nums, sum, i-1);
        }
        else{
            return dp[i][sum] = helper(nums, sum-nums[i-1], i-1)||helper(nums, sum, i-1);
        }
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n= nums.size();
        int total = 0;
        for(int i=0;i<n; i++){
            total+=nums[i];
        }
        if(total%2){
            return false;
        }
        return helper(nums, total/2, n);
    }
};
// @lc code=end

