/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int ll = 0, lr = 0, gr = 0, gl = 0;
            for (int j = 0; j < n; j++)
            {
                if (rating[i] > rating[j])
                {
                    if (i > j)
                    {
                        ll++;
                    }
                    else
                    {
                        lr++;
                    }
                }
                if (rating[i] < rating[j])
                {
                    if (i > j)
                    {
                        gl++;
                    }
                    else
                    {
                        gr++;
                    }
                }
            }
            res += gl * lr + gr * ll;
        }
        return res;
    }
};
// @lc code=end
