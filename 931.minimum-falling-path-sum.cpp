/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int a = dp[i - 1][j] + matrix[i][j];
                int b = j - 1 >= 0 ? dp[i - 1][j - 1] + matrix[i][j] : INT_MAX;
                int c = j + 1 < m ? dp[i - 1][j + 1] + matrix[i][j] : INT_MAX;
                dp[i][j] = min(a, min(b, c));
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            mn = min(mn, dp[n - 1][i]);
        }
        return mn;
    }
};
// @lc code=end
