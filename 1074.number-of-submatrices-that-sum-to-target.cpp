/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    for (int l = 1; l <= m; l++)
                    {
                        if (i <= j && k <= l)
                        {
                            int sum = prefix[j][l] - prefix[i - 1][l] - prefix[j][k - 1] + prefix[i - 1][k - 1];
                            if (sum == target)
                            {
                                res++;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
