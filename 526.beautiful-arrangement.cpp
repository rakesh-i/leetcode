/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(i + 1);
        }
        return count(n, v);
    }

    int count(int n, vector<int> &v)
    {
        if (n <= 0)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % n == 0 || n % v[i] == 0)
            {
                swap(v[i], v[n - 1]);
                ans += count(n - 1, v);
                swap(v[i], v[n - 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
