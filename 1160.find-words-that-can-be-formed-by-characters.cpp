/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> m;
        int res = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            m[chars[i]]++;
        }
        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> p;
            for (int j = 0; j < words[i].size(); j++)
            {
                p[words[i][j]]++;
            }
            int x = 0;
            for (auto k : p)
            {
                if (k.second <= m[k.first])
                {
                }
                else
                {
                    x = 1;
                    break;
                }
            }
            if (x == 0)
            {
                res += words[i].size();
            }
        }
        return res;
    }
};
// @lc code=end
