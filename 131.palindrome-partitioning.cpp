/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    int dp[1001][1001] = {0};
    vector<vector<string>> res;
    void helper(string &s, int idx, vector<string> cur){
        if(idx==s.size()){
            res.push_back(cur);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(dp[idx][i]==1){
                cur.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        for(int j=0; j<n; j++){
            for(int i=0; i<=j; i++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1]==1)){
                    dp[i][j] = 1;
                }
            }
        }
        vector<string> cur;
        helper(s, 0, cur);
        return res;
    }
};
// @lc code=end

