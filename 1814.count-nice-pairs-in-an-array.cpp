/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int reverseDigits(int num)
    {
        int rev_num = 0;
        while (num > 0)
        {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, long> mp;
        for (int i = 0; i < n; i++)
        {
            int x = reverseDigits(nums[i]);
            mp[nums[i] - x]++;
        }
        long long res = 0;
        for (auto i : mp)
        {
            res = (res + i.second * (i.second - 1) / 2) % 1000000007;
        }
        return res;
    }
};
// @lc code=end
