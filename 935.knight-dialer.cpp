/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution
{
public:
    int knightDialer(int n)
    {
        long long x1, x2, x3, x4, x5, x6, x7, x8, x9, x0;
        x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = x9 = x0 = 1;
        long long y1, y2, y3, y4, y5, y6, y7, y8, y9, y0;
        y1 = y2 = y3 = y4 = y5 = y6 = y7 = y8 = y9 = y0 = 1;
        for (int i = 0; i < n - 1; i++)
        {
            y1 = (x6 + x8) % (1000000007);
            y2 = (x7 + x9) % (1000000007);
            y3 = (x4 + x8) % (1000000007);
            y4 = (x0 + x9 + x3) % (1000000007);
            y5 = 0;
            y6 = (x0 + x7 + x1) % (1000000007);
            y7 = (x2 + x6) % (1000000007);
            y8 = (x1 + x3) % (1000000007);
            y9 = (x2 + x4) % (1000000007);
            y0 = (x4 + x6) % (1000000007);
            x1 = y1;
            x2 = y2;
            x3 = y3;
            x4 = y4;
            x5 = y5;
            x6 = y6;
            x7 = y7;
            x8 = y8;
            x9 = y9;
            x0 = y0;
        }
        return (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x0) % (1000000007);
    }
};
// @lc code=end
