/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution
{
public:
    int countHomogenous(string s)
    {
        int n = s.size();
        long res = 0;
        int i = 0;
        while (i < n)
        {
            int cur = 0;
            char x = s[i];
            while (i < n && x == s[i])
            {
                cur++;
                i++;
            }
            res += (long)cur * ((long)cur + long(1)) / (long)2;
        }
        if (res > (1000000007))
        {
            return res % 1000000007;
        }
        return res;
    }
};
// @lc code=end
