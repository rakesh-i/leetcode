/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = 0;
        for(int i=1; i<nums.size(); i++){
            m = max(m, nums[i]-nums[i-1]);
        }
        return m;
    }
};
// @lc code=end

