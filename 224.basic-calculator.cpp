/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution
{
public:
    int i = 0;
    int calculate(string s)
    {
        int res = 0;
        bool negflag = false;
        while (i < s.size() && s[i] != ')')
        {
            if (s[i] == '+' || s[i] == ' ')
            {
                i++;
            }
            else if (s[i] == '-')
            {
                i++;
                negflag = true;
            }
            else if (s[i] == '(')
            {
                i++;
                res += negflag ? -calculate(s) : calculate(s);
                negflag = false;
            }
            else
            {
                long long num = 0;
                while (s[i] >= '0')
                {

                    num = num * 10 + s[i++] - '0';
                }
                res += negflag ? -num : num;
                negflag = false;
            }
        }
        i++;
        return res;
    }
};
// @lc code=end
