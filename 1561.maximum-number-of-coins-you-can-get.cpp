/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int c = n / 3;
        int res = 0;
        int r = n - 2;
        for (int i = 0; i < c; i++)
        {
            res += piles[r];
            r = r - 2;
        }
        return res;
    }
};
// @lc code=end
