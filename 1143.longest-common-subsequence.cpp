/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int helper(string &t1, string &t2, int m, int n){
        if(m==0||n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(t1[m-1]==t2[n-1]){
            return dp[m][n] = 1+helper(t1, t2, m-1, n-1);
        }
        else{
            return dp[m][n]=max(helper(t1, t2, m-1, n), helper(t1, t2, m, n-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return helper(text1, text2, text1.size(), text2.size());
    }
};
// @lc code=end

