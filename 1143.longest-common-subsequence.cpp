/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int LCS(int n, int m, string &s1, string &s2, vector<vector<int>> &memo) {
        if(n == 0 || m == 0) return 0;
        if(memo[n][m]!=-1) return memo[n][m];
        if(s1[n-1] == s2[m-1])
            return memo[n][m] = 1 + LCS(n-1, m-1, s1, s2,memo);
        else
            return memo[n][m] = max(LCS(n, m-1, s1, s2,memo), LCS(n-1, m, s1, s2, memo));
    } 
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return LCS(n, m, text1, text2, memo);
    }
};
// @lc code=end

