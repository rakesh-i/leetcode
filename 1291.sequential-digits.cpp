/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution
{
public:
    vector<int> res;
    void helper(int low, int high, int i, int num)
    {
        if (num <= high && num >= low)
        {
            res.push_back(num);
        }
        if (i > 9 || num > high)
        {
            return;
        }
        helper(low, high, i + 1, num * 10 + i);
    }
    vector<int> sequentialDigits(int low, int high)
    {
        for (int i = 1; i < 10; i++)
        {
            helper(low, high, i, 0);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
