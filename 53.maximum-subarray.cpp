/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int mx = nums[0];
        for(int i=1; i<nums.size(); i++){
            cur = max(cur+nums[i], nums[i]);
            mx = max(cur, mx);
        }
        return mx;
    }
};
// @lc code=end

