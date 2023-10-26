/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution
{
public:
    int dp[1001][1001];
    int dsum(string &a, int i)
    {
        int sum = 0;
        for (; i < a.size(); i++)
        {
            sum += int(a[i]);
        }
        return sum;
    }
    int helper(string &a, string &b, int i, int j, int n, int m)
    {
        int sum = 0;
        if (i == n || j == m)
        {
            if (i == n && j == m)
            {
                return 0;
            }
            return (i == n) ? dsum(b, j) : dsum(a, i);
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (a[i] == b[j])
        {
            sum = helper(a, b, i + 1, j + 1, n, m);
        }
        else
        {
            sum = min(helper(a, b, i + 1, j, n, m) + int(a[i]), helper(a, b, i, j + 1, n, m) + int(b[j]));
        }
        return dp[i][j] = sum;
    }
    int minimumDeleteSum(string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, 0, 0, s1.size(), s2.size());
    }
};
// @lc code=end
