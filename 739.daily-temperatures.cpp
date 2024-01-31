/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
