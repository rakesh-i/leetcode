/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = nums.size();
        int m = l.size();
        vector<bool> res;
        for (int i = 0; i < m; i++)
        {
            int s = l[i];
            int e = r[i];
            int d = e - s + 1;
            vector<int> a;
            for (int k = s; k <= e; k++)
            {
                a.push_back(nums[k]);
            }
            sort(a.begin(), a.begin() + d);
            int flag = 1;
            int diff = a[1] - a[0];
            for (int j = 1; j < d; j++)
            {
                if (a[j] - a[j - 1] != diff)
                {
                    flag = 0;
                    res.push_back(false);
                    break;
                }
            }
            if (flag)
            {
                res.push_back(true);
            }
        }
        return res;
    }
};
// @lc code=end
