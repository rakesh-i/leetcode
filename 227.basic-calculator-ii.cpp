/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> stack;
        int res = 0;
        long long temp = 0;
        char sign = '+';
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                temp = temp * 10 + s[i] - '0';
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i == n - 1)
            {
                if (sign == '-')
                {
                    stack.push(-temp);
                }
                else if (sign == '+')
                {
                    stack.push(temp);
                }
                else
                {
                    int num;
                    if (sign == '*')
                    {
                        num = stack.top() * temp;
                    }
                    else
                    {
                        num = stack.top() / temp;
                    }
                    stack.pop();
                    stack.push(num);
                }
                temp = 0;
                sign = s[i];
            }
        }
        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};
// @lc code=end
