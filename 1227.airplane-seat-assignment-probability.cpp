/*
 * @lc app=leetcode id=1227 lang=cpp
 *
 * [1227] Airplane Seat Assignment Probability
 */

// @lc code=start
class Solution
{
public:
    double helper(int n, vector<double> &dp)
    {
        if (n <= 0)
        {
            return 1.0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = 1.0 / (double)n + double(n - 2) / (double)n * helper(n - 1, dp);
    }
    double nthPersonGetsNthSeat(int n)
    {
        vector<double> dp(n + 2, -1.0);
        dp[1] = 1.0;
        dp[2] = .5;

        return helper(n, dp);
        // return n==1?1.0:.5;
    }
};
// @lc code=end
