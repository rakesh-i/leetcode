/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void helper(vector<string> &res, string cur, int open, int close, int n){
        if(cur.size()==n*2){
            res.push_back(cur);
            return;
        }
        if(open<n){
            helper(res, cur+"(", open+1, close, n);
        }
        if(close<open){
            helper(res, cur+")", open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        helper(res,cur, 0, 0, n);
        return res;
    }
};
// @lc code=end

