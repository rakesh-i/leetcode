/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string a = "";
        string b = "";

        for (int i = 0; i < word1.size(); i++)
        {
            a += word1[i];
        }
        for (int i = 0; i < word2.size(); i++)
        {
            b += word2[i];
        }
        if (a == b)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
