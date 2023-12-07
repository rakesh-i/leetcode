/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        int a = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = num[i] - '0';
            if (x % 2 != 0)
            {
                a = i;
                break;
            }
        }
        if (a != -1)
        {
            return num.substr(0, a + 1);
        }
        return "";
    }
};
// @lc code=end
