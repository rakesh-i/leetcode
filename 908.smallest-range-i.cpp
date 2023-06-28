/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(0,(nums[n-1]-k)-(nums[0]+k));
    }
};
// @lc code=end

