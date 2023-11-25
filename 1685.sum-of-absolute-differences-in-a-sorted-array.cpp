/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        vector<int> sum;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            sum.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            int l = sum[i] - nums[i];
            int r = sum[n - 1] - sum[i];
            int ls = abs(l - (nums[i] * i));
            int rs = abs(r - (nums[i] * (n - i - 1)));
            res.push_back(ls + rs);
        }
        return res;
    }
};
// @lc code=end
