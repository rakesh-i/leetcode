/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution
{
public:
    int totalMoney(int n)
    {
        int c = 0;
        int res = 0;
        int x = n / 7;
        int y = n - x * 7;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                res += (j + 1 + c);
            }
            c++;
        }
        for (int i = 0; i < y; i++)
        {
            res += (i + 1 + c);
        }
        return res;
    }
};
// @lc code=end
