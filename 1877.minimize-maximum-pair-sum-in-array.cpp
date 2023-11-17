/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;
        for (int i = 0; i < n / 2; i++)
        {
            mx = max(nums[i] + nums[n - i - 1], mx);
        }
        return mx;
    }
};
// @lc code=end
