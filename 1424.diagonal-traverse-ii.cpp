/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int n = nums.size();
        map<int, vector<int>> m;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                m[i + j].push_back(nums[i][j]);
            }
        }
        for (auto i : m)
        {
            for (int j = i.second.size() - 1; j >= 0; j--)
            {
                // cout<<i.second[j]<<" ";
                res.push_back(i.second[j]);
            }
            // cout<<endl;
        }
        return res;
    }
};
// @lc code=end
