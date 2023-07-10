/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void helper(string cur, int n, int open, int close, vector<string> &res){
        if(cur.length()==n*2){
            res.push_back(cur);
            return;
        }
        if(open<n) helper(cur+"(", n, open+1, close, res);
        if(close<open) helper(cur+")", n, open, close+1,res); 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", n, 0, 0,res);
        return res;
    }
};
// @lc code=end

